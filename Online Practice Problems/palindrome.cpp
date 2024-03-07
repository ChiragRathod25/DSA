// https://www.codingninjas.com/studio/problems/palindrome-number_624662
#include<iostream>
#include<string>
using namespace std;
bool palindrome(int n)
{
    // Write your code here
   string number=to_string(n);
   for(int i=0;i<number.size()/2;i++){
       if(number[i]!=number[number.size()-i-1]){
           return false;
       }
   }
   return true;
}
int main(){
   cout<<palindrome(121);
}