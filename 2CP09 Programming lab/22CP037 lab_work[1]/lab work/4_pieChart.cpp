#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "GL/glut.h"
#include <fstream>

std::vector<int> data;

std::vector<int> angle;

void getData()
{
    std::ifstream file("data.txt", std::ios::in);
    int temp;
    while (file >> temp)
    {
        data.push_back(temp);
    }
    file.close();
}

void calculateAngle()
{
    int total = 0;
    for (unsigned int i = 0; i < data.size(); i++)
    {
        total += data[i];
    }

    for (unsigned int i = 0; i < data.size(); i++)
    {
        angle.push_back((data[i] * 360) / total);
    }
}

int startAngle = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 1, 1);
    for (unsigned int i = 0; i < data.size(); i++)
    {
        glBegin(GL_POLYGON);
        int endAngle = angle[i] + startAngle;
        glVertex2f(0.0f, 0.0f);
        for (int j = startAngle; j <= endAngle; j = j + 1)
        {
            float radians = j * (3.14159f / 180.0f);
            glVertex2f(100 * cos(radians), 100 * sin(radians));
        }
        startAngle = endAngle;
        glEnd();
    }
    glFlush();
}

void init()
{
    glClearColor(0, 0, 0, 0);
    glColor3f(1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-320, 320, -320, 320);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);
}

int main(int argc, char **argv)
{
    getData();
    calculateAngle();
    // angle.push_back(30);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 640);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TEST");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}