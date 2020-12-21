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
#define EIXO_Z 2
#define EIXO_Y 1
#define EIXO_X 0
#define POSITIVO 1
#define NEGATIVO -1

int anguloTotal = 0,anguloTotalX =0 ;
int anguloSino = 0,anguloBadalo = 0,anguloMinutos =0,anguloHoras=0;
GLfloat positionLuz [] = { 0.0, 0.0, 2.0, 1.0 };

int eixoNorma;
int sinalNorma = POSITIVO;
/* Declarações de funções */
GLfloat* calculaNorma();
void init(void);
void quartoDeCirculo(double *extremaEsquerda,double *baixo,double *cima,int qtdPts);
void desenhaMetadeFaceBaixo();
void desenhaCrucifixo();
void desenhaFaceBaixo();
void desenhaParteBaixo();
void desenhaMetadeJanelaFaceLateral(double xFinal,double yBaixo,double alturaParede,bool comecoMenor);
void desenharFaceLateral(int numeroJanelas,double larguraParede,bool portaNoMeio);
void desenhaFaceMeio();
void desenhaParteMeio();
void desenhaParteCima();
void desenhaRetangulo(double h,double l);
void desenhaSino();
void desenhaCirculoCompleto(double raio);
void desenhaRelogio();
void desenhaTorre();
void desenhaIgreja();
void ilumina(void);
void display(void);
void reshape(int w, int h);
void animacao(int  a);
void keyboard(unsigned char key, int x, int y);
void MouseOptions(int button, int state, int x, int y);
/* FIM das declarações de funções */





double ptsMeio[][2] = {{0.1,0.0},{0.2,0.0},{0.1,0.8},{0.2,0.7},{0.1,1.0},{0.5,1.0},{0.1,1.2},{0.5,1.2}};
double ptsBaixo[][2] = {{0.0,0.0},{0.2,0.0},{0.0,0.8},{0.2,0.7},{0.0,1.0},{0.5,1.0},{0.0,3.0},{0.2,3.0},{0.5,3.3},{0.5,3.0}};
bool rodarAnim = false,sinoPositivo=true;


