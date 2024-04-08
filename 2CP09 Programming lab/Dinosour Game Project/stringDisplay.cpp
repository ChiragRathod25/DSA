#include <GL/glut.h>
#include <string.h>
#include <windows.h> // for MS Windows
#include <iostream>
#include <string.h> // for strlen
// Function to draw text on the screen
void drawText(const char* text, float x, float y)
{
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer
    glMatrixMode(GL_MODELVIEW);   // To operate on Model-View matrix
    glLoadIdentity();             // Reset the model-view matrix

    const char* text = "Hello, World!";
    int len = strlen(text);
    float width = len * 0.01f; // This is an estimate, adjust as needed

    glColor3f(1.0f, 1.0f, 1.0f); // Set text color to white
    drawText(text, -width / 2, 0.0f); // Draw text at the middle of the screen

    glutSwapBuffers(); // Double buffered - swap the front and back buffers
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                           // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE);                // Enable double buffered mode
    glutInitWindowSize(640, 480);                    // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);                  // Position the window's initial top-left corner
    glutCreateWindow("String Display");              // Create window with the given title

    glutDisplayFunc(display);   // Register callback handler for window re-paint event

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set "clearing" or background color to black

    glutMainLoop();             // Enter the infinite event-processing loop
    return 0;
}