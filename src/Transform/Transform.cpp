#include <math.h>
#include <GL/glut.h>
#define PI 3.1415926535898

#ifndef M_PI
#define M_PI 3.141592
#endif

int width = 600;
int height = 600;
int pos1 = 0;
int pos2 = 90;
int pos3 = 0;
int pos4 = 180;
int pos5 = 0;

void drawCircle(int radius, int anzahlSegmente){
	glBegin( GL_LINE_STRIP );
	for( int i=0; i<anzahlSegmente+1; i++ )
	{
		float Angle = i * (2.0*PI/anzahlSegmente); 
		float X = cos( Angle )*radius; 
		float Y = sin( Angle )*radius;
		glVertex2f( X, Y );
	}
	glEnd();

}

void display(void)	
{
    // Farb- und Tiefenbuffer leeren
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Teekanne rendern.

	glPushMatrix();
    glColor3f(0,1,0);
	glRotatef(pos1, 0, 1.0, 0);
	glTranslatef(10, 0, 0);
	glRotatef(pos3, 0, 0, 1.0);
	glTranslatef(5, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
    glColor3f(0,0,1);
	glRotatef(pos1, 0, 1.0, 0);
	glTranslatef(10, 0, 0);
	glRotatef(pos4, 1.0, 0, 0);
	glTranslatef(0, 5, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
    glColor3f(1,0,0);
	glRotatef(pos1, 0, 1.0, 0);
	glTranslatef(10, 0, 0);
	glRotatef(pos2, 0, 1.0, 0);
	glTranslatef(5, 0, 0);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glRotatef(pos1, 0, 1.0, 0);
	glTranslatef(10, 0, 0);
	glutSolidSphere(1,10,10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glRotatef(pos1, 0, 1.0, 0);
	glTranslatef(10, 0, 0);
	glRotatef(90, 0, 1.0, 0);
	drawCircle(5, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glRotatef(pos1, 0, 1.0, 0);
	glTranslatef(10, 0, 0);
	glRotatef(90, 1.0, 0, 0);
	drawCircle(5, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glRotatef(pos1, 0, 1.0, 0);
	glTranslatef(10, 0, 0);
	drawCircle(5, 100);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0,0,0);
	glRotatef(90, 1.0, 0, 0);
	drawCircle(10, 100);
	glPopMatrix();

	glPushMatrix();
	GLfloat position[] = { 0 , 0, 0, 1};
	glLightfv(GL_LIGHT0, GL_POSITION, position);
    glColor3f(1,1,0);
	glRotatef(45, 0, 0, 1.0);
	glRotatef(pos5, 0, 1.0, 0);
    glutSolidTeapot(1);
	glPopMatrix();

    glutSwapBuffers();	
}

void timer(int val)
{
    glutTimerFunc(val,timer,val);
	pos1++;
	pos2++;
	pos3++;
	pos4++;
	pos5--;
    glutPostRedisplay();
}

void init()
{
    glEnable(GL_DEPTH_TEST);

    glViewport(0,0,width,height);					
    glMatrixMode(GL_PROJECTION);					
    glLoadIdentity();								
    glOrtho(-15.0, 15.0, -15.0, 15.0, 0.0, 200);

    glMatrixMode(GL_MODELVIEW);

	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

    glLoadIdentity();
    gluLookAt(25.0, 11.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Transformationen");

    glutDisplayFunc(display);
    glutTimerFunc(10,timer,10);

    init();
    glutMainLoop();
    return 0;
}
