#include "Terrain.h"

#include "Vector3D.h"
#include <stdlib.h>
#include <GL/glut.h>

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


void Terrain::draw()
{
    Vector3D n;
    
    float terrainColor[4] = {0.8f, 0.8f, 0.8f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, terrainColor);
    
    for (int z = 1 ; z < mResolution-2 ; z++) {
        glBegin(GL_TRIANGLE_STRIP);
                      
        for (int x = 1 ; x < mResolution-1 ; x++) {
                n.setXYZ(getHeight(x - 1, z) - getHeight(x + 1, z), 2, getHeight(x, z - 1) - getHeight(x, z + 1));
                n.normalize();
                glNormal3f(n.x(), n.y(), n.z());
                glVertex3f((GLfloat)(x), getHeight(x, z), (GLfloat)(z));
                n.setXYZ(getHeight(x - 1, z + 1) - getHeight(x + 1, z + 1), 2, getHeight(x, z) - getHeight(x, z + 2));
                n.normalize();
                glNormal3f(n.x(), n.y(), n.z());
                glVertex3f((GLfloat)(x), getHeight(x, z+1), (GLfloat)(z+1));
        }
        glEnd();
    }
}

void Terrain::generate(int x1, int z1, int x2, int z2, float interval)
{
    float edgeHeight, centerHeight;
	int midX = (x1 + x2) / 2;
	int midY = (z1 + z2) / 2;

	if ((x2 - x1 < 2) && (z2 - z1 < 2))
	    return;
     
    centerHeight = (getHeight(x1,z1) + getHeight(x1,z2) + 
                          getHeight(x2,z1) + getHeight(x2,z2)) / 4.0 + 
                          random(interval);
    setHeight(midX, midY, centerHeight);
    
    edgeHeight = (getHeight(x1,z1) + getHeight(x1,z2)) / 2.0 + random(interval);                                     
    setHeight(x1, midY, edgeHeight);
    edgeHeight = (getHeight(x2,z1) + getHeight(x2,z2)) / 2.0 + random(interval);                                     
    setHeight(x2, midY, edgeHeight);
    edgeHeight = (getHeight(x1,z1) + getHeight(x2,z1)) / 2.0 + random(interval);                                     
    setHeight(midX, z1, edgeHeight);
    edgeHeight = (getHeight(x1,z2) + getHeight(x2,z2)) / 2.0 + random(interval);                                     
    setHeight(midX, z2, edgeHeight);
    
	interval /= 2;
	
	generate(x1, z1, midX, midY, interval);
	generate(midX, z1, x2, midY, interval);
	generate(x1, midY, midX, z2, interval);
	generate(midX, midY, x2, z2, interval);
}

void Terrain::setHeight(int x, int z, float height)
{
    if (getHeight(x, z) == 0)
        mHeight[z*mResolution+x] = height;
}

float Terrain::getHeight(int x, int z)
{
    return mHeight[z*mResolution+x];
}





