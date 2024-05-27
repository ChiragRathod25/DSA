#include <windows.h>
#include <GL\glut.h>
#include <iostream>
#include <vector>
#define PI 3.14
int width = 800;
int height = 600;
int flag = false;

std::vector<std::pair<int, int>> points;
void drawPoints()
{
    glColor3f(1.0f, 1.0f, 1.0f); // White color
    if (!flag)
    {
        glBegin(GL_POINTS);
        for (const auto &point : points)
        {
            glVertex2i(point.first, point.second);
        }
        glEnd();
    }
    else
    {
        glColor3f(1.0f, 1.0f, 1.0f); // White color
        glBegin(GL_POLYGON);
        for (const auto &point : points)
        {
            glVertex2i(point.first, point.second);
        }
        glEnd();
    }
}
void drawPolygon()
{
}
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawPoints();
    // drawPolygon();
    glutSwapBuffers();
}
void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            points.push_back(std::make_pair(x, height - y)); // Invert y-coordinate
            glutPostRedisplay();
        }
        break;
    case GLUT_RIGHT_BUTTON:
        if (state == GLUT_DOWN)
        {
            flag=true;
             glutPostRedisplay();
        }
        break;

    default:
        break;
    }
    // if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    //     points.push_back(std::make_pair(x, height - y)); // Invert y-coordinate
    //     glutPostRedisplay();
    // }
}

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0); // Set background color to black
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, 0.0, height);
}

int main(int argc, char **argv)
{
    // glutInit(&argc, argv);
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // glutInitWindowSize(500, 500);
    // glutCreateWindow("My First OpenGL Window");
    // glutInitWindowPosition(0, 0);
    // glutMouseFunc(mouse);
    // glutDisplayFunc(Display);

    // init();
    // glutMainLoop();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polygon Drawing and Rotation");
    init();
    glutDisplayFunc(Display);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}