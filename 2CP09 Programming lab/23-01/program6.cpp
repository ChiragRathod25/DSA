#include<iostream>
#include<list>
using namespace std;
void display(list<int> &ls){
    list<int>::iterator p;
    for(p=ls.begin();p!=ls.end();p++){
        cout<<*p<<" ";
    }
    cout<<endl;
}
int main(void){
    int choice;
    list<int> ls;
    list<int>::iterator p;
    int n,temp;
    
    cout<<"Enter total Integers : ";
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        ls.push_back(temp);
    }
    cout<<"1.Insert\n"
            <<"2.Display\n"
            <<"3.Remove\n"
            <<"4.Append\n"
            <<"5.sort\n"
            <<"6.POP\n"
            <<"7.Reverse\n"
            <<"8.Exit\n";
    while(true){
        cout<<"Select : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            int index;
            cout<<"Enter index to insert : ";
            cin>>index;
            if(index>ls.size()+1){
                cout<<"Enter valid index \n";
                break;
            }
            p=ls.begin();
            advance(p,index);
            cout<<"Enter value to insert : ";
            cin>>temp;
            ls.insert(p,temp);
            break;
        case 2:
            display(ls);
            break;
        case 3:
            cout<<"Enter element to remove : ";
            cin>>temp;
            ls.remove(temp);
            break;
        case 4:
            cout<<"Enter Integer to insert :";
            cin>>temp;
            ls.push_back(temp);
            break;
        case 5:
            ls.sort();
            display(ls);
            break;
        case 6:
            temp=ls.back();
            ls.pop_back();
            cout<<temp<<endl;
            break;
        case 7:
            ls.reverse();
            display(ls);
            break;
        case 8:
        exit(0);
            break;
        }
    }
    return 1;
}