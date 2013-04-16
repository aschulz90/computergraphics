#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0;

void init(void) 
{
   glClearColor (1.0, 1.0, 1.0, 1.0);
}


void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
   glColor3f(0,0,0);
   glLoadIdentity();
   gluLookAt( 0,0,10, 0,0,0, 0,1,0);

   glRotatef ((GLfloat) -shoulder, 0.0, 0.0, 1.0);

   glPushMatrix();
      glTranslatef (1.0, 0.0, 0.0);
      glScalef (2.0, 0.4, 1.0);
      glutWireCube (1.0);
   glPopMatrix();

   glTranslatef (2.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);

   glTranslatef (0.75, 0.0, 0.0);
   glScalef (1.5, 0.4, 1.0);
   glutWireCube (1.0);
   glFlush();

}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glOrtho(-5.0, 5.0, -5.0, 5.0, -100.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 's':
         shoulder += 5;
         glutPostRedisplay();
         break;
      case 'S':
         shoulder -= 5;
         glutPostRedisplay();
         break;
      case 'e':
         elbow += 5;
         glutPostRedisplay();
         break;
      case 'E':
         elbow -= 5;
         glutPostRedisplay();
         break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
