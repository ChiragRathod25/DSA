#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>
using namespace std;

class Employee {
    char id[10];
    char name[50];
    char department[50];
    float salary;

public:
    void insert() {
        cout << "Enter Employee id, name, department, salary: ";
        cin >> id >> name >> department >> salary;
    }

    const char* get_name() const {
        return name;
    }

    void update() {
        cout << "Enter New Salary and Department: ";
        cin >> salary >> department;
    }

    void display() const {
        cout << id << setw(10)
            << name << setw(10)
            << department << setw(10)
            << salary << endl;
    }

    void deleteEmployee() {
        name[0] = '\0';
        salary = 0;
        id[0] = '\0';
        department[0] = '\0';
    }
};

int main() {
    Employee e;
    int input;
    fstream file;
    char search[50];
    int flag = 0;
    int pos = -1;

    while (1) {
        cout << "1. Insert\n"
            << "2. Display\n"
            << "3. Search\n"
            << "4. Update\n"
            << "5. Delete\n"
            << "6. Exit\n";
        cin >> input;

        switch (input) {
        case 1:
            e.insert();
            file.open("Employee", ios::app);
            file.write((char*)&e, sizeof(e));
            file.close();
            break;
        case 2:
            file.open("Employee", ios::in);
            file.seekg(0, ios::beg);
            while (file.read((char*)&e, sizeof(e))) {
                e.display();
            }
            file.close();
            break;
        case 3:
            cout << "Enter Name to search: ";
            cin >> search;
            file.open("Employee", ios::in);
            file.seekg(0, ios::beg);
            while (file.read((char*)&e, sizeof(e))) {
                if (strcmp(e.get_name(), search) == 0)
                    e.display();
            }
            file.close();
            break;
        case 4:
            cout << "Enter Name to Update: ";
            cin >> search;
            pos = -1;
            file.open("Employee", ios::in);
            file.seekg(0, ios::beg);
            while (!file.eof()) {
                flag = file.tellg();
                file.read((char*)&e, sizeof(e));
                if (strcmp(e.get_name(), search) == 0) {
                    pos = flag;
                    break;
                }
            }
            file.clear();
            file.close();
            if (pos > -1) {
                file.open("Employee", ios::in | ios::out);
                e.update();
                file.seekp(pos, ios::beg);
                file.write((char*)&e, sizeof(e));
                file.close();
            }
            break;
        case 5:
            cout << "Enter Name to Delete: ";
            cin >> search;
            pos = -1;
            file.open("Employee", ios::in);
            file.seekg(0, ios::beg);
            while (!file.eof()) {
                flag = file.tellg();
                file.read((char*)&e, sizeof(e));
                if (strcmp(e.get_name(), search) == 0) {
                    pos = flag;
                    break;
                }
            }
            file.clear();
            file.close();
            if (pos > -1) {
                file.open("Employee", ios::in | ios::out);
                e.deleteEmployee();
                file.seekp(pos, ios::beg);
                file.write((char*)&e, sizeof(e));
                file.close();
            }
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
