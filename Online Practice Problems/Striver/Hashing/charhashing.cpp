#include<iostream>
#include<string>
using namespace std;
int main(){

    string str;
    getline(std::cin, str);
    int hash[122]={0};
    for(int i=0;i<str.length();i++){
        hash[str[i]]++;
    }
    for (size_t i = 0; i < 122; i++)
    {
        if(hash[i]!=0)
        cout<<char(i)<<" "<<hash[i]<<endl;
    }
    
}