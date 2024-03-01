#include<stdio.h>
#include<graphics.h>
#include<sstream>
#include<math.h>
int main()
{
    initwindow(640,400);
    int x,y,a=10;
    setcolor(RED);
 circle(200,200, 100);
 for(a=0;a<720;a=a+10)
 {

    // x=100*cos(a*3.14/180);
   //y=100*sin(a*3.14/180);
    y=100*cos(a*3.14/180);
    x=100*sin(a*3.14/180);

   setcolor(WHITE);
   circle(x+200,y+200,10);
   delay(100);
   setcolor(GREEN);
   circle(x+200,y+200,10);

  setcolor(WHITE);
   circle(x+400,y+400,30);
   delay(100);
   setcolor(GREEN);
   circle(x+400,y+400,30);

 }
getch();
}
