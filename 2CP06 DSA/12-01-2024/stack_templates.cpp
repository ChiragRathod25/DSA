//last in first out
//using templates
#include<iostream>
using namespace std;
template <class Type>
class stack_arr{
    Type *arr;
    int size;
    int top=-1;
public:
    stack_arr(int n){
    arr=new Type[n];
    size=n;
    for(int i=0;i<size;i++){
        arr[i]=0;
    }
    }
 
    ~stack_arr(){
    delete arr;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    void insert(Type val){
    try{
         if(top==size-1){
            throw val;
         }
         top++;
       arr[top]=val;

    }
    catch(...){
    cout<<"Array is full"<<endl<<"We can't take this value"<<endl;
    }
    }
    void delete_index(){
            arr[top--]=0;
    }
};
int main(void){
    int s;
    cout<<"Enter Size of array : ";
    cin>>s;
    stack_arr<float> a(s);
    int check;
    while(true){
          cout<<endl<<"1.Insert Number"<<endl
                <<"2.display"<<endl
                <<"3.delete"<<endl
                <<"4.Exit"<<endl;
                cin>>check;
            switch(check){
            case 1:
                    float value;
                    cout<<"Enter Value : ";
                    cin>>value;
                    a.insert(value);
                    break;
            case 2:
                a.display();
                break;
            case 3:
                a.delete_index();
                break;
            case 4:
                 return 0;
            }
    }
return 1;
}
