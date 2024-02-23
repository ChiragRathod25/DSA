//int array
//if the mot occupied , check if it is not occupied then enter or raise error
//update this to insert into queue , filo
//delete index

#include<iostream>
using namespace std;
class array{
    int *arr;
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
    delete[] arr;
    }
    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    void insert(int val,int i){
    try{
        if(i>size-1){
            throw "Enter valid Index";
        }
        if(arr[i]==0){
            arr[i]=val;
        }
    else {
        throw val;
    }
    }
    catch(const char *valid){
    cout<<"Enter Valid Index"<<endl;
    }
    catch(int v){
    cout<<"Occupied Index"<<endl;
    }
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
                <<"3.Exit"<<endl;
                cin>>check;
            switch(check){
            case 1:
                    int value,index;
                    cout<<"Enter Value : ";
                    cin>>value;
                    cout<<"Enter Index : ";
                    cin>>index;
                    a.insert(value,index);
                    break;
            case 2:
                a.display();
                break;
            case 3:
                 return 0;
            }
    }
return 1;
}
