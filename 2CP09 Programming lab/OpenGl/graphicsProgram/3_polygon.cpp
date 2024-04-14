#include <windows.h>
#include <cmath>
#include "GL/glut.h"
#include <vector>

bool flag = false;

std::vector<std::pair<int, int>> vec;

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            flag = false;
            vec.push_back(std::make_pair(x - 400, 300 - y));
            glutPostRedisplay();
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            flag = true;
            glutPostRedisplay();
        }
        break;

    default:
        break;
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPointSize(5);

    if (flag)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_POINTS);

    for (auto temp : vec)
        glVertex2i(temp.first, temp.second);

    glEnd();
    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glColor3f(1, 1, 1);
    gluOrtho2D(-400, 400, -300, 300);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TEST");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}