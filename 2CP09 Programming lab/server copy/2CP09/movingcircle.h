#include<stdio.h>
#include<graphics>
#include<sstream>
#include<math.h>
int main()
{
    initwindow(640,480);
    int x,y,a=90;
 circle(200,200,100);
 for(a=0;a<720;a=a+10)
 {

    // x=100*cos(a*3.14/180);
   //y=100*sin(a*3.14/180);
    y=100*cos(a*3.14/180);
    x=100*sin(a*3.14/180);

   setcolor(GREEN);
   circle(x+200,y+200,10);
   setcolor(BLACK);
   circle(x+200,y+200,10);
 }
getch();
}
