#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(void){
    string str;
    cin>>str;
    
    set<char> s;
    int long_length=0;
    for(int i=0;i<str.length();i++){
        auto it = s.find(str[i]);
        if(it==s.end()){
            s.insert(str[i]);
            long_length++;
        }
        else if(it!=s.end()){
            continue;;
        }
    }
    cout<<"length of longest substring : "<<long_length<<endl;

    return 0;
}