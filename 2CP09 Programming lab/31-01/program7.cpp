#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map<string, float> student;

int main(void)
{
    string name;
    float marks;
    int choice;
    student result;
    map<string, float>::iterator itr;

    cout << "--:List of Queries:--" << endl
         << "1. X Y : Add the marks Y to student whose name is X" << endl
         << "2. X : Erase the marks of the student whose name is X" << endl
         << "3. X : Print the marks of student whose name is X" << endl
         << "4. Display student" << endl
         <<"5. Exit"<<endl;
    while (true)
    {
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:{

            cout << "Enter name : ";
            cin >> name;
            cout << "Enter marks : ";
            cin >> marks;
            result[name] = marks;
            break;
        }
        case 2:
         {
            cout << "Enter student name : ";
            cin >> name;
            itr = result.begin();
            auto itr = result.find(name);
            result.erase(itr);
            break;
         } 
        case 3:
           {
            cout << "Enter name to search :";
            cin >> name;
            marks = result[name];
            cout << "Marks : " << marks << endl;
            break;
           }
        case 4:
        {
            itr = result.begin();
            for (auto itr = result.begin(); itr != result.end(); itr++)
            {
                cout << itr->first << '\t' << itr->second << endl;
            }
        } 
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }

    return 0;
}