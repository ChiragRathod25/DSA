//int array
//if the mot occupied , check if it is not occupied then enter or raise error
//update this to insert into queue , filo
//delete index

#include<iostream>
using namespace std;
class array{
    int *arr;
    int top=0;
    int size;
public:
    array(int n){
    arr=new int[n];
    size=n;
    for(int i=0;i<size;i++){
        arr[i]=0;
    }
    }
    ~array(){
    delete arr;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    void insert(int val){
    try{
         if(top==size){
            throw val;
         }
       arr[top++]=val;

    }
    catch(int v){
    cout<<"Array is full"<<endl;
    }
    }
    void delete_index(int n){
        for(int i=n;i<size;i++){
            arr[i]=arr[i+1];
        }
        arr[size-1]=0;
    }
};
int main(void){
    int s;
    cout<<"Enter Size of array : ";
    cin>>s;
    array a(s);
    int check;
    while(true){

          cout<<endl<<"1.Insert Number"<<endl
                <<"2.display"<<endl
                <<"3.delete"<<endl
                <<"4.Exit"<<endl;
                cin>>check;
            switch(check){
            case 1:
                    int value;
                    cout<<"Enter Value : ";
                    cin>>value;
                    a.insert(value);
                    break;
            case 2:
                a.display();
                break;
            case 3:
                int index;
                cout<<"Enter index to delete : ";
                cin>>index;
                a.delete_index(index);
                break;
            case 4:
                 return 0;
            }
    }
return 1;
}
