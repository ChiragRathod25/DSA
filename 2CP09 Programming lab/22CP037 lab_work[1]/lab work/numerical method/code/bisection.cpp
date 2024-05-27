//Equation : x^3 - x - 2
#include<bits/stdc++.h>
using namespace std;

double f(double x){
    return pow(x,3)-x-2;
}

void bisection(double a, double b,double tol=0.01){
    if(f(a)*f(b) > 0){
        cout<<"Bounds are not correct"<<endl;
        exit (0);
    }
    double c = a;

    while((b-a)>=tol){
        c = (b + a)/2;
        if(f(c) == 0){
            break;
        }
        else if(f(c)*f(a) < 0){
            b = c;
        }
        else{
            a = c;
        }
    }
    cout<<"Root : "<<c;
}

int main(){
    double a=0 ,b=1;
    for(int i=0 ; i<10; i++){
        if(f(a)*f(b) < 0){
            bisection(a,b);
            break;
        }
        else{
            a++;
            b++;
        }
    }
    return 0;
}