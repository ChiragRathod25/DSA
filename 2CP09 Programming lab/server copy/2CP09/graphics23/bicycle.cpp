#include<iostream>
#include<graphics.h>
#include<sstream>
#include<math.h>
#include <windows.h>
using namespace std;

int main()
{

    initwindow(640,480);

    setcolor(WHITE);

     for(int i=0;i<100;i++)
     {

       circle(100,100,i);

     }

      setcolor(RED);
      for(int i=0;i<80;i++)
      {
          circle(200,200,i);
      }

    setcolor(YELLOW);
      for(int i=0;i<60;i++)
      {
          circle(270,270,i);
      }

     setcolor(YELLOW);
     for(int i=0;i<60;i++)
      {
     ellipse ( 230,450,450,560, 780, 890);
      }

getch();

}
