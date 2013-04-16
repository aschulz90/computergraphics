#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

GLfloat alphay, alphax = 0.0;
GLfloat accx, accy = 0.01;

void display(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glLoadIdentity();

   //glTranslatef(0.5, 0.5, 0.5);
   glRotatef(alphay, 0, 1.0, 0);
   glRotatef(alphax, 1.0, 0, 0);
   glTranslatef(-0.5, -0.5, -0.5);

   glBegin(GL_QUADS);
   glColor3f(1.0, 0, 0); // Rot - Vorne
   glVertex3i(0, 0, 0);
   glVertex3i(1, 0, 0);
   glVertex3i(1, 1, 0);
   glVertex3i(0, 1, 0);
   
   glColor3f(0, 1.0, 0); //Grün - Links
   glVertex3i(0, 0, 0);
   glVertex3i(0, 0, 1);
   glVertex3i(0, 1, 1);
   glVertex3i(0, 1, 0);
   
   glColor3f(0, 0, 1.0); //Blau - Unten
   glVertex3i(0, 0, 0);
   glVertex3i(0, 0, 1);
   glVertex3i(1, 0, 1);
   glVertex3i(1, 0, 0);
   
   glColor3f(0, 1.0, 1.0); //Cyan - Oben
   glVertex3i(0, 1, 0);
   glVertex3i(0, 1, 1);
   glVertex3i(1, 1, 1);
   glVertex3i(1, 1, 0);
   
   glColor3f(1.0, 0, 1.0); //Magenta - Hinten
   glVertex3i(0, 0, 1);
   glVertex3i(1, 0, 1);
   glVertex3i(1, 1, 1);
   glVertex3i(0, 1, 1);
   
   glColor3f(1.0, 1.0, 0); //Gelb - Rechts
   glVertex3i(1, 0, 0);
   glVertex3i(1, 0, 1);
   glVertex3i(1, 1, 1);
   glVertex3i(1, 1, 0);
   glEnd();

   glFlush ();
}

void init (void) 
{
   glOrtho(-0.5,1.5,-0.5,1.5,-10,10);
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glEnable(GL_DEPTH_TEST);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
		case 'a':
			alphay += accx;
			x = 1.0;
			glutPostRedisplay();
			break;
		case 'A':
			alphay -= accx;
			x = 1.0;
			glutPostRedisplay();
			break;
      default:
         break;
   }
}

void idle()
{
	alphax += accx;
	alphay += accy;
	glutPostRedisplay();
}

void special(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_UP : 
		accx += 0.01;
		break;
	case GLUT_KEY_DOWN :
		accx -= 0.01;
		break;
	case GLUT_KEY_RIGHT : 
		accy += 0.01;
		break;
	case GLUT_KEY_LEFT :
		accy -= 0.01;
		break;
	}
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Cube");
   init ();
   glutIdleFunc(idle);
   glutDisplayFunc(display); 
   glutKeyboardFunc(keyboard);
   glutSpecialFunc(special);
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
