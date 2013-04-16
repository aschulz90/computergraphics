
// **** Sutherland Hodgman Clipping ****

#include "Cube.h"
#include <GL/glut.h>
#include <iostream>

Cube cube;

const int width = 600;
const int height = 600;

const int xmin = 100;
const int xmax = 500;
const int ymin = 100;
const int ymax = 500;




void display(void)
{  

                                       // Polygon wird geclippt, deshalb pro display Aufruf neu initialisieren
    glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
   // cube.setRotateFactor(cube.getRotateFactor() + 1);
	cube.draw();
	
	
    glutSwapBuffers ();                        // nie vergessen...
}


void idle()
{
	glutPostRedisplay();
}

void special(int key, int x, int y) 
{
	switch(key) {

	case GLUT_KEY_UP : cube.setRotateY(cube.getRotateY() + 1); break;
	case GLUT_KEY_RIGHT : cube.setRotateX(cube.getRotateX() + 1); break;

	case GLUT_KEY_DOWN : cube.setRotateY(cube.getRotateY() - 1); break;
	case GLUT_KEY_LEFT : cube.setRotateX(cube.getRotateX() - 1); break;
	}
}

void init (void) 
{
    glClearColor (1.0, 1.0, 1.0, 0.0);   
    glOrtho(-0.5, 1.5, -0.5, 1.5, -10, 10); 
	
	cube = Cube();

}




int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glEnable(GL_DEPTH_TEST);
   glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
  // glEnable(GL_DEPTH_TEST);

   glutInitWindowSize(width, height);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Cube");

   glutIdleFunc(idle);
   glutSpecialFunc(special);
   init();
   //glEnable(GL_LINE_STIPPLE);
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}


