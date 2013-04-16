/*** Eine Landschaft mit Beleuchtung ***/

#include "Terrain.h"

#include <GL/glut.h>


GLint width = 600;
GLint height = 600;

float xAngle = 0.0;
float yAngle = 0.0;

int terrainResolution = 32;
float interval = 10.0;
Terrain* terrain;

bool cameraLight = true;

float lightPosCamera[4] = {0.0, 0.0, 0.0, 1.0};
float lightPosWorld[4] = {terrainResolution/2, terrainResolution/2, terrainResolution/2, 1.0};

void display(void)
{
	int i;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	if (cameraLight)
	    glLightfv(GL_LIGHT0, GL_POSITION, lightPosCamera);    // Licht bewegt sich mit Kamera

	glTranslatef(0, 0, -terrainResolution);
    glRotatef(xAngle, 1, 0, 0);
    glRotatef(yAngle, 0, 1, 0);
    glTranslatef(-terrainResolution/2, 0, -terrainResolution/2);

	if (!cameraLight)
	    glLightfv(GL_LIGHT0, GL_POSITION, lightPosWorld);   // Licht ist fest an Weltkoordinate 

	terrain->draw();
	      
	glutSwapBuffers();
}

void special(int key, int x, int y)
{
	switch (key) {
	 case GLUT_KEY_UP: xAngle+= 0.5; break;
	 case GLUT_KEY_DOWN: xAngle -= 0.5; break;
	 case GLUT_KEY_LEFT: yAngle += 0.5; break;
	 case GLUT_KEY_RIGHT: yAngle -= 0.5; break;
	}
    glutPostRedisplay();	
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == ' ')
        cameraLight = !cameraLight;            // Licht umschalten
}

void init()
{
    float lightCol[4] = {1.0, 1.0, 1.0, 1.0};
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightCol);
        
    glEnable(GL_DEPTH_TEST);
        
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, 1.0, 0.1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
		
	terrain = new Terrain(terrainResolution, interval);
}

int main(int argc, char **argv)
{
	int i;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Light Terrain");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutDisplayFunc(display);
	glutIdleFunc(display);

	init();

	glutMainLoop();
	return 0;             
}


