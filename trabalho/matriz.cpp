/*
 *  Este código é uma modificação de "robo.cpp" com o intuito de realizar os movimentos sozinho.
 *  Foi feito como curiosidade, sendo que 
 */

#include <GL/glut.h>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265359

int anguloTotal = 0;
int aux = 0;

double ptsMeio[][2] = {{0.1,0.0},{0.2,0.0},{0.1,0.8},{0.2,0.7},{0.1,1.0},{0.5,1.0},{0.1,1.2},{0.5,1.2}};

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}
void quartoDeCirculo(double *extremaEsquerda,double *baixo,double *cima,int qtdPts){
    
    for(int i=0;i<=qtdPts;i++){
        double angulo = i*((PI/2) /qtdPts);
        double raio = cima[0] - baixo[0];
        double x = raio - (cos(angulo) * raio);
        x += baixo[0];
        double y = (sin(angulo) * raio);
        y += baixo[1];

        glVertex3f(x, y, 0.0f);
        glVertex3f(extremaEsquerda[0], extremaEsquerda[1], 0.0f);
    }
    glVertex3f(cima[0], cima[1], 0.0f);
}

void desenhaFaceBaixo(){
    double ptsBaixo[][2] = {{0.0,0.0},{0.2,0.0},{0.0,0.8},{0.2,0.7},{0.0,1.0},{0.5,1.0},{0.0,3.0},{0.2,3.0},{0.5,3.3}};
    
    glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
            // lado esquerdo
            
            for(int i=0;i<5;i++)
                glVertex3f(ptsBaixo[i][0], ptsBaixo[i][1], 0.0f);
            quartoDeCirculo(ptsBaixo[4],ptsBaixo[3],ptsBaixo[5],5);
            glVertex3f(ptsBaixo[6][0], ptsBaixo[6][1], 0.0f);
            glVertex3f(ptsBaixo[7][0], ptsBaixo[7][1], 0.0f);
            glVertex3f(ptsBaixo[7][0], ptsBaixo[7][1], 0.0f);
            quartoDeCirculo(ptsBaixo[7],ptsBaixo[7],ptsBaixo[8],5);
            glVertex3f(ptsBaixo[5][0], ptsBaixo[5][1], 0.0f);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        glRotatef(180,0.0,1.0,0.0);
        glTranslatef(-1.0,0.0,0.0);
        glBegin(GL_TRIANGLE_STRIP);
            // lado direito
            
            for(int i=0;i<5;i++)
                glVertex3f(ptsBaixo[i][0], ptsBaixo[i][1], 0.0f);
            quartoDeCirculo(ptsBaixo[4],ptsBaixo[3],ptsBaixo[5],5);
            glVertex3f(ptsBaixo[6][0], ptsBaixo[6][1], 0.0f);
            glVertex3f(ptsBaixo[7][0], ptsBaixo[7][1], 0.0f);
            glVertex3f(ptsBaixo[7][0], ptsBaixo[7][1], 0.0f);
            quartoDeCirculo(ptsBaixo[7],ptsBaixo[7],ptsBaixo[8],5);
            glVertex3f(ptsBaixo[5][0], ptsBaixo[5][1], 0.0f);
        glEnd();
    glPopMatrix();
}

void desenhaParteBaixo(){
    glColor3f(1.0f, 1.0f, 1.0f); // branco
    glPushMatrix();
        desenhaFaceBaixo();
    glPopMatrix();
    glPushMatrix();
        glRotatef(90,0.0,1.0,0.0);
        
        desenhaFaceBaixo();
    glPopMatrix();
    
    glPushMatrix();
        glRotatef(90,0.0,1.0,0.0);
        glTranslatef(0.0,0.0,1.0);
        
        desenhaFaceBaixo();
    glPopMatrix();

    glPushMatrix();
        
        glTranslatef(0.0,0.0,-1.0);
        desenhaFaceBaixo();
    glPopMatrix();
    
}

