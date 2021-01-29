/*
 *  Este código é uma modificação de "robo.cpp" com o intuito de realizar os movimentos sozinho.
 *  Foi feito como curiosidade, sendo que 
 */

#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
using namespace std;

double velocidade = 0.5,posDisco[2][2] = { {{-3.0},{0.0}},{{3.0},{0.0}}},zoom=0.0;
GLfloat win = 0.0f;
int rotX = 0, rotY = 0;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0,(GLfloat)zoom,0.0);
    glPushMatrix();
        glRotatef((GLfloat)rotX, 1.0, 0.0, 0.0);
        glRotatef((GLfloat)rotY, 0.0, 1.0, 0.0);
        

        //campo
        glPushMatrix();
            glScalef(15.0, 1.0, 10.0);
            glutSolidCube(1.0);
        glPopMatrix();

        // disco 1 (amarelo)
        glPushMatrix();
            glColor3f(1.0f, 1.0f, 0.0f);
            glTranslatef(posDisco[0][0],1.3,posDisco[0][1]);
            glScalef(1.0, 0.2, 1.0);
            glutSolidSphere(0.5, 10, 10);
        glPopMatrix();

        // disco 1 (rosa)
        glPushMatrix();
            glColor3f(1.0f, 0.0f, 1.0f);
            glTranslatef(posDisco[1][0],1.3,posDisco[1][1]);
            glScalef(1.0, 0.2, 1.0);
            glutSolidSphere(0.5, 10, 10);
        glPopMatrix();

        glPopMatrix();

        glutSwapBuffers();
}

void moverBola(int)
{
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D (-win, win, -win, win);
    glTranslatef(0.0, 0.0, -5.0);
    

}

void keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 27:
        exit(0);
        break;
    case 'x':
        rotX = (rotX + 5) % 360;

        break;
    case 'X':
        rotX = (rotX - 5) % 360;
        break;
    case 'c':
        rotY = (rotY + 5) % 360;
        break;
    case 'C':
        rotY = (rotY - 5) % 360;
        break;


    case 'w':
        posDisco[0][1] = posDisco[0][1] - 0.2;
        break;
    case 's':
        posDisco[0][1] = posDisco[0][1] + 0.2;
        break;
    case 'd':
        posDisco[0][0] = posDisco[0][0] + 0.2;
        break;
    case 'a':
        posDisco[0][0] = posDisco[0][0] - 0.2;
        break;

    case 'Z':
        zoom += 0.1;
        break;
    case 'z':
        zoom -= 0.1;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutTimerFunc(1000 / 60, moverBola, 0);
    glutMainLoop();
    return 0;
}