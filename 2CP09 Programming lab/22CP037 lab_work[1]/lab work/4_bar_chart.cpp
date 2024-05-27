#include <windows.h>
#include <cmath>
#include "GL/glut.h"
#include <iostream>
#include <vector>
#include <fstream>

std::vector<int> data;

int max()
{
    int max = data[0];
    for (unsigned int i = 1; i < data.size(); i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    return max;
}

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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 1, 1);

    float maxVal = max();
    float barWidth = 640.0f / data.size();

    for (unsigned int i = 0; i < data.size(); i++)
    {
        glBegin(GL_QUADS);
        glVertex2f(i * barWidth + 5, 0);                            // Bottom-left corner
        glVertex2f((i + 1) * barWidth - 5, 0);                      // Bottom-right corner
        glVertex2f((i + 1) * barWidth - 5, data[i] / maxVal * 600); // Top-right corner
        glVertex2f(i * barWidth + 5, data[i] / maxVal * 600);       // Top-left corner
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
    gluOrtho2D(0, 640, 0, 640);
}

int main(int argc, char **argv)
{
    getData();
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