#include<windows.h>
#include"GL/glut.h"
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 1, 1); 
    glFlush();          
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    gluOrtho2D(0.0, 160.0, 0.0, 120.0);
}
void init()
{
    glClearColor(2.6, 0.5, 1.2, 0);
}
int main(int argc, char *argv[])
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480);
    glutCreateWindow("Hello ");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}