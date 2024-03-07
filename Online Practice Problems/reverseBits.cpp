// https://www.codingninjas.com/studio/problems/reverse-bits_2181102

#include <queue>
#include <math.h>
#include<iostream>
using namespace std;

long reverseBits(long n) {
    long number=n;
    queue<int> myQueue;
    for(int i=0;i<=31;i++){
        myQueue.push(number%2);
        number=number/2;
    }
    // while(!myQueue.empty()){
    //     cout<<myQueue.front();
    //     myQueue.pop();
    // }

    long reverse_number=0;
    int temp;
    for(int i=31;i>=0;i--){
        if(i==0){
            temp=0;
        }
        temp=myQueue.front();
        // cout<<i<<" "<<reverse_number<<" "<<temp<<endl;
        reverse_number+=(temp*pow(2,i));
        myQueue.pop();
    }

    return reverse_number;
}

int main(){
    cout<<reverseBits(4);
}