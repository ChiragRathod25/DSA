#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
class employee
{
    char id[10];
    char name[100];
    char dept[100];
    float salary;

public:
    employee()
    {
    }
    void insert()
    {
        cout << "Enter Id,Name,Department,Salary : ";
        cin >> id >> name >> dept >> salary;
    }
    void display()
    {
        cout << setw(5) << id
             << setw(10) << name
             << setw(10) << dept
             << setw(10) << salary << endl;
    }
    void update(char *dept, float salary)
    {
        strcpy(this->dept, dept);
        this->salary = salary;
    }
    char *getname()
    {
        return name;
    }
};
int main()
{
    employee e;
    int select;
    char search[100];
    char filename[100];
    cout << "Enter Filename : ";
    cin >> filename;
    
    fstream file;
    while (true)
    {
        cout << "1. Insert Details " << endl
             << "2. Serach" << endl
             << "3. Update" << endl
             << "4. Delete" << endl
             << "5. Display" << endl
             << "6. Exit" << endl;
        cout << "Enter your Choise : " << endl;
        cin >> select;
        switch (select)
        {
        case 1:
            file.open(filename, ios::app);
            e.insert();
            file.write((char *)&e, sizeof(e));
            file.close();
            break;
        case 2:
            cout << "Enter Name to search : ";
            cin >> search;
            file.open(filename, ios::in);
            file.seekg(0, ios::beg);
            while (file.read((char *)&e, sizeof(e)))
            {
                if (strcmp(e.getname(), search) == 0)
                {
                    e.display();
                }
            }

            break;
        case 3:
            cout << "Enter Name to Update : ";
            cin >> search;
            file.open(filename, ios::in);
            file.seekg(0, ios::beg);
            while (file.read((char *)&e, sizeof(e)))
            {
                if (strcmp(e.getname(), search) == 0)
                {
                    cout << "Enter new Department and Salary :";
                    char dept[100];
                    float salary;
                    cin >> dept >> salary;
                    e.update(dept, salary);
                    e.display();
                    file.open(filename,ios::app);
                    file.seekg(0, ios::beg);
                    file.write((char *)&e, sizeof(e));
                    file.close();
                    break;
                }
            }
            file.close();
            break;
        case 4:
            break;
        case 5:
            file.open(filename, ios::in);
            file.seekg(0, ios::beg);
            while (file.read((char *)&e, sizeof(e)))
            {
                e.display();
            }
            file.close();
            break;

        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}