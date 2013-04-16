#include "Terrain.h"

#include <stdlib.h>
#include <GL/glut.h>

// Hilfsfunktion: bestimmt Zufallszahl auf dem Bereich -interval ... +interval 
float random(float interval)
{
	return((float)rand()/(float)RAND_MAX)*2*interval-interval;
}

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
	GLfloat mat_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);

    for (int z = 1 ; z < mResolution - 2 ; z++) {
        glBegin(GL_TRIANGLE_STRIP);
        for (int x = 1 ; x < mResolution - 1 ; x++) {
			glNormal3f(getHeight(x - 1, z) - getHeight(x + 1, z), 2, getHeight(x, z - 1) - getHeight(x, z + 1));
            glVertex3f((GLfloat)(x), getHeight(x, z), (GLfloat)(z));
			glNormal3f(getHeight(x - 1, z + 1) - getHeight(x + 1, z + 1), 2, getHeight(x, z) - getHeight(x, z + 2));
            glVertex3f((GLfloat)(x), getHeight(x, z+1), (GLfloat)(z+1));
        }
        glEnd();
    }
}

// *** Diamond-Square Verfahren fuer Quadrat im Bereich (x1,z1) bis (x2,z2)
// *** interval gibt Bereich fuer die Zufallszahlen an
void Terrain::generate(int x1, int z1, int x2, int z2, float interval)
{
    float edgeHeight, centerHeight;
	int midX = (x1 + x2) / 2;
	int midZ = (z1 + z2) / 2;

	if ((x2 - x1 < 2) && (z2 - z1 < 2))
	    return;
     
    centerHeight = (getHeight(x1,z1) + getHeight(x1,z2) + 
                          getHeight(x2,z1) + getHeight(x2,z2)) / 4.0 + 
                          random(interval);
    setHeight(midX, midZ, centerHeight);
    
    edgeHeight = (getHeight(x1,z1) + getHeight(x1,z2)) / 2.0 + random(interval);                                     
    setHeight(x1, midZ, edgeHeight);
    edgeHeight = (getHeight(x2,z1) + getHeight(x2,z2)) / 2.0 + random(interval);                                     
    setHeight(x2, midZ, edgeHeight);
    edgeHeight = (getHeight(x1,z1) + getHeight(x2,z1)) / 2.0 + random(interval);                                     
    setHeight(midX, z1, edgeHeight);
    edgeHeight = (getHeight(x1,z2) + getHeight(x2,z2)) / 2.0 + random(interval);                                     
    setHeight(midX, z2, edgeHeight);
    
	interval /= 2;
	
	generate(x1, z1, midX, midZ, interval);
	generate(midX, z1, x2, midZ, interval);
	generate(x1, midZ, midX, z2, interval);
	generate(midX, midZ, x2, z2, interval);
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





