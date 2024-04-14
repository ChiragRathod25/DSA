#include <windows.h>
#include <iostream>
#include <vector>
#include <cmath>
#include "GL/glut.h"
#include <fstream>

using namespace std;

char str[1000] = "NO DATA FOUND";
char temp[1000] = "";
fstream file;
bool flag = true;
bool writing = true;

int option = 0;

class emp
{
    char name[20];
    char id[10];
    int salary;
    bool active = true;

public:
    emp() {}
    emp(char *a, char *b, int c)
    {
        strcpy(name, a);
        strcpy(id, b);
        salary = c;
        active = true;
    }
    void add(char *name, char *id, int salary);
    void modify(char *name, char *id, int salary);
    void del(char *id);
    char *display(char *id);
};

void emp::add(char *name, char *id, int salary)
{
    file.seekp(0, ios::end);
    emp e(name, id, salary);
    file.write((char *)&e, sizeof(e));
}

void emp::modify(char *name, char *id, int salary)
{
    file.seekg(0, ios::beg);
    emp e;
    while (file.read((char *)&e, sizeof(e)))
    {
        if (strcmp(e.id, id) == 0 && !file.eof() && e.active == true)
        {
            strcpy(e.name, name);
            e.salary = salary;
            file.seekp((int)file.tellg() - sizeof(e), ios::beg);
            file.write((char *)&e, sizeof(e));
            break;
        }
    }
}

void emp::del(char *id)
{
    file.seekg(0, ios::beg);
    emp e;
    while (file.read((char *)&e, sizeof(e)))
    {
        if (strcmp(e.id, id) == 0 && !file.eof() && e.active == true)
        {
            e.active = false;
            file.seekp((int)file.tellg() - sizeof(e), ios::beg);
            file.write((char *)&e, sizeof(e));
            break;
        }
    }
}

char *emp::display(char *id)
{
    file.seekg(0, ios::beg);
    emp e;
    while (file.read((char *)&e, sizeof(e)))
    {
        if (!file.eof() && e.active == true && strcmp(e.id, id) == 0)
        {
            strcpy(str, e.name);
            strcat(str, " ");
            strcat(str, e.id);
            strcat(str, " ");
            strcat(str, to_string(e.salary).c_str());
            break;
        }
    }
    return str;
}

void drawText(float x, float y, float r, float g, float b, const char *text)
{
    glColor3f(r, g, b);  // Set text color
    glRasterPos2f(x, y); // Set text position
    for (int i = 0; text[i] != '\0'; ++i)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
    }
}

