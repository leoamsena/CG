/*
 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED 
 * Permission to use, copy, modify, and distribute this software for 
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that 
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission. 
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 * US Government Users Restricted Rights 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

/*
 * robot.c
 * This program shows how to composite modeling transformations
 * to draw translated and rotated hierarchical models.
 * Interaction:  pressing the s and e keys (shoulder and elbow)
 * alters the rotation of the robot arm.
 */
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
using namespace std;

static int shoulder = 0, elbow = 0, posX = 0, braco2 = 0, falange1 = 0, falange2 = 0, falange3 = 0, falange4 = 0;
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}

void defineIluminacao()
{
    // Define os parâmetros através de vetores RGBA - o último valor deve ser
    // sempre 1.0f (transparência, não usada neste exemplo)
    float luzAmbiente[4] = {0.2f, 0.2f, 0.2f, 1.0f};
    float luzDifusa[4] = {0.7f, 0.7f, 0.7f, 1.0f};
    float luzEspecular[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float posicaoLuz[4] = {10.0f, 10.0f, 0.0f, 1.0f};

    // Ativa o uso da luz ambiente
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);


    

    // Brilho do material
    float especularidade[] = {1.0f, 1.0f, 1.0f, 1.0f};
    int especMaterial = 128;

    // Define a reflectância do material
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);

    // Define a concentração do brilho
    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);
}

void display(void)
{
    defineIluminacao();
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1.0,0.0,1.0);
        glRotatef((GLfloat)posX, 0.0, 1.0, 0.0);
        //TRANSFORMAÇÕES NO BONECO TODO
        glPushMatrix();
            glScalef(1.0, 2.0, 1.0);
            glTranslatef(-1.0, 0.0, 0.0);
            glutSolidCube(1.0); // corpo
            
        glPopMatrix();

        glPushMatrix();
            glTranslatef(-1.0, 1.3, 0.0);
            glutSolidSphere(0.8, 20, 16); // cabeça
        glPopMatrix();

        glPushMatrix();

            glTranslatef(-0.5, 0.0, 0.0);
            glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
            glTranslatef(0.1, 0.0, 0.0);
            glPushMatrix();
                glScalef(1.2, 0.4, 1.0);
                glutSolidCube(1.0); // ombro
            glPopMatrix();

            glTranslatef(1.0, 0.0, 0.0);
            glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
            glTranslatef(0.1, 0.0, 0.0);
            glPushMatrix();
                glScalef(1.2, 0.4, 1.0);
                glutSolidCube(1.0); // braço 1
            glPopMatrix();

            glTranslatef(1.0, 0.0, 0.0);
            glRotatef((GLfloat)braco2, 0.0, 0.0, 1.0);
            glTranslatef(0.1, 0.0, 0.0);
            glPushMatrix();
                glScalef(1.2, 0.4, 1.0);
                glutSolidCube(1.0); // braço 1
            glPopMatrix();
            glColor3f(1.0, 0.0, 0.0);
            glPushMatrix();
                
                glTranslatef(0.5, 0.0, 0.0);
                glRotatef((GLfloat)falange1, 0.0, 0.0, 1.0);
                glTranslatef(0.4, -0.2, 0.0);
                glPushMatrix();
                    glScalef(1.2, 0.4, 1.0);
                    glutSolidCube(0.5); // falange 1
                glPopMatrix();

                glTranslatef(0.5, 0.0, 0.0);
                glRotatef((GLfloat)falange2, 0.0, 0.0, 1.0);
                glTranslatef(0.1, 0.0, 0.0);
                glPushMatrix();
                    glScalef(1.2, 0.4, 1.0);
                    glutSolidCube(0.5); // falange 2
                glPopMatrix();

                glPopMatrix();

                // segundo dedo
                glColor3f(1.0, 0.0, 0.5);
                glPushMatrix();
                
                glTranslatef(0.5, 0.0, 0.0);
                glRotatef((GLfloat)falange3, 0.0, 0.0, 1.0);
                glTranslatef(0.4, 0.2, 0.0);
                glPushMatrix();
                    glScalef(1.2, 0.4, 1.0);
                    glutSolidCube(0.5); // falange 3
                glPopMatrix();

                glTranslatef(0.5, 0.0, 0.0);
                glRotatef((GLfloat)falange4, 0.0, 0.0, 1.0);
                glTranslatef(0.1, 0.0, 0.0);
                glPushMatrix();
                    glScalef(1.2, 0.4, 1.0);
                    glutSolidCube(0.5); // falange 4
                glPopMatrix();

            glPopMatrix();
        glPopMatrix();
    glPopMatrix(); // corpo todo
    glutSwapBuffers();
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