#include <GL/glut.h>

GLfloat horzangle = -45.0, vertangle = 30.0;

void RenderScene(void)
{
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -3.0f);
  glRotatef(vertangle, 1.0f, 0.0f, 0.0f);
  glRotatef(horzangle, 0.0f, 1.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  //linhas dos eixos
  glBegin(GL_LINES);
  glColor3f(0.0f, 0.0f, 1.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.7f, 0.0f, 0.0f);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.5f, 0.0f);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.7f);
  glEnd();

  // face do chão
  glBegin(GL_QUAD_STRIP);
  glColor3f(0.5f, 0.5f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.4f);
  glVertex3f(0.4f, 0.0f, 0.4f);
  glEnd();

  // face de tras (vermelha)
  glBegin(GL_POLYGON);
  glColor3f(1.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glVertex3f(0.2f, 0.3f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.0f, 0.0f);
  glEnd();

  // face do lado (azul)
  glBegin(GL_QUADS);

  glColor3f(0.0f, 0.0f, 1.0f);

  glVertex3f(0.0f, 0.0f, 0.0f);     // 1
  glVertex3f(0.0f, 0.075f, 0.175f); // 2
  glVertex3f(0.0f, 0.125f, 0.175f); // 3
  glVertex3f(0.0f, 0.2f, 0.0f);     // 4

  glVertex3f(0.0f, 0.2f, 0.4f);     // 5
  glVertex3f(0.0f, 0.125f, 0.225f); // 6
  glVertex3f(0.0f, 0.125f, 0.175f); // 4
  glVertex3f(0.0f, 0.2f, 0.0f);     // 3

  glVertex3f(0.0f, 0.2f, 0.4f);     // 5
  glVertex3f(0.0f, 0.125f, 0.225f); // 6
  glVertex3f(0.0f, 0.075f, 0.225f); // 7
  glVertex3f(0.0f, 0.0f, 0.4f);     // 8

  glVertex3f(0.0f, 0.075f, 0.225f); // 7
  glVertex3f(0.0f, 0.0f, 0.4f);     // 8
  glVertex3f(0.0f, 0.0f, 0.0f);     // 1
  glVertex3f(0.0f, 0.075f, 0.175f); // 2

  glEnd();
  // face do teto
  glBegin(GL_QUAD_STRIP);
  glColor3f(0.0f, 1.0f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.0f);
  glVertex3f(0.0f, 0.2f, 0.4f);
  glVertex3f(0.2f, 0.3f, 0.0f);
  glVertex3f(0.2f, 0.3f, 0.4f);
  glVertex3f(0.4f, 0.2f, 0.0f);
  glVertex3f(0.4f, 0.2f, 0.4f);
  glEnd();

  // face do lado direito (branco)
  glBegin(GL_QUADS);

  glColor3f(1.0f, 1.0f, 1.0f);

  glVertex3f(0.4f, 0.0f, 0.0f);     // 1
  glVertex3f(0.4f, 0.075f, 0.175f); // 2
  glVertex3f(0.4f, 0.125f, 0.175f); // 3
  glVertex3f(0.4f, 0.2f, 0.0f);     // 4

  glVertex3f(0.4f, 0.2f, 0.4f);     // 5
  glVertex3f(0.4f, 0.125f, 0.225f); // 6
  glVertex3f(0.4f, 0.125f, 0.175f); // 4
  glVertex3f(0.4f, 0.2f, 0.0f);     // 3

  glVertex3f(0.4f, 0.2f, 0.4f);     // 5
  glVertex3f(0.4f, 0.125f, 0.225f); // 6
  glVertex3f(0.4f, 0.075f, 0.225f); // 7
  glVertex3f(0.4f, 0.0f, 0.4f);     // 8

  glVertex3f(0.4f, 0.075f, 0.225f); // 7
  glVertex3f(0.4f, 0.0f, 0.4f);     // 8
  glVertex3f(0.4f, 0.0f, 0.0f);     // 1
  glVertex3f(0.4f, 0.075f, 0.175f); // 2

  glEnd();

  // face da frente (rosa)
  glBegin(GL_TRIANGLE_STRIP);
  glColor3f(1.0f, 0.0f, 0.4f);
  glVertex3f(0.10f, 0.0f, 0.4f);  // 9
  glVertex3f(0.0f, 0.0f, 0.4f);   // 1
  glVertex3f(0.10f, 0.15f, 0.4f); // 8
  glVertex3f(0.0f, 0.2f, 0.4f);   // 2
  glVertex3f(0.20f, 0.15f, 0.4f); // 7
  glVertex3f(0.2f, 0.3f, 0.4f);   // 3
  glVertex3f(0.4f, 0.2f, 0.4f);   // 4
  glVertex3f(0.20f, 0.0f, 0.4f);  // 6
  glVertex3f(0.4f, 0.0f, 0.4f);   // 5
  glEnd();

  glFlush();
  glutSwapBuffers();
}
void MouseOptions(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON)
  {
    if (state == GLUT_UP)
    {
      vertangle += 15;
      horzangle += 15;
      RenderScene();
    }
  }

  if (button == GLUT_RIGHT_BUTTON)
  {
    if (state == GLUT_UP)
    {
      vertangle -= 15;
      horzangle -= 15;
      RenderScene();
    }
  }

  glutPostRedisplay();
}

void ChangeSize(GLsizei width, GLsizei height)
{
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(30.0, width / height, 1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0.0f, 0.0f, -3.0f);
  glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
  glRotatef(-45, 0.0f, 1.0f, 0.0f);
}
void KeyboardOptions(int key, int x, int y)
{
  switch (key)
  {
  case GLUT_KEY_UP:
    vertangle -= 5;
    break;
  case GLUT_KEY_DOWN:
    vertangle += 5;
    break;
  case GLUT_KEY_LEFT:
    horzangle -= 5;
    break;
  case GLUT_KEY_RIGHT:
    horzangle += 5;
    break;
  default:
    return;
  }
  RenderScene();
  glutPostRedisplay();
}

int main(int argc, char *argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("OpenGL - Casinha");
  glutDisplayFunc(RenderScene);
  glutReshapeFunc(ChangeSize);
  glutMouseFunc(MouseOptions);
  glutSpecialFunc(KeyboardOptions);
  glutMainLoop();
  return 0;
}
