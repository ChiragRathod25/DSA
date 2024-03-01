#include<graphics.h>
#include<iostream>
#include<stdio.h>
#include <dos.h>
using namespace std;
//const int DELAY = 50;
int pver[100],i=0;

int main()
{
int gd,gm,a,b,x,y;
detectgraph(&gd,&gm);
initgraph(&gd,&gm," ");
setcolor(RED);
do
{
    if(ismouseclick(WM_LBUTTONDOWN))
       {
    getmouseclick(WM_LBUTTONDOWN, x, y);
    circle(x,y,20);
    pver[i]=x;
    pver[i+1]=y;
    i=i+2;
       }


}while(!ismouseclick(WM_RBUTTONDOWN));

pver[i]=pver[0];
pver[i+1]=pver[1];
//i=i+2;
//i=i/2;

//int j=0;
//for (int j=0 ;j<i;j=j+2)
 // line(pver[j],pver[j+1],pver[j+2],pver[j+3]);

drawpoly(i, pver);
//line(100,100,200,200);
getch();

}



