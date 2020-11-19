#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <iostream>
using namespace std;

void display()
{
    int indices[12][2] = {{1, 2}, {1, 3}, {3, 6}, {6, 8}, {8, 9}, {9, 7}, {7, 4}, {4, 2}, {5, 2}, {5, 8}, {5, 3}, {5, 7}};
    int pontos[9][2] = {{100, 150}, {75, 125}, {125, 125}, {50, 100}, {100, 100}, {150, 100}, {75, 75}, {125, 75}, {100, 50}};
    
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5.0);
    // Draw a line
    glBegin(GL_LINES); // Each set of 4 vertices form a quad
    //glColor3f(1.0f, 0.0f, 0.0f); // Red
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int indexXdoPonto = indices[i][j];
            int indexYdoPonto = indices[i][j];

            glVertex2i(pontos[indexXdoPonto - 1][0], pontos[indexYdoPonto - 1][1]);
            cout << "(" << pontos[indexXdoPonto - 1][0] << "," << pontos[indexYdoPonto - 1][1] << ")";
        }
        cout << endl
             << "------" << endl;
    }
    // x, y

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
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
    glutMainLoop(); // Enter the event-processing loop
    return 0;
}