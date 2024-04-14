#include <windows.h>
#include <cmath>
#include "GL/glut.h"

int angle = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    for (float i = 0; i < 360; i = i + 0.3)
    {
        glVertex2f(200 * cos(i * 3.14159 / 180), 200 * sin(i * 3.14159 / 180));
    }
    glEnd();

    glColor3f(1, 0, 0);
    for (int i = 0; i < 360; i++)
    {
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glBegin(GL_POLYGON);
        for (float i = 0; i < 360; i = i + 0.3)
        {
            glVertex2f(200 + 50 * cos(i * 3.14159 / 180), 50 * sin(i * 3.14159 / 180));
        }
        glEnd();
        glPopMatrix();
    }
    glFlush();
}

void update(int a){
    angle = angle - 3;
    glutPostRedisplay();
    glutTimerFunc(10, update, 0);
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320, 320, -320, 320);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TEST");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(10, update, 0);
    glutMainLoop();
}