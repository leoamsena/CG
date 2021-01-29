
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <iostream>
using namespace std;

list<float> lista;
bool parado = false;

void novaLinha(int n);

void init(void)
{
   GLfloat values[2];
   glGetFloatv (GL_LINE_WIDTH_GRANULARITY, values);
   
   glGetFloatv (GL_LINE_WIDTH_RANGE, values);
   

   glEnable (GL_LINE_SMOOTH);
   glEnable (GL_BLEND);
   glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glHint (GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
   glLineWidth (1.5);

   glClearColor(0.0, 0.0, 0.0, 0.0);
   novaLinha(0);
}   


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 1.0, 0.0);
    glPushMatrix();

    float LO = -1.0;
    float HI = 1.0;
    float numbers[4];
    for(int i=0;i<4;i++)
        lista.push_back( LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO))));
    
    
    for(list<float>::iterator it = lista.begin(); it!=lista.end();){
        float p1 = *it;
        float p2 = *(++it);
        float p3 = *(++it);
        float p4 = *(++it);
        ++it;
        glBegin (GL_LINES);
            glVertex2f (p1,p2);
            glVertex2f (p3,p4);
        glEnd ();
    }
    glPopMatrix();
   
    
   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h) 
      gluOrtho2D (-1.0, 1.0, 
         -1.0*(GLfloat)h/(GLfloat)w, 1.0*(GLfloat)h/(GLfloat)w);
   else 
      gluOrtho2D (-1.0*(GLfloat)w/(GLfloat)h, 
         1.0*(GLfloat)w/(GLfloat)h, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void novaLinha(int n){
    glutPostRedisplay();
    if(!parado)
    glutTimerFunc(1000, novaLinha, 0);

}

void keyboard(unsigned char key, int x, int y)
{
    //lista.clear();
    parado=!parado;
    
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (200, 200);
   glutCreateWindow (argv[0]);
   init();
   glutReshapeFunc (reshape);
   glutKeyboardFunc (keyboard);
   
   glutDisplayFunc (display);
   
   glutMainLoop();
   return 0;
}