#include<iostream>
using namespace std;
int fact(int n){
    if(n==1||n==0){
        return 1;
    }
    return n*fact(n-1);
}
int main(){
    cout<<fact(4)<<endl;
    cout<<fact(5)<<endl;
    cout<<fact(0)<<endl;
    return 1;
}