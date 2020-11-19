#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <iostream>
#include <cmath>

#define PI 3.1415926535898

using namespace std;
void drawCircle()
{
    GLfloat circle_points = 100;

    glBegin(GL_LINE_LOOP);
    double lx, ly;
    for (int i = 0; i < circle_points / 4; i++)
    {
        double angle = 2 * PI * i / circle_points;
        lx = cos(angle);
        ly = sin(angle);
        glVertex2f(lx, ly);
    }
    cout << lx << " " << ly;
    glVertex2f(lx, ly);
    glVertex2f(lx - 1.0, ly);
    for (int i = 0; i < circle_points / 4; i++)
    {
        double angle = 2 * PI * i / circle_points;
        lx = cos(angle);
        ly = sin(angle);
        glVertex2f(lx, ly);
    }

    glEnd();
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(1.0);
    // Draw a line
    drawCircle();
    //glTranslatef(2, 2, 0);

    glFlush(); // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char **argv)
{

    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    glutInitWindowSize(320, 320);          // Set the window's initial width & height
    glutInitWindowPosition(50, 50);        // Position the window's initial top-left corner
    glutDisplayFunc(display);              // Register display callback handler for window re-paint
    glClearColor(1.0, 1.0, 1.0, 0.0);
    //glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-4.0, 4.0, -4.0, 4.0, -4.0, 1.0);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}