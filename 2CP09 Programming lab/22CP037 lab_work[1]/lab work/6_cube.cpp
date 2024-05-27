#include <windows.h>
#include <cmath>
#include "GL/glut.h"

GLfloat coord[8][3] = {
    {100, 100, -100},
    {100, 100, 100},
    {100, -100, -100},
    {100, -100, 100},
    {-100, -100, 100},
    {-100, -100, -100},
    {-100, 100, 100},
    {-100, 100, -100}};

GLint phase[6][4] = {
    {0, 1, 3, 2},
    {1, 6, 4, 3},
    {4, 6, 7, 5},
    {0, 2, 5, 7},
    {0, 7, 6, 1},
    {2, 3, 4, 5}};

int angle = 30;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(30, 1, 0, 0);
    glRotatef(angle, 0, 1, 0);
    glBegin(GL_QUADS);

    for (int i = 0; i < 6; i++)
    {
        glVertex3fv(&coord[phase[i][0]][0]);
        glVertex3fv(&coord[phase[i][1]][0]);
        glVertex3fv(&coord[phase[i][2]][0]);
        glVertex3fv(&coord[phase[i][3]][0]);
    }

    glEnd();
    glPopMatrix();
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            angle += 10;
            angle %= 360;
            glutPostRedisplay();
        }
        break;

    case GLUT_RIGHT_BUTTON:
        break;

    default:
        break;
    }
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-200, 200, -200, 200, -200, 200);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TEST");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
}