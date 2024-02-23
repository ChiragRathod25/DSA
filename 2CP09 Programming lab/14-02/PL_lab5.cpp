// #include <iostream>
// #include <vector>
// #include <string>
// #include <map>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<string> v;
//     map<string, int> m;
//     v.push_back("Himanshu");
//     v.push_back("Huzaifa");
//     v.push_back("Harsh");
//     v.push_back("Himanshu");
//     v.push_back("Huzaifa");
//     v.push_back("Harsh");
//     v.push_back("Himanshu");
//     //sort(v.begin(), v.end());
//     vector<string>::iterator i1, i = v.begin();
//     vector<string>::iterator i2=v.begin(), i5,i3=v.end(),i4;
//     for(i2;i2!=--i3;i2++){
//         i4=i2;
//         for(i5=++i4;i5!=v.end();i5++){
//             string temp1=*i2;
//             string temp2=*i5;
//             if(temp1.compare(temp2)>0){
//                 string temp=*i2;
//                 *i2=*i5;
//                 *i5=temp;
//             }
//         }
//     }
//     for (i; i != v.end(); i++)
//     {
//         string temp = *i;
//         m[temp]++;
//     }
//     map<string, int>::iterator mi = m.begin();
//     for (mi; mi != m.end(); mi++)
//     {
//         cout << mi->first << " " << mi->second << endl;
//     }
// }
#include<iostream>
#include<set>
#include<string>

using namespace std;

int main()
{
    set<string> s;
    s.insert("Himanshu");
    s.insert("Harsh");
    s.insert("Chirag");
    s.insert("vedant");
    s.insert("Huzaifa");
    s.insert("Nipun");
    
    set<string> :: iterator i=s.begin();
    cout<<"Enter a query string : ";
    string temp;
    cin>>temp;
    int flag=0;
    for(i;i!=s.end();i++){
        if(temp.compare(*i)==0){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"Yes\n";
    }
    else
        cout<<"No\n";
        
}