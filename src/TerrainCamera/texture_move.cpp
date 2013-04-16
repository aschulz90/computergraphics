#include <GL/glut.h>

GLint width = 600;
GLint height = 600;

GLubyte pixels[16][16][3];

// hier wird eine Textur der Groesse 16 x 16 erzeugt und im Array pixels abgelegt
// pro Pixel werden RGB Werte (ohne Alpha) als unsigned byte Werte eingetragen
void generateTexture()
{
	int i,j;
	for (i = 0 ; i < 16 ; i++) {
		for (j = 0 ; j < 16 ; j++) {
			switch ((i+j) % 4) {
			case 0:
				pixels[i][j][0] = 255;
				pixels[i][j][1] = 255;
				pixels[i][j][2] = 255;
				break;
			case 1:
				pixels[i][j][0] = 255;
				pixels[i][j][1] = 0;
				pixels[i][j][2] = 0;
				break;
			case 2:
				pixels[i][j][0] = 0;
				pixels[i][j][1] = 0;
				pixels[i][j][2] = 255;
				break;
			case 3:
				pixels[i][j][0] = 255;
				pixels[i][j][1] = 255;
				pixels[i][j][2] = 0;
				break;
			}
		}
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.5, 0.5, 5, 0.5, 0, 0.5, 0, 1, 0);
	glColor3f(1.0f, 1.0f, 1.0f);

	// *** hier mit Hilfe der Texturmatrix die Texturkoordinaten so verschieben
	// *** dass sich die Textur auf den Betrachter zu bewegt 


	// *** hier die Texturkoordinaten eintragen, so dass die Textur
	// *** in z-Richtung (= t-Richtung der Textur) fuenf mal wiederholt dargestellt wird

	glBegin(GL_QUADS);
		glVertex3f(0,0,5);
		glVertex3f(1,0,5);
		glVertex3f(1,0,0);
		glVertex3f(0,0,0);
	glEnd();

	glutSwapBuffers();
}

void idle(void)
{
	glutPostRedisplay();
}

// *** mit den Tasten 1,2 und 3 soll zwischen verschiedenen Texturfiltern
// *** umgeschaltet werden. 
void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case '1' :
	    // *** MIN Filter auf GL_NEAREST setzen
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
		break;
	case '2' :
	    // *** MIN Filter auf GL_LINEAR setzen
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
		break;
	case '3' :
	    // *** MIN Filter auf GL_LINEAR_MIPMAP_LINEAR setzen
		gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, 16, 16, GL_RGB, GL_UNSIGNED_BYTE, pixels);
		break;
	}
}

// *** mit den Pfeiltasten soll die Geschwindigkeit verstellt werden
void special(int key, int x, int y)
{

}

void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, 1.0, 0.1, 100);

	generateTexture();

	// *** Texturen aktivieren und GL_NEAREST Filter fuer MIN und MAX setzen

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 16, 16, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(width, height);
	glutCreateWindow("Textur Bewegung");
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	init();
	
	glutMainLoop();
	return 0;
}

