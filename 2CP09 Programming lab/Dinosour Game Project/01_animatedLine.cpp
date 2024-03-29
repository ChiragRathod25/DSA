/*
 * GL06TimerFunc.cpp: Translation and Rotation
 * Transform primitives from their model spaces to world space (Model Transform).
 */
#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <Math.h>    // Needed for sin, cos
#include <iostream>
#define PI 3.14159265f
using namespace std;
// global variable
GLfloat angle = 0.0f;
int refreshMills = 100; // refresh interval in milliseconds
GLfloat xCoordinate = -1.0f;

GLfloat ballRadius = 0.1f; // Radius of the bouncing ball
int windowWidth = 640;     // Windowed mode's width
int windowHeight = 480;    // Windowed mode's height
int windowPosX = 50;       // Windowed mode's top-left corner x
int windowPosY = 50;       // Windowed mode's top-left corner y

/* Initialize OpenGL Graphics */
void initGL()
{
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}
/* Called back when timer expired */
void Timer(int value)
{
    glutPostRedisplay();                   // Post re-paint request to activate display()
    glutTimerFunc(refreshMills, Timer, 0); // next Timer call milliseconds later
}

void xCoordinateUpdate(GLfloat xCoordinate)
{
}
/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glMatrixMode(GL_MODELVIEW);   // To operate on Model-View matrix
    glLoadIdentity();             // Reset the model-view matrix

    glPushMatrix();                 // Save model-view matrix setting
    glTranslatef(0.0f, 0.0f, 0.0f); // Translate

    glBegin(GL_LINES);           // Each set of 4 vertices form a quad
    glColor3f(0.0f, 0.0f, 1.0f); // Red
    glVertex2f(xCoordinate + 0.5f, 0.0f);
    glVertex2f(xCoordinate - 0.5f, 0.0f);
    glEnd();

    glBegin(GL_LINES);           // Each set of 4 vertices form a quad
    glColor3f(0.0f, 1.0f, 0.0f); // Red
    glVertex2f(xCoordinate + 0.3f, 0.0f);
    glVertex2f(xCoordinate - 0.3f, 0.0f);
    glEnd();

    glBegin(GL_LINES);           // Each set of 4 vertices form a quad
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(xCoordinate + 0.1f, 0.0f);
    glVertex2f(xCoordinate - 0.1f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    // glVertex2f(0.0f, 0.0f);      // Center of circle
    glVertex2f(xCoordinate, xCoordinate); // Center of circle
    int numSegments = 100;
    GLfloat angle;
    for (int i = 0; i <= numSegments; i++)
    {
        angle = i * 2.0f * PI / numSegments; // 360 deg for all segments
        glVertex2f(cos(angle) * ballRadius+xCoordinate , sin(angle) * ballRadius+0.2f );
    }
    glEnd();

    glPopMatrix(); // Restore the model-view matrix

    glutSwapBuffers(); // Double buffered - swap the front and back buffers

    xCoordinate = xCoordinate + 0.1f;
    if (xCoordinate >= 1.0f)
    {
        xCoordinate = -1.3f;
    }
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height)
{ // GLsizei for non-negative integer
    // Compute aspect ratio of the new window
    if (height == 0)
        height = 1; // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping area to match the viewport
    glMatrixMode(GL_PROJECTION); // To operate on the Projection matrix
    glLoadIdentity();
    if (width >= height)
    {
        // aspect >= 1, set the height from -1 to 1, with larger width
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    }
    else
    {
        // aspect < 1, set the width to -1 to 1, with larger height
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
    }
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                           // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE);                // Enable double buffered mode
    glutInitWindowSize(640, 480);                    // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);                  // Position the window's initial top-left corner
    glutCreateWindow("Animation via Idle Function"); // Create window with the given title
    glutDisplayFunc(display);                        // Register callback handler for window re-paint event
    glutReshapeFunc(reshape);                        // Register callback handler for window re-size event
    glutTimerFunc(0, Timer, 0);                      // First timer call immediately
    initGL();                                        // Our own OpenGL initialization
    glutMainLoop();                                  // Enter the infinite event-processing loop
    return 0;
}