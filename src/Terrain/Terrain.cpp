#include "Terrain.h"

#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>

// Hilfsfunktion: bestimmt Zufallszahl auf dem Bereich -interval ... +interval 
float random(float interval)
{
	return((float)rand()/(float)RAND_MAX)*2*interval-interval;
}

// neues Terrain anlegen, alle Hoehenwerte auf Null setzen
// Eckpunkte bekommen zufaellige Hoehenwerte
Terrain::Terrain(int resolution, float interval)
{
    mResolution = resolution;
    mHeight.resize(resolution*resolution);

    for (int i = 0 ; i < resolution*resolution ; i++) {
        mHeight[i] = 0;
    }

   	setHeight(0, 0, random(interval));
  	setHeight(0, resolution-1, random(interval));
  	setHeight(resolution-1, resolution-1, random(interval));
  	setHeight(resolution-1, 0, random(interval));
  	
	generate(0, 0, resolution-1, resolution-1, interval);
}

Terrain::~Terrain()
{
}

// *** Terrain mit mehreren GL_TRIANGLE_STRIPs zeichnen
void Terrain::draw()
{
	for (int z = 0; z < mResolution-1; z++){
		glBegin(GL_TRIANGLE_STRIP);
		for (int x = 0; x < mResolution; x++){
			glVertex3f(x, getHeight(x, z), z);
			glVertex3f(x, getHeight(x, z + 1), z + 1);
		}
		glEnd();
	}
}

// *** Diamond-Square Verfahren fuer Rechteck im Bereich (x1,z1) bis (x2,z2)
// *** interval gibt Bereich fuer die Zufallszahlen an
void Terrain::generate(int x1, int z1, int x2, int z2, float interval)
{	 
   int xMidpnt = (x1+x2) / 2;
   int zMidpnt = (z1+z2) / 2;
 
   GLfloat A = getHeight(x1, z1);
   GLfloat B = getHeight(x2, z1);
   GLfloat C = getHeight(x1, z2);
   GLfloat D = getHeight(x2, z2);
 
   GLfloat E = (A + B + C + D) / 4 + random(interval); // Midpoint height
 
   setHeight(xMidpnt, zMidpnt, E); // Set E
 
   setHeight(x1, zMidpnt, (A + C + E) / 3 + random(interval));  // F
   setHeight(xMidpnt, z1, (A + B + E) / 3 + random(interval));  // G
   setHeight(x2, zMidpnt, (B + D + E) / 3 + random(interval));  // H
   setHeight(xMidpnt, z2, (C + D + E) / 3 + random(interval));  // I
   std::cout << xMidpnt << "-" << x1 << std::endl;
   if ((xMidpnt - x1) > 1) { // Subdivide if new midpoint length will be > 1
 
      generate(x1, z1, xMidpnt, zMidpnt, interval);
      generate(xMidpnt, z1, x2, zMidpnt, interval);
      generate(x1, zMidpnt, xMidpnt, z2, interval);
      generate(xMidpnt, zMidpnt, x2, z2, interval);
   }
}

// Hoehenwert bei (x,z) eintragen
void Terrain::setHeight(int x, int z, float height)
{
    if (getHeight(x, z) == 0)                  // nur ueberschreiben falls nicht schon gesetzt
        mHeight[z*mResolution+x] = height;
}

// Hoehenwert bei (x,z) abfragen
float Terrain::getHeight(int x, int z)
{
    return mHeight[z*mResolution+x];
}

