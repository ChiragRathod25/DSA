#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class employee
{
    int empId;
    char name[50];
    float sal;
    bool isAvailable;

public:
    employee()
    {
        isAvailable = true;
    }
    employee(int empId, const char *name, float sal)
    {
        this->empId = empId;
        strcpy(this->name, name);
        this->sal = sal;
        isAvailable = true;
    }
    void display()
    {
        cout << empId << " " << name << " " << sal << endl;
    }
    char *getName()
    {
        return name;
    }
    bool getAvailable()
    {
        return isAvailable;
    }
    void toggleAvailable()
    {
        if (isAvailable)
            isAvailable = 0;
        else
            isAvailable = 1;
    }
    void setSal(float n)
    {
        sal = n;
    }
    void set(int id, const char *name, float sal)
    {
        this->empId = id;
        strcpy(this->name, name);
        this->sal = sal;
        isAvailable = true;
    }
};

void add(fstream &f, employee &e)
{
    f.seekp(0, ios::end);
    f.write((char *)&e, sizeof(e));
}

int search(fstream &f, char const *target)
{
    f.clear();
    f.seekg(0, ios::beg);
    employee e;
    while (!f.eof())
    {
        f.read((char *)&e, sizeof(e));
        if (!f.eof())
        {
            if (strcmp(target, e.getName()) == 0 && e.getAvailable())
            {
                // cout << target;
                e.display();
                return ((int)f.tellg() - (int)sizeof(employee));
            }
        }
    }
    cout << "Could not find" << endl;
    return -1;
}

void deleteE(fstream &f, const char *name)
{
    cout << "Deleteing : ";
    int address = search(f, name);
    if (address != -1)
    {
        cout << address << endl;
        f.seekg(address, ios::beg);
        employee e;
        f.read((char *)&e, sizeof(e));

        if (e.getAvailable())
            e.toggleAvailable();

        f.seekp(address, ios::beg);
        f.write((char *)&e, sizeof(e));
    }
}

void update(fstream &f, const char *name, float sal)
{
    cout << "Updating : ";
    int address = search(f, name);
    // cout << address << endl;
    if (address != -1)
    {
        employee e;
        f.seekg(address, ios::beg);
        f.read((char *)&e, sizeof(e));

        e.setSal(sal);

        f.seekp(address, ios::beg);
        f.write((char *)&e, sizeof(e));
    }
}

void displayAll(fstream &f)
{
    f.clear();
    f.seekg(0, ios::beg);
    employee e;
    while (!f.eof())
    {
        f.read((char *)&e, sizeof(e));
        if (!f.eof() && e.getAvailable())
        {
            e.display();
        }
    }
}

int main()
{
    fstream file;
    file.open("emp", ios::in | ios::out | ios::ate);

    cout << "1. Add\n2. Update\n3. Delete\n4. Search\n5. Display\n6. Exit" << endl;

    char name[50];
    int id;
    float sal;
    employee e;
    while (1)
    {
        file.clear();
        int choice;
        cout << "Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            file.clear();
            cout << "Enter id, name, sal : ";
            cin >> id >> name >> sal;
            e.set(id, name, sal);
            add(file, e);
            break;
        case 2:
            cout << "Enter name and new salary : ";
            cin >> name >> sal;
            update(file, name, sal);
            break;
        case 3:
            cout << "Enter name : ";
            cin >> name;
            deleteE(file, name);
            break;
        case 4:
            cout << "Enter name : ";
            cin >> name;
            search(file, name);
            break;
        case 5:
            displayAll(file);
            break;
        case 6:
            file.close();
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}