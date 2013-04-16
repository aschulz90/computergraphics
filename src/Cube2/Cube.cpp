#include "Cube.h"
#include <GL/glut.h>
#include <iostream>

Cube::Cube()
{
	rotateX = 1;
	rotateY = 1;

	addPoint(Vector3D(0,0,0));
	addPoint(Vector3D(1,0,0));
	addPoint(Vector3D(1,1,0));
	addPoint(Vector3D(0,1,0));
	addPoint(Vector3D(0,0,1));
	addPoint(Vector3D(1,0,1));
	addPoint(Vector3D(1,1,1));
	addPoint(Vector3D(0,1,1));
}

Cube::~Cube()
{
}

void Cube::addPoint(Vector3D point)
{
    mPoints.push_back(point);
}

Vector3D Cube::getPoint(int i) const
{
    return mPoints[i];
}

void Cube::deletePoints()
{
    mPoints.clear();
}

int Cube::numPoints() const
{
    return mPoints.size();
}


void drawPoint(Vector3D p) 
{
	glVertex3f(p.x(), p.y(), p.z());
}

void Cube::draw() const
{
	glTranslatef(0.5f, 0.5f, 0.5f);

    glRotatef(0.06 * rotateX, 1.0f, 0.0f, 0.0f);
	glRotatef(0.06 * rotateY, 0.0f, 1.0f, 0.0f);
	glRotatef(0.06, 0.0f, 0.0f, 1.0f);
	
	glTranslatef(-0.5f, -0.5f, -0.5f);	

    glBegin(GL_QUADS);

	glColor3f(1,0,0);
	drawPoint(mPoints[0]);
    drawPoint(mPoints[4]);
	drawPoint(mPoints[5]);
	drawPoint(mPoints[1]);

	glColor3f(0,1,0);
	drawPoint(mPoints[5]);
	drawPoint(mPoints[1]);
	drawPoint(mPoints[2]);
	drawPoint(mPoints[6]);

	glColor3f(0,0,1);
	drawPoint(mPoints[0]);
	drawPoint(mPoints[1]);
	drawPoint(mPoints[2]);
	drawPoint(mPoints[3]);

	glColor3f(1,0,1);
	drawPoint(mPoints[7]);
	drawPoint(mPoints[4]);
	drawPoint(mPoints[0]);
	drawPoint(mPoints[3]);

	glColor3f(1,1,0);
	drawPoint(mPoints[2]);
	drawPoint(mPoints[3]);
	drawPoint(mPoints[7]);
	drawPoint(mPoints[6]);

	glColor3f(0,1,1);
	drawPoint(mPoints[4]);
	drawPoint(mPoints[5]);
	drawPoint(mPoints[6]);
	drawPoint(mPoints[7]);

    glEnd();
	
}

void Cube::setRotateX(float f) 
{
	rotateX = f;
}

float Cube::getRotateX() 
{
	return rotateX;
}

void Cube::setRotateY(float f) 
{
	rotateY = f;
}

float Cube::getRotateY() 
{
	return rotateY;
}