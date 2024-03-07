#include <windows.h>
#include "GL/glut.h"
using namespace std;
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //line
    glBegin(GL_LINE);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex2f(1,1);
    glVertex2f(2,2);
    glEnd();

    //rectangle

    glBegin(GL_QUADS);           // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(-0.8f, 0.1f);     // Define vertices in counter-clockwise (CCW) order
    glVertex2f(-0.2f, 0.1f);     //  so that the normal (front-face) is facing you
    glVertex2f(-0.2f, 1);
    glVertex2f(-0.8f, 1);
    glEnd();
    //triangle
    glBegin(GL_TRIANGLES);           // Each set of 4 vertices form a quad
    glColor3f(0.1f,0.3f,1.0f);
    glVertex2f(0,0);
    glVertex2f(0.8f,0);
    glVertex2f(0.4f,0.8f);
    glEnd();
    glFlush();
}
void Init()
{
    glClearColor(0, 0, 0, 0);
}
void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
}
// void reshape(){}
int main(int argc, char *argv[])
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(321, 240);
    glutCreateWindow("Chirag Rathod");
    Init();
    glutDisplayFunc(Display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}