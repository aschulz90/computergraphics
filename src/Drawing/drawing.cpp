#include <GL/glut.h>
#include <iostream>

#define BREITE 350
#define HOEHE 350
#define PI 3.1415926535898


void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f( 0.0, 0.0, 1.0); 
	glFlush ();
}

void init (void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);
   /* initialize viewing values  */
   glOrtho(0, BREITE, 0, HOEHE, -1, 1);
}

void put_pixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
		glVertex3f(x, y, 0);
	glEnd();
}

void mouse( int button, int state, int x, int y){
	if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		glColor3f (0.0, 0.0, 0.0);
		put_pixel(x, y) ;
	}
	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		glColor3f (1.0, 1.0, 1.0);
		put_pixel(x, y);
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize( BREITE, HOEHE);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Malen");
   init ();
   glutMouseFunc(mouse);
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