GLfloat* calculaNorma(){
    static GLfloat norma[] = {0.0,0.0,0.0};
    norma[eixoNorma] = sinalNorma*1.0;
    return norma;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    ilumina();
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
    
    glBegin(GL_TRIANGLE_STRIP);
        glNormal3fv(calculaNorma());
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

void desenhaCrucifixo(){
    glPushMatrix();
        glScalef(1.0,2.5,1.0);
        glutSolidCube(0.15);
    glPopMatrix();
    glPushMatrix();
        glScalef(2.5,1.0,1.0);
        glutSolidCube(0.15);
    glPopMatrix();
}

void desenhaFaceBaixo(){
    
    glPushMatrix();
        desenhaMetadeFaceBaixo();
        
    glPopMatrix();

    glPushMatrix();
        glRotatef(180,0.0,1.0,0.0);
        glTranslatef(-1.0,0.0,0.0);
        sinalNorma = -1*sinalNorma;
        desenhaMetadeFaceBaixo();
        glEnd();
    glPopMatrix();
}

void desenhaParteBaixo(){
    
    glPushMatrix();
        eixoNorma = EIXO_Z;
        sinalNorma = POSITIVO;
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

void desenhaMetadeJanelaFaceLateral(double xFinal,double yBaixo,double alturaParede,bool comecoMenor=false){
    double baixo[]={xFinal - 0.3,yBaixo,0.0f},cima[]={xFinal,alturaParede,0.0f};
    double xInicial = comecoMenor?(baixo[0]-0.2):0.0;
    double extremaEsquerda[] ={xInicial,alturaParede,0.0f};
    

    glBegin(GL_TRIANGLE_STRIP);
        glNormal3fv(calculaNorma());
        glVertex3f(xFinal,0.0f,0.0f); // 1
        glVertex3f(xInicial,0.0f,0.0f); // 2
        glVertex3f(xFinal,yBaixo,0.0f); // 3
        glVertex3f(xInicial,yBaixo,0.0f); //4
        glVertex3f(baixo[0],baixo[1],baixo[2]); //5
        glVertex3f(xInicial,alturaParede,0.0f);//6
        glVertex3f(xInicial,alturaParede,0.0f); //6
        
        quartoDeCirculo(extremaEsquerda,baixo,cima,300);
    glEnd();
    
    
}



void desenharFaceLateral(int numeroJanelas=1,double larguraParede=2.0,bool portaNoMeio=false){
    double  alturaParede = 1.5,alturaJanela = alturaParede/2;

    double xFinal,yBaixo;
    

    xFinal = larguraParede/(numeroJanelas+1);
    yBaixo = alturaParede - alturaJanela;
    int portaAPartirDaJanela = numeroJanelas>1?(numeroJanelas / 2):-1; // so tem porta no meio se numeroJanelas > 1
    portaAPartirDaJanela--;
    glPushMatrix();

        for(int i=0;i<numeroJanelas;i++){
            
            glPushMatrix();
                
                desenhaMetadeJanelaFaceLateral(xFinal,yBaixo,alturaParede,portaNoMeio && i-1==portaAPartirDaJanela);
                glTranslatef(xFinal*2,0.0,0.0);
                glRotatef(180,0.0,1.0,0.0);   
                sinalNorma = -1*sinalNorma;
                desenhaMetadeJanelaFaceLateral(xFinal,yBaixo,alturaParede,portaNoMeio && i == portaAPartirDaJanela);
                sinalNorma = -1*sinalNorma;
            glPopMatrix();
            glTranslatef(xFinal*2,0.0,0.0);
        }
    glPopMatrix();
}

void desenhaFaceMeio(){  
    glPushMatrix();
        glBegin(GL_TRIANGLE_STRIP);
            glNormal3fv(calculaNorma());
            for(int i=0;i<5;i++)
                glVertex3f(ptsMeio[i][0], ptsMeio[i][1], 0.0f);
            quartoDeCirculo(ptsMeio[4],ptsMeio[3],ptsMeio[5],10);
            glVertex3f(ptsMeio[6][0], ptsMeio[6][1], 0.0f);
            glVertex3f(ptsMeio[7][0], ptsMeio[7][1], 0.0f);
        glEnd();
    glPopMatrix();
    sinalNorma = -1*sinalNorma;
    
    glPushMatrix();
        glRotatef(180,0.0,1.0,0.0);
        glTranslatef(-1.0,0.0,0.0);
        glBegin(GL_TRIANGLE_STRIP);
            glNormal3fv(calculaNorma());
            for(int i=0;i<5;i++)
                    glVertex3f(ptsMeio[i][0], ptsMeio[i][1], 0.0f);
                quartoDeCirculo(ptsMeio[4],ptsMeio[3],ptsMeio[5],10);
                glVertex3f(ptsMeio[6][0], ptsMeio[6][1], 0.0f);
                glVertex3f(ptsMeio[7][0], ptsMeio[7][1], 0.0f);
        glEnd();
    glPopMatrix();
    sinalNorma = -1*sinalNorma;
}

void desenhaParteMeio(){
    eixoNorma = EIXO_Z;
    sinalNorma = POSITIVO;
   
    glPushMatrix();
        glTranslatef(0.0,0.0,-0.1);
        desenhaFaceMeio();
    glPopMatrix();
    sinalNorma = NEGATIVO;
    glPushMatrix();
        glRotatef(90,0.0,1.0,0.0);
        glTranslatef(0.0,0.0,0.1);
        desenhaFaceMeio();
    glPopMatrix();
    sinalNorma = POSITIVO;
    glPushMatrix();
        glRotatef(90,0.0,1.0,0.0);
        glTranslatef(0.0,0.0,0.9);        
        desenhaFaceMeio();
    glPopMatrix();

    sinalNorma = NEGATIVO;
    glPushMatrix();

        glTranslatef(0.0,0.0,-0.9);
        desenhaFaceMeio();
    glPopMatrix();

    
}

void desenhaParteCima(){
    glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);   
            
            glVertex3f(0.5,ptsMeio[6][1]+1.0,-0.4);//ponta
            
            glNormal3f(0.0f,1/sqrt(2),1/sqrt(2));
            glVertex3f(ptsMeio[6][0],ptsMeio[6][1],0.0); // 1
            glVertex3f(ptsMeio[6][0]+0.8,ptsMeio[6][1],0.0);//2
            glNormal3f(1/sqrt(2),1/sqrt(2),0.0f);
            glVertex3f(ptsMeio[6][0]+0.8,ptsMeio[6][1],-1.0);//3
            glNormal3f(0.0f,-1/sqrt(2),-1/sqrt(2));
            glVertex3f(ptsMeio[6][0],ptsMeio[6][1],-1.0);//4
            glNormal3f(-1/sqrt(2),-1/sqrt(2),0.0f);
            glVertex3f(ptsMeio[6][0],ptsMeio[6][1],0.0); // 1

        glEnd();
    glPopMatrix();
}

void desenhaRetangulo(double h,double l){
    eixoNorma = EIXO_Z;
    
    glBegin(GL_QUADS);
        glNormal3fv(calculaNorma());
        glVertex3f(0.0,0.0,0.0);
        glVertex3f(h,0.0,0.0);
        glVertex3f(h,l,0.0);
        glVertex3f(0.0,l,0.0);
    glEnd();
}

void desenhaSino(){
    glColor3f(1.0,1.0,0.0);
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
        sinalNorma = POSITIVO;
        glBegin(GL_TRIANGLE_STRIP);
            glNormal3fv(calculaNorma());
            quartoDeCirculo(ptsAux[0],ptsAux[1],ptsAux[2],100);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glRotatef(180,0.0,1.0,0.0);
        glTranslatef(-0.5,0.0,0.0);
        sinalNorma = NEGATIVO;
        glBegin(GL_TRIANGLE_STRIP);
            glNormal3fv(calculaNorma());
            quartoDeCirculo(ptsAux[0],ptsAux[1],ptsAux[2],100);
        glEnd();
    glPopMatrix();


    // baixo relogio
    glPushMatrix();
        glRotatef(180,1.0,0.0,0.0);
        //glTranslatef(0.0,0.5,0.0);
        sinalNorma = NEGATIVO;
        glPushMatrix();
            glBegin(GL_TRIANGLE_STRIP);
                glNormal3fv(calculaNorma());
                
                quartoDeCirculo(ptsAux[0],ptsAux[1],ptsAux[2],100);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glRotatef(180,0.0,1.0,0.0);
            glTranslatef(-0.5,0.0,0.0);
            sinalNorma = POSITIVO;
            glBegin(GL_TRIANGLE_STRIP);
                glNormal3fv(calculaNorma());
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
        
        glTranslatef(0.25,0.0,0.01);
        glPushMatrix();
            glRotatef(anguloMinutos,0.0,0.0,1.0);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_QUADS);
                glVertex3f(0.0,0.0,0.0);
                glVertex3f(0.03,0.15,0.0);
                glVertex3f(0.0,0.2,0.0);
                glVertex3f(-0.03,0.15,0.0);
            glEnd();
        glPopMatrix();
        glPushMatrix();
            glRotatef(anguloHoras,0.0,0.0,1.0);
            glColor3f(1.0,1.0,1.0);
            glBegin(GL_QUADS);
                glVertex3f(0.0,0.0,0.0);
                glVertex3f(0.03,0.10,0.0);
                glVertex3f(0.0,0.15,0.0);
                glVertex3f(-0.03,0.10,0.0);
            glEnd();
        glPopMatrix();

    glPopMatrix();
}
void desenhaIgreja(){
    glPushMatrix(); // igreja em si (paralelepipedo)
            eixoNorma = EIXO_Z;
            sinalNorma = POSITIVO;
            glTranslatef(-3.5,0.0,0.0);
            glTranslatef(2.0,0.0,-1.0);
            
            desenharFaceLateral(2,3,true); // face frontal
            glTranslatef(4.0,0.0,0.0);
           

            
            sinalNorma = POSITIVO;
            
            glRotatef(90,0.0,1.0,0.0);
            desenharFaceLateral(2,3); // face direita
            
            glTranslatef(0.0,0.0,-4);
            sinalNorma = NEGATIVO;
            desenharFaceLateral(2,3); // face esquerda

            glRotatef(-90,0.0,1.0,0.0);
            glTranslatef(0.0,0.0,-4);
            desenharFaceLateral(1,4); // face traseira
            
            sinalNorma = POSITIVO;

            glColor3f(0.6039,0.6039,0.1960);
            
            glRotatef(90,1.0,0.0,0.0);
            desenhaRetangulo(4.0,4.0);
            sinalNorma = NEGATIVO;
            
            glTranslatef(0.0,0.0,-1.5);
            desenhaRetangulo(4.0,4.0);
        glPopMatrix();
}
void desenhaTorre(){
    desenhaParteBaixo();
        glPushMatrix();
            glTranslatef(0.0,3.0,0.0);
            desenhaParteMeio();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.0,3.0,0.0);
            desenhaParteCima();
            glTranslatef(0.5,2.2,-0.4);
            desenhaCrucifixo();
        glPopMatrix();
        glPushMatrix();
            glTranslatef(0.5,3.6,-0.5);
            
            desenhaSino();
        glPopMatrix();
        glPushMatrix();
            glColor3f(0.0,0.0,1.0);
            glTranslatef(0.25,3.0,0.01);
            desenhaRelogio();
        glPopMatrix();
}

