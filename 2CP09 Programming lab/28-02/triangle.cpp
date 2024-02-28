#include <windows.h>
#include "GL/glut.h"
void display()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // red color
    glVertex2f(-0.8f, 0.1f);
    glVertex2f(-0.2f, 0.1f);
    glVertex2f(-0.2f, 0.7f);
    glVertex2f(-0.8f, 0.7f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 1.0f); // blue color
    glVertex2f(0.1f, -0.6f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.4f, -0.1f);
    glEnd();

    glFlush(); // Render now
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
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(720, 480);
    glutCreateWindow("Hello ");
    init();
    glutDisplayFunc(display);
    // glutReshapeFunc(reshape);
    glutMainLoop();
}