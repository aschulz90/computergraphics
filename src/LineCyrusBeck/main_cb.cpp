// *** Linienclipping nach Cyrus-Beck ***

#include <GL/glut.h>

#include <vector>
#include "Vector2D.h"

using namespace std;

#define BREITE 520
#define HOEHE 520

const int xmin = 10;
const int xmax = 510;
const int ymin = 50;
const int ymax = 450;

vector<Vector2D> clipPoints;

void drawLine(Vector2D a, Vector2D b)
{
	glBegin(GL_LINES);
		glVertex3f(a.x(), a.y(), 0);
		glVertex3f(b.x(), b.y(), 0);
	glEnd();
}

void initClipPoints()
{
    clipPoints.push_back(Vector2D(xmin, ymin));
    clipPoints.push_back(Vector2D(xmax, ymin));
    clipPoints.push_back(Vector2D(xmax, ymax));
    clipPoints.push_back(Vector2D(xmin, ymax));
}

void drawClipPolygon()
{
    for (int i = 0 ; i < 4 ; i++)
        drawLine(clipPoints[i], clipPoints[(i+1)%4]);
}

void clipAndDraw(Vector2D a, Vector2D b)
{
	Vector2D v,w0,w1,n;	
	float t, tIn, tOut, c0, c1, nenner;
	int i;

	v = b - a;
	tIn  = 0.0;
	tOut = 1.0;

	for (i=0; i<4; i++)
	{
	    int iNext = (i+1) % 4;
		n.setX( clipPoints[iNext].y() - clipPoints[i].y() );      // Normalenvektor auf Clipkante
		n.setY( - (clipPoints[iNext].x() - clipPoints[i].x()) );

		w0 = a - clipPoints[i];
		w1 = b - clipPoints[i];
		
		c0 = dot(w0, n);
		c1 = dot(w1, n);
		
		if (c0 > 0 && c1 > 0)	// alles auﬂerhalb, fertig
			return;
		if (c0 <= 0 && c1 <= 0) // innerhalb, weitertesten
			continue;

		nenner = dot(v,n );
		t = -c0/nenner;

		if (nenner < 0 && t > tIn)
			tIn = t;
		if (nenner > 0 && t < tOut)
			tOut = t;
	}
	if (tIn > tOut)
		return;
	
	b = a + tOut * v;
	a = a + tIn * v;

	drawLine(a, b);
}

void display(void)
{
   GLint x;

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f( 0.0, 0.0, 1.0); 
   drawClipPolygon();
        
   glColor3f( 1.0, 0.0, 0.0); 
   clipAndDraw(Vector2D(-200,-50),Vector2D(750,550));   
   clipAndDraw(Vector2D(-100,545),Vector2D(25,650));   
   clipAndDraw(Vector2D(75,100),Vector2D(85,-150));
   clipAndDraw(Vector2D(175,375),Vector2D(300,150));
   clipAndDraw(Vector2D(350,-100),Vector2D(550,250));

   glFlush ();
}

void init (void) 
{
   glClearColor (1.0, 1.0, 1.0, 0.0);
   glOrtho(0, BREITE, 0, HOEHE, -1, 1);
   
   initClipPoints();
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize( BREITE, HOEHE);
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("Cyrus-Beck Clipping");
   init ();
   glutDisplayFunc(display); 
   glutMainLoop();
   return 0;   /* ANSI C requires main to return int. */
}
