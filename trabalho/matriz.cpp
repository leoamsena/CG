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
int anguloSino = 0,anguloBadalo = 0;

double ptsMeio[][2] = {{0.1,0.0},{0.2,0.0},{0.1,0.8},{0.2,0.7},{0.1,1.0},{0.5,1.0},{0.1,1.2},{0.5,1.2}};
double ptsBaixo[][2] = {{0.0,0.0},{0.2,0.0},{0.0,0.8},{0.2,0.7},{0.0,1.0},{0.5,1.0},{0.0,3.0},{0.2,3.0},{0.5,3.3},{0.5,3.0}};

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

void desenhaMetadeFaceBaixo(){
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLE_STRIP);
        for(int i=0;i<5;i++)
            glVertex3f(ptsBaixo[i][0], ptsBaixo[i][1], 0.0f);
        quartoDeCirculo(ptsBaixo[4],ptsBaixo[3],ptsBaixo[5],5);
        glVertex3f(ptsBaixo[6][0], ptsBaixo[6][1], 0.0f);
        glVertex3f(ptsBaixo[7][0], ptsBaixo[7][1], 0.0f);
        glVertex3f(ptsBaixo[7][0], ptsBaixo[7][1], 0.0f);
        quartoDeCirculo(ptsBaixo[9],ptsBaixo[7],ptsBaixo[8],5);
    glEnd();
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3f(ptsBaixo[7][0], ptsBaixo[7][1], 0.0f);
        glVertex3f(ptsBaixo[9][0], ptsBaixo[9][1], 0.0f);
        glVertex3f(ptsBaixo[5][0], ptsBaixo[5][1], 0.0f);
    glEnd();
    
    
    
}

void desenhaFaceBaixo(){
    glPushMatrix();
        desenhaMetadeFaceBaixo();
        
    glPopMatrix();

    glPushMatrix();
        glRotatef(180,0.0,1.0,0.0);
        glTranslatef(-1.0,0.0,0.0);
        desenhaMetadeFaceBaixo();
        glEnd();
    glPopMatrix();
}

void desenhaParteBaixo(){
    
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
    glPushMatrix();
        glBegin(GL_QUADS);
            glVertex3f(0.0f, ptsBaixo[6][1], 0.0f);
            glVertex3f(1.0f, ptsBaixo[9][1], 0.0f);
            glVertex3f(1.0f, ptsBaixo[9][1], -1.0f);
            glVertex3f(0.0, ptsBaixo[6][1], -1.0f);
        glEnd();
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
        glRotatef(anguloSino,1.0,0.0,0.0);
        glRotatef(270,1.0,0.0,0.0);
        
        glPushMatrix();
            gluCylinder(gluNewQuadric(),0.15f,0.1f,0.1f,32,32);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0,0.0,0.1);
            gluCylinder(gluNewQuadric(),0.1f,0.1f,0.2f,32,32);
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0,0.0,0.3);
            gluCylinder(gluNewQuadric(),0.1f,0.0f,0.1f,32,32);
        glPopMatrix();

        // badalo
        glPushMatrix();

            glColor3f(0.2,0.09,0.0);
            glTranslatef(0.0,0.0,0.2);
            glRotatef(anguloBadalo,1.0,0.0,0.0);
            glTranslatef(0.0,0.0,-0.3);
            
            //glTranslatef(0.0,0.0,0.6);
            
            gluCylinder(gluNewQuadric(),0.05f,0.05f,0.3f,32,32);
            
            glutSolidSphere(0.06,32,32);
        glPopMatrix();
    glPopMatrix();
}

