#include <iostream>
#include <string>
#include <set>
using namespace std;
int main(void){
    int n;
    cin>>n;
    string temp;
    multiset<string,greater<string>> s;
    set<string> s2;
    while(n--){
        cin>>temp;
        s.insert(temp);
    }
   
    //inserting unique strings into set
    multiset<string,greater<string>> ::iterator itr;
    for(itr=s.begin();itr!=s.end();itr++){
        auto it = s2.find(*itr);
        if(it==s2.end()){
            s2.insert(*itr);
        }
    }
    //printing unique string
   for (auto& str : s2) {
        std::cout << str << ' ';
    }
    return 0;
}