//search,delete,add, editing, displaying
#include<iostream>
#include<fstream>
#include<map>
typedef map<string,string,string,float> employee;
using namespace std;

int main(){
    int n;
    cout<<"Enter Total Employee : ";
    cin>>n;
    employee emp[n];
    for(int i=0;i<n;i++){
        emp[i].insert();
    }
    ofstream out("Employee");

    
    return 0;
}