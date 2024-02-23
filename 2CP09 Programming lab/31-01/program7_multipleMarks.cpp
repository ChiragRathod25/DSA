#include <iostream>
#include <map>
#include <string>
#include<vector>
using namespace std;
typedef map<string, vector<float>> student;
void display(vector<float> vect){
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<" ";
    }
    cout<<"\n";
}
int main(void)
{
    string name;
    float marks;
    int choice,queries;
    student result;
    map<string, vector<float>>::iterator itr;
    cout << "--:List of Queries:--" << endl
         << "1. X Y : Add the marks Y to student whose name is X" << endl
         << "2. X : Erase the marks of the student whose name is X" << endl
         << "3. X : Print the marks of student whose name is X" << endl
         << "4. Display student" << endl
         <<"5. Exit"<<endl;
    cout<<"Enter total Queries :";
    cin>>queries;
    int i=0;   
    while (i++<queries)
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
            result[name] .push_back(marks);
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
            vector<float> v = result[name];
            display(v);
            break;
           }
        case 4:
        {
            itr = result.begin();
            for (auto itr = result.begin(); itr != result.end(); itr++)
            {
                cout << itr->first << '\t' ;
                vector<float> v=result[itr->first];
                display(v);
            }
        } 
        break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}