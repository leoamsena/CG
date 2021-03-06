/*
 *  Este código é uma modificação de "robo.cpp" com o intuito de realizar os movimentos sozinho.
 *  Foi feito como curiosidade, sendo que 
 */

#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
using namespace std;

int shoulder = 0, elbow = 0, posX = 0, braco2 = 0, falange1 = 0, falange2 = 0, falange3 = 0, falange4 = 0, bolinha = 0;
int parteAnim = 1;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef((GLfloat)posX, 0.0, 1.0, 0.0);
    //TRANSFORMAÇÕES NO BONECO TODO

    glPushMatrix();
    glScalef(1.0, 2.0, 1.0);
    glTranslatef(-1.0, 0.0, 0.0);
    glutWireCube(1.0); // corpo
    glPopMatrix();

    glPushMatrix();

    glTranslatef(-1.0, 1.3, 0.0);
    glutWireSphere(0.8, 20, 16); // cabeça
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0.0, 0.0);
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.2, 0.4, 1.0);
    glutWireCube(1.0); // ombro
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.2, 0.4, 1.0);
    glutWireCube(1.0); // braço 1
    glPopMatrix();

    glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)braco2, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.2, 0.4, 1.0);
    glutWireCube(1.0); // braço 1
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)falange1, 0.0, 0.0, 1.0);
    glTranslatef(0.4, -0.2, 0.0);
    glPushMatrix();
    glScalef(1.2, 0.4, 1.0);
    glutWireCube(0.5); // braço 1
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)falange2, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.2, 0.4, 1.0);
    glutWireCube(0.5); // braço 1
    glPopMatrix();

    glPopMatrix();

    // segundo dedo

    glPushMatrix();
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)falange3, 0.0, 0.0, 1.0);
    glTranslatef(0.4, 0.2, 0.0);
    glPushMatrix();
    glScalef(1.2, 0.4, 1.0);
    glutWireCube(0.5); // braço 1
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);
    glRotatef((GLfloat)falange4, 0.0, 0.0, 1.0);
    glTranslatef(0.1, 0.0, 0.0);
    glPushMatrix();
    glScalef(1.2, 0.4, 1.0);
    glutWireCube(0.5); // braço 1
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    //glTranslatef(1.0, 0.0, 0.0);
    glRotatef((GLfloat)bolinha, 0.0, 0.0, 1.0);
    glTranslatef(3.0, -2.0, 0.0);
    glutSolidSphere(0.3, 15, 8);
    glPopMatrix();

    glPopMatrix(); // corpo todo

    // bolinha

    glutSwapBuffers();
}

void move(int parte)
{
    int sinal = (parte < 0) ? -1 : 1;
    int auxParte = parte * sinal;
    int tam = 8;

    int *vars[] = {0, &shoulder,
                   &elbow,
                   &braco2,
                   &falange1,
                   &falange2,
                   &falange3,
                   &falange4

    };
    if (auxParte < tam)
    {
        *vars[auxParte] = ((*vars[auxParte]) + (1 * sinal)) % 360;
        glutPostRedisplay();
        if (parteAnim == 1)
        {
            if (*vars[4] > -60)
                glutTimerFunc(1000 / 60, move, -4);
            else if (*vars[6] < 60)
                glutTimerFunc(1000 / 60, move, 6);
            else if (*vars[1] > -50)
                glutTimerFunc(1000 / 60, move, -1);
            else if (*vars[2] < 20)
                glutTimerFunc(1000 / 60, move, 2);
            else if (*vars[3] < 10)
                glutTimerFunc(1000 / 60, move, 3);
            else if (*vars[5] < 50)
                glutTimerFunc(1000 / 60, move, 5);
            else if (*vars[7] > -50)
                glutTimerFunc(1000 / 60, move, -7);
            else
            {
                glutTimerFunc(1000 / 60, move, 4);
                parteAnim = 2;
            }
        }
        else if (parteAnim == 2)
        {
            if (*vars[4] < -10)
                glutTimerFunc(1000 / 60, move, 4);
            else if (*vars[6] > 20)
                glutTimerFunc(1000 / 60, move, -6);
            else if (*vars[1] < -30)
            {
                bolinha = (bolinha + 1) % 360;
                glutTimerFunc(1000 / 60, move, 1);
            }
        }
    }
}

void animacao()
{
    /*bolinha = 0;
    braco2 = 0;
    falange1 = 0;
    falange2 = 0;
    falange3 = 0;
    falange4 = 0;
    shoulder = 0;
    elbow = 0;*/
    glutTimerFunc(1000 / 60, move, -4);
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {
    case 's':
        shoulder = (shoulder + 5) % 360;
        glutPostRedisplay();
        break;
    case 'S':
        shoulder = (shoulder - 5) % 360;
        glutPostRedisplay();
        break;
    case 'e':
        elbow = (elbow + 5) % 360;
        glutPostRedisplay();
        break;
    case 'E':
        elbow = (elbow - 5) % 360;
        glutPostRedisplay();
        break;
    case 'b':
        braco2 = (braco2 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'B':
        braco2 = (braco2 - 5) % 360;
        glutPostRedisplay();
        break;
    case 27:
        exit(0);
        break;
    case 'd':

        posX = (posX + 5) % 360;
        glutPostRedisplay();
        break;
    case 'a':
        posX = (posX - 5) % 360;
        glutPostRedisplay();
        break;
    case 'p':
        falange1 = (falange1 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'P':
        falange1 = (falange1 - 5) % 360;
        glutPostRedisplay();
        break;
    case 'o':
        falange2 = (falange2 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'O':
        falange2 = (falange2 - 5) % 360;
        glutPostRedisplay();
        break;

    case 'i':
        falange3 = (falange3 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'I':
        falange3 = (falange3 - 5) % 360;
        glutPostRedisplay();
        break;
    case 'u':
        falange4 = (falange4 + 5) % 360;
        glutPostRedisplay();
        break;
    case 'U':
        falange4 = (falange4 - 5) % 360;
        glutPostRedisplay();
        break;
    case ' ':
        animacao();
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}