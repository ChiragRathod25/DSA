#include <windows.h>
#include <math.h>
#include "GL/glut.h"

float x = 0, y = 0;

void display()
{
    // glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
    // glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);

    glBegin(GL_LINES);
    glVertex2f(1, -.215);
    glVertex2f(-1, -.215);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0 + x, 0);
    glVertex2f(-.2 + x, .3);
    glVertex2f(.5 + x, .3);

    glVertex2f(0 + x, 0);
    // glVertex2f(.4, .3);
    // glVertex2f(.0, .4);
    glEnd();

    glColor3f(0, .5, .87);
    glBegin(GL_POLYGON);
    glVertex2f(-.2 + x, .3);
    glVertex2f(-.4 + x, .0);
    glVertex2f(0 + x, .0);
    glEnd();

    glColor3f(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(.5 + x, .3);
    // glVertex2f(.5, .3);
    // glVertex2f(.5, 0);
    glVertex2f(.5 + x, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.5 + x, .3);
    glVertex2f(.7 + x, .37);
    glEnd();

    glColor3f(0, 1, .0);
    glBegin(GL_LINE_LOOP);
    float r = .21;
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.14 / 180;
        float x1 = r * cos(angle) + -.4 + x;
        float y1 = r * sin(angle) + 0;

        glVertex2f(x1, y1);
    }
    glEnd();

    glColor3f(0, 1, .0);
    glBegin(GL_LINE_LOOP);
    // r = .28;
    for (int i = 0; i < 360; i++)
    {
        float angle = i * 3.14 / 180;
        float x1 = r * cos(angle) + .5 + x;
        float y1 = r * sin(angle) + 0;

        glVertex2f(x1, y1);
    }
    glEnd();
    x += 0.1;
    glFlush();
}

void init()
{
    glClearColor(1, 1, 1, 1);
    glColor3f(0, 0.0, 1.0);
}

void time(int x)
{
    glutPostRedisplay();
    glutTimerFunc(500, time, 0);
}

int main(int argc, char *argv[])
{
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cycle");
    init();
    glutTimerFunc(0, time, 0);
    glutDisplayFunc(display);
    glutMainLoop();
}