void ilumina(void)
{
    
    GLfloat difusa[] = { 1.0, 1.0, 1.0, 1.0};
    
    glShadeModel(GL_FLAT); // especifica o método de iluminação constrante
    glColorMaterial(GL_FRONT_AND_BACK,GL_DIFFUSE); // determina que a reflexão aconteça para as faces de frente e de trás dos objetos
    
    glEnable(GL_COLOR_MATERIAL); // habilita as colorações

    glLightfv (GL_LIGHT0, GL_DIFFUSE, difusa);  // cria luz difusa
    
    glLightfv (GL_LIGHT0, GL_POSITION,positionLuz );  // define que a luz é direcional


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    
    glColor3f(0.6039,0.8039,0.1960);

    

    glPushMatrix();
        
        glRotatef(anguloTotal,0.0,1.0,0.0); // y
        glRotatef(anguloTotalX,1.0,0.0,0.0); // x
        glTranslatef(0.0,-2.0,2.0);

        desenhaTorre();
        glColor3f(0.6039,0.6039,0.1960);
        desenhaIgreja();
    glPopMatrix();
    glutSwapBuffers();
}


void reshape(int w, int h)
{
    glViewport(0, 0, static_cast<GLsizei> (w), static_cast<GLsizei> (h));
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0, static_cast<GLfloat> (w) / static_cast<GLfloat> (h), 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
    

}