emp e;
char name[20], id[10];
int salary;
bool first = true, second = false, third = false;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glColor3f(1, 1, 1);

    if (flag)
    {

        for (int i = 600; i > 0; i -= 150)
        {
            glBegin(GL_POLYGON);
            glVertex2f(595, i - 5);
            glVertex2f(5, i - 5);
            glVertex2f(5, i - 145);
            glVertex2f(595, i - 145);
            glEnd();
        }

        drawText(260, 525, 1, 1, 1, "ADD");
        drawText(260, 385, 1, 1, 1, "MODIFY");
        drawText(260, 245, 1, 1, 1, "DELETE");
        drawText(260, 105, 1, 1, 1, "DISPLAY");
        flag = false;
    }
    else
    {
        if (option == 1)
        {
            // add
            static bool added = false;
            if (!added)
                drawText(350, 300, 1, 1, 1, temp);
            if (first)
                drawText(200, 300, 1, 1, 1, "Enter Name :");
            if (!writing && first)
            {
                strcpy(name, temp);
                writing = true;
                for (int i = 0; i < 1000; i++)
                    temp[i] = '\0';
                first = false;
                second = true;
                glutPostRedisplay();
            }
            if (second)
                drawText(200, 300, 1, 1, 1, "Enter ID:");
            if (!writing && second)
            {
                strcpy(id, temp);
                writing = true;
                for (int i = 0; i < 1000; i++)
                    temp[i] = '\0';
                second = false;
                third = true;
                glutPostRedisplay();
            }
            if (third)
                drawText(200, 300, 1, 1, 1, "Enter Salary:");
            if (!writing && third)
            {
                salary = atoi(temp);
                third = false;
                glutPostRedisplay();
            }
            if (!first && !second && !third && !added)
            {
                e.add(name, id, salary);
                added = true;
            }
            if (added)
                drawText(250, 300, 1, 1, 1, "ADDED");
        }
        else if (option == 2)
        {
            // modify
            static bool modified = false;
            if (!modified)
                drawText(350, 300, 1, 1, 1, temp);
            if (first)
                drawText(200, 300, 1, 1, 1, "Enter ID:");
            if (!writing && first)
            {
                strcpy(id, temp);
                writing = true;
                for (int i = 0; i < 1000; i++)
                    temp[i] = '\0';
                first = false;
                second = true;
                glutPostRedisplay();
            }
            if (second)
                drawText(200, 300, 1, 1, 1, "Enter Name :");
            if (!writing && second)
            {
                strcpy(name, temp);
                writing = true;
                for (int i = 0; i < 1000; i++)
                    temp[i] = '\0';
                second = false;
                third = true;
                glutPostRedisplay();
            }
            if (third)
                drawText(200, 300, 1, 1, 1, "Enter Salary:");
            if (!writing && third)
            {
                salary = atoi(temp);
                writing = true;
                for (int i = 0; i < 1000; i++)
                    temp[i] = '\0';
                third = false;
                glutPostRedisplay();
            }
            if (!first && !second && !third && !modified)
            {
                e.modify(name, id, salary);
                modified = true;
            }
            if (modified)
                drawText(250, 300, 1, 1, 1, "MODIFIED");
        }
        else if (option == 3)
        {
            // delete
            static bool deleted = false;
            if (!deleted)
            {
                drawText(350, 300, 1, 1, 1, temp);
                drawText(200, 300, 1, 1, 1, "Enter id");
            }
            if (!writing && !deleted)
            {
                deleted = true;
                strcpy(id, temp);
                writing = true;
                for (int i = 0; i < 1000; i++)
                    temp[i] = '\0';
                e.del(id);
                glutPostRedisplay();
            }
            if (deleted)
            {
                drawText(250, 300, 1, 1, 1, "DELETED");
            }
        }
        else if (option == 4)
        {
            // display
            static bool found = false;
            if (!found)
            {
                drawText(350, 300, 1, 1, 1, temp);
                drawText(200, 300, 1, 1, 1, "Enter id");
            }
            if (!writing && !found)
            {
                found = true;
                strcpy(str, e.display(temp));
                writing = true;
                for (int i = 0; i < 1000; i++)
                    temp[i] = '\0';
                glutPostRedisplay();
            }
            if (found)
            {
                drawText(250, 300, 1, 1, 1, str);
            }
        }
        else
        {
            drawText(0, 0, 1, 1, 1, "ERROR");
        }
    }

    glFlush();
}

int i = 0;
void keyboard(unsigned char key, int x, int y)
{
    temp[i++] = key;
    if (key == 13)
    {
        temp[i] = '\0';
        writing = false;
        i = 0;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:
        if (state == GLUT_DOWN)
        {
            if (x > 5 && x < 595)
            {
                if (y > 455 && y < 595)
                    option = 4;
                else if (y > 305 && y < 445)
                    option = 3;
                else if (y > 155 && y < 295)
                    option = 2;
                else if (y > 5 && y < 145)
                    option = 1;
                else
                    flag = true;
            }
            glutPostRedisplay();
        }
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
    gluOrtho2D(0, 600, 0, 600);
    glEnableClientState(GL_VERTEX_ARRAY);
    glPolygonMode(GL_FRONT, GL_LINE);
    glPolygonMode(GL_BACK, GL_LINE);
}

int main(int argc, char **argv)
{
    file.open("data2.txt", ios::in | ios::out | ios::ate | ios::binary);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("TEST");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}