void desenhaFaceMeio(){  
    glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
            for(int i=0;i<5;i++)
                glVertex3f(ptsMeio[i][0], ptsMeio[i][1], 0.0f);
            quartoDeCirculo(ptsMeio[4],ptsMeio[3],ptsMeio[5],10);
            glVertex3f(ptsMeio[6][0], ptsMeio[6][1], 0.0f);
            glVertex3f(ptsMeio[7][0], ptsMeio[7][1], 0.0f);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glRotatef(180,0.0,1.0,0.0);
        glTranslatef(-1.0,0.0,0.0);
        glBegin(GL_TRIANGLE_STRIP);
            for(int i=0;i<5;i++)
                    glVertex3f(ptsMeio[i][0], ptsMeio[i][1], 0.0f);
                quartoDeCirculo(ptsMeio[4],ptsMeio[3],ptsMeio[5],10);
                glVertex3f(ptsMeio[6][0], ptsMeio[6][1], 0.0f);
                glVertex3f(ptsMeio[7][0], ptsMeio[7][1], 0.0f);
        glEnd();
    glPopMatrix();
}

void desenhaParteMeio(){
   glColor3f(1.0f, 0.0f, 0.0f); // vermelho
    glPushMatrix();
        glTranslatef(0.0,0.0,-0.1);
        desenhaFaceMeio();
    glPopMatrix();
    glPushMatrix();
        glRotatef(90,0.0,1.0,0.0);
        glTranslatef(0.0,0.0,0.1);
        desenhaFaceMeio();
    glPopMatrix();
    
    glPushMatrix();
        glRotatef(90,0.0,1.0,0.0);
        glTranslatef(0.0,0.0,0.9);        
        desenhaFaceMeio();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(0.0,0.0,-0.9);
        desenhaFaceMeio();
    glPopMatrix();

    
}

void desenhaParteCima(){
    glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0.5,ptsMeio[6][1]+1.0,-0.4);
            glVertex3f(ptsMeio[6][0],ptsMeio[6][1],0.0);
            glVertex3f(ptsMeio[6][0]+0.8,ptsMeio[6][1],0.0);
            glVertex3f(ptsMeio[6][0]+0.8,ptsMeio[6][1],-1.0);
            glVertex3f(ptsMeio[6][0],ptsMeio[6][1],-1.0);
            glVertex3f(ptsMeio[6][0],ptsMeio[6][1],0.0);

        glEnd();
    glPopMatrix();
}

void desenhaSino(){
    glPushMatrix();
        glRotatef(270,1.0,0.0,0.0);
        glPushMatrix();
            gluCylinder(gluNewQuadric(),0.15f,0.1f,0.1f,32,32);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0,0.0,0.1);
            gluCylinder(gluNewQuadric(),0.1f,0.1f,0.1f,32,32);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0,0.0,0.2);
            gluCylinder(gluNewQuadric(),0.1f,0.0f,0.1f,32,32);
        glPopMatrix();

        // badalo
        glPushMatrix();
            
            glTranslatef(0.0,0.0,-0.1);
            gluCylinder(gluNewQuadric(),0.05f,0.05f,0.3f,32,32);
            //glTranslatef(0.0,0.0,-0.1);
            glColor3f(1.0,0.0,0.0);
            glutSolidSphere(0.05,32,32);
        glPopMatrix();
    glPopMatrix();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
        glRotatef(anguloTotal,0.0,1.0,0.0);
        desenhaParteBaixo();
        glPushMatrix();
            glTranslatef(0.0,3.0,0.0);
            desenhaParteMeio();
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.0f, 0.0f, 1.0f); // vermelho
            glTranslatef(0.0,3.0,0.0);
            desenhaParteCima();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.5,4,-0.5);
            glColor3f(1.0,0.0,0.0);
            desenhaSino();
        glPopMatrix();
    glPopMatrix();
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
        case 27:
            exit(0);
            break;
        case 'a':
            anguloTotal = (anguloTotal + 5) %360;
            break;
        case 'u':
            aux = (aux + 5) %360;
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
    glutMainLoop();
    return 0;
}