void animacao(int  a){
    if(!rodarAnim) return;
    glutPostRedisplay();
    anguloMinutos = (anguloMinutos + 1) % 360;
    if(anguloMinutos%72==0)
    anguloHoras = ((anguloHoras+6)%360);
    if(sinoPositivo){
        if((anguloSino+1)%360<8){
            anguloSino = (anguloSino + 1) %360;
            anguloBadalo = (anguloBadalo - (1+2)) %360;
        }else
            sinoPositivo = !sinoPositivo;
    }else{
        if((anguloSino-1)%360>-8){
            anguloSino = (anguloSino - 1) %360;
            anguloBadalo = (anguloBadalo + (1+2)) %360;
        }else
            sinoPositivo = !sinoPositivo;
        
    }
    
    
    
    glutTimerFunc(1000 / 60, animacao, 0);
}
void keyboard(unsigned char key, int x, int y)
{

    switch (key)
    {
        case 27:
            exit(0);
            break;
        case 'a':
            rodarAnim =!rodarAnim;
            animacao(0);
            break;
       
        case 's':
            if((anguloSino+1)%360<8){
                anguloSino = (anguloSino + 1) %360;
                anguloBadalo = (anguloBadalo - (1+2)) %360;
            }
            break;
        case 'S':
            if((anguloSino-1)%360>-8){
                anguloSino = (anguloSino - 1) %360;
                anguloBadalo = (anguloBadalo + 1 + 2) %360;
            }
            break;
        case 'm':
            anguloMinutos = (anguloMinutos + 5) %360;
            break;
        case 'h':
            anguloHoras = (anguloHoras + 5) %360;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
void MouseOptions(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
  {
    anguloTotal = (anguloTotal + 5)%360;
  }else if(button == GLUT_RIGHT_BUTTON){
    anguloTotalX = (anguloTotalX+5)%360;
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
    glutMouseFunc(MouseOptions);
    glutMainLoop();
    
    return 0;
}