void desenhaCirculoCompleto(double raio){
    double ptsAux[][2]= {{raio,0.0},{0.0,0.0},{raio,raio}};
    glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
            quartoDeCirculo(ptsAux[0],ptsAux[1],ptsAux[2],100);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glRotatef(180,0.0,1.0,0.0);
        glTranslatef(-0.5,0.0,0.0);
        glBegin(GL_TRIANGLE_STRIP);
            quartoDeCirculo(ptsAux[0],ptsAux[1],ptsAux[2],100);
        glEnd();
    glPopMatrix();


    // baixo relogio
    glPushMatrix();
        glRotatef(180,1.0,0.0,0.0);
        //glTranslatef(0.0,0.5,0.0);
        glPushMatrix();
            glBegin(GL_TRIANGLE_STRIP);
                quartoDeCirculo(ptsAux[0],ptsAux[1],ptsAux[2],100);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glRotatef(180,0.0,1.0,0.0);
            glTranslatef(-0.5,0.0,0.0);
            glBegin(GL_TRIANGLE_STRIP);
                quartoDeCirculo(ptsAux[0],ptsAux[1],ptsAux[2],100);
            glEnd();
        glPopMatrix();
    glPopMatrix();
}

void desenhaRelogio(){
    
    glPushMatrix();
        
        desenhaCirculoCompleto(0.25);
        
        glPushMatrix();
            glTranslatef(0.25,0.0,0.0);
            gluCylinder(gluNewQuadric(),0.25f,0.25f,0.1f,32,32);
        glPopMatrix();
        
        glTranslatef(0.0,0.0,0.1);
        desenhaCirculoCompleto(0.25);
    glPopMatrix();
}

void ilumina(void)
{
    
    GLfloat luzAmbiente[4] = { 0.2,0.2,0.2,1.0 };
    GLfloat luzDifusa[4] = { 0.7,0.7,0.7,1.0 };	   // "cor" 
    GLfloat luzEspecular[4] = { 1.0, 1.0, 1.0, 1.0 };// "brilho" 
    GLfloat posicaoLuz[4] = { -50.0, 50.0, 10.0, 0.0 };

    // Capacidade de brilho do material
    GLfloat especularidade[4] = { 0.0,0.0,0.0,0.0 };
    GLint especMaterial = 10;
    // Habilita o modelo de colorização de Gouraud
    glShadeModel(GL_SMOOTH);

    // Define a refletância do material 
    glMaterialfv(GL_FRONT, GL_SPECULAR, especularidade);
    // Define a concentração do brilho
    glMateriali(GL_FRONT, GL_SHININESS, especMaterial);

    // Ativa o uso da luz ambiente 
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

    // Define os parâmetros da luz de número 0
    glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
    glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
    glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);

    // Habilita a definição da cor do material a partir da cor corrente
    glEnable(GL_COLOR_MATERIAL);
    //Habilita o uso de iluminação
    glEnable(GL_LIGHTING);
    // Habilita a luz de número 0
    glEnable(GL_LIGHT0);
    // Habilita o depth-buffering
    glEnable(GL_DEPTH_TEST);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glColor3f(1.0,0.0,0.0);
    glPushMatrix();
        glTranslatef(-1.0,-2.0,1.0);
        glRotatef(anguloTotal,0.0,1.0,0.0);
        desenhaParteBaixo();
        glPushMatrix();
            glTranslatef(0.0,3.0,0.0);
            desenhaParteMeio();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0,3.0,0.0);
            desenhaParteCima();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.5,3.6,-0.5);
            glColor3f(1.0,1.0,0.0);
            desenhaSino();
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.0,0.0,1.0);
            glTranslatef(0.25,3.0,0.01);
            desenhaRelogio();
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
        case 's':
            if((anguloSino+5)%360<10){
                anguloSino = (anguloSino + 5) %360;
                anguloBadalo = (anguloBadalo - (5+2)) %360;
            }
            break;
        case 'S':
            if((anguloSino+5)%360>-10){
                anguloSino = (anguloSino - 5) %360;
                anguloBadalo = (anguloBadalo + 5 + 2) %360;
            }
            break;
        case 'b':
            anguloBadalo = (anguloBadalo + 5) %360;
            break;
        case 'B':
            anguloBadalo = (anguloBadalo - 5) %360;
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
    ilumina();
    glutMainLoop();
    
    return 0;
}