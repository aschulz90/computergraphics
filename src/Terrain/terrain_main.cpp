/*** Eine einfache Landschaft... ***/

#include "Terrain.h"
#include <iostream>
#include <GL/glut.h>

GLint width = 600;
GLint height = 600;

float xAngle = 0.0;
float yAngle = 0.0;

int terrainResolution = 32;             // Terrain Aufloesung (x und z Richtung)
float interval = 10.0;                  // Ausdehnung in der Hoehe
Terrain* terrain;


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	glTranslatef(0, 0, -terrainResolution);
	glRotatef(xAngle, 1, 0, 0);                     // Terrain drehen
	glRotatef(yAngle, 0, 1, 0);
	glTranslatef(-terrainResolution/2, 0, -terrainResolution/2);

	terrain->draw();
	      
	glutSwapBuffers();
}

void special(int key, int x, int y)
{
	switch (key) {
	 case GLUT_KEY_UP: xAngle+= 0.5; break;    // Terrain ueber Tasten drehen
	 case GLUT_KEY_DOWN: xAngle -= 0.5; break;
	 case GLUT_KEY_LEFT: yAngle += 0.5; break;
	 case GLUT_KEY_RIGHT: yAngle -= 0.5; break;
	}
    glutPostRedisplay();	
}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, 1.0, 0.1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		
	glColor3f(1.0, 1.0, 1.0);
	terrain = new Terrain(terrainResolution, interval);  // neues Terrain anlegen
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Simple Terrain");
	glutSpecialFunc(special);
	glutDisplayFunc(display);
	glutIdleFunc(display);

	init();

	glutMainLoop();
	return 0;             
}
