#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include <iostream>
#include <cmath>
#define PI 3.1415926535898

using namespace std;

void quadrado(GLfloat centroX, GLfloat centroY, GLfloat tam = 0.25, GLfloat fatorX = 0, GLfloat fatorY = 0)
{

    glBegin(GL_LINE_LOOP);

    glVertex2f(centroX + tam + fatorX, centroY + tam + fatorY);
    glVertex2f(centroX - tam - fatorX, centroY + tam + fatorY);
    glVertex2f(centroX - tam - fatorX, centroY - tam - fatorY);
    glVertex2f(centroX + tam + fatorX, centroY - tam - fatorY);
    glEnd();
}
void trapezio(GLfloat centroX, GLfloat centroY, GLfloat fatorBaseMenor, GLfloat tam = 0.25)
{

    glBegin(GL_LINE_LOOP);

    glVertex2f(centroX + tam, centroY + tam);
    glVertex2f(centroX - tam, centroY + tam);
    glVertex2f(centroX - tam + fatorBaseMenor, centroY - tam);
    glVertex2f(centroX + tam - fatorBaseMenor, centroY - tam);
    glEnd();
}
void circulo(GLfloat centroX, GLfloat centroY, GLfloat raio, int precisao = 100)
{
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < precisao; i++)
    {
        GLfloat angulo = 2 * PI * i / precisao;
        GLfloat x_comp = raio * cosf(angulo);
        GLfloat y_comp = raio * sinf(angulo);
        glVertex2f(x_comp + centroX, y_comp + centroY);
    }
    glEnd();
}
void reta(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void pia()
{
    quadrado(0.5, 0.5, 0.2, 0.1);
    quadrado(0.5, 0.5, 0.15, 0.1);
    circulo(0.5, 0.6, 0.02);
    quadrado(0.5, 0.675, 0.01, 0.1);
}
void vaso()
{
    quadrado(-0.5, 0.75, 0.05, 0.15);
    trapezio(-0.5, 0.50, 0.05, 0.20);
}
void espelho()
{
    quadrado(0.5, 0.75, 0.01, 0.4);
}
void armario()
{
    quadrado(1.2, 0, 0.15);
}
void banheira()
{
    quadrado(-0.75, -0.75, 0.20, 0.4);
    quadrado(-0.75, -0.75, 0.15, 0.4);
    circulo(-0.25, -0.75, 0.015);
}
void chuveiro()
{
    quadrado(0.75, -0.75, 0.20, 0.35);
    quadrado(0.75, -0.75, 0.15, 0.35);
    circulo(0.75, -0.75, 0.025);
    reta(1.25, -0.9, 0.80, -0.8);
    reta(1.25, -0.6, 0.80, -0.7);
    reta(0.25, -0.6, 0.7, -0.7);
    reta(0.25, -0.9, 0.7, -0.8);
}

void display()
{

    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5.0);

    pia();
    vaso();
    espelho();
    armario();
    chuveiro();
    banheira();

    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Banheiro!");
    glutInitWindowSize(520, 520);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, -1.0, 1.0);
    glutMainLoop();
    return 0;
}