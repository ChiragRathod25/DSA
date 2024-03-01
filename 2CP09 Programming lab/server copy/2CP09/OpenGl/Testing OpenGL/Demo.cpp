#include <windows.h>

//#include "GL/glut.h"

#define PI 3.14

  void display()
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINE_LOOP);
   Glint circle_pont = 5;
   for(float i=0; i<360;i++)
   {
    float angle = PI*i/180;
    glvertex2f(0.2*cos(angle),0.2*sin(angle))
   }
    glEnd();

    glFlush();
  }

  void init()
  {
    glClearColor(0.000, 0.110, 0.392, 0.0); // JMU Gold

    glColor3f(0.314, 0.314, 0.000); // JMU Purple

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
  }

  int main(int argc, char** argv)
  {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Test");
    glutDisplayFunc(display);
    init();
    glutMainLoop();
  }
