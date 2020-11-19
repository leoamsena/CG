#include <GL/glut.h> // GLUT, include glu.h and gl.h

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{
    //glClear(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5.0);
    // Draw a line
    glBegin(GL_LINES); // Each set of 4 vertices form a quad
    //glColor3f(1.0f, 0.0f, 0.0f); // Red

    glVertex2i(50, 50); // x, y
    glVertex2i(200, 200);
    glVertex2i(200, 200);
    glVertex2i(200, 50);
    glVertex2i(200, 50);
    glVertex2i(50, 50);

    glEnd();

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
    gluOrtho2D(0.0, 300.0, 0.0, 300.0);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}