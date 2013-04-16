/*** Eine einfache Landschaft... ***/

#include "Terrain.h"

#include <GL/glut.h>

GLint width = 600;
GLint height = 600;

float xAngle = 0.0;
float yAngle = 0.0;

bool camera_light;

int terrainResolution = 128;
float interval = 10.0;
Terrain* terrain;

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	if (camera_light) {
		GLfloat position[] = { 0 , 0, 0, 1};
		glLightfv(GL_LIGHT0, GL_POSITION, position);
	}

	glTranslatef(0, 0, -terrainResolution);
    glRotatef(xAngle, 1, 0, 0);
    glRotatef(yAngle, 0, 1, 0);
    glTranslatef(-terrainResolution/2, 0, -terrainResolution/2);

	 if (!camera_light) {
		GLfloat position[] = { terrainResolution/2 , terrainResolution/2, terrainResolution/2, 1};
		glLightfv(GL_LIGHT0, GL_POSITION, position);
	}
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
	switch (key) {
		case 'q':
			if (camera_light) camera_light = false; else camera_light = true;
			break;
      default:
         break;
	}
	glutPostRedisplay();
}

void init()
{
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, 1.0, 0.1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glShadeModel(GL_SMOOTH);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glColor3f(0.5, 0.5, 0.5);
	terrain = new Terrain(terrainResolution, interval);
}

int main(int argc, char **argv)
{
	camera_light = true;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Simple Terrain");
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutIdleFunc(display);

	init();

	glutMainLoop();
	return 0;             
}


