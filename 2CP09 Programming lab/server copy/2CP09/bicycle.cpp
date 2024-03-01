#include<iostream>
#include<graphics.h>
#include<sstream>
#include<math.h>

using namespace std;

int main()
{

    initwindow(640,480);

    setcolor(WHITE);

    for(int i=0;i<100;i++)
     {

       circle(100,100,i);

     }

     ellipse ( 23,  45,45,  56,  78,  89);

getch();

}
