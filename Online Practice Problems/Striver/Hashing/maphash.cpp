#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    map<char,int\> mp;
    for(int i=0;i<str.length();i++){
        mp[str[i]]++;
    }
    for(auto itr:mp){
        cout<<itr.first<<" "<<itr.second<<endl;
    }
}