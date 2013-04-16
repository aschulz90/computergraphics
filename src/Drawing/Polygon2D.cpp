#include "Polygon2D.h"
#include <GL/glut.h>

Polygon2D::Polygon2D(){
}

Polygon2D::~Polygon2D(){
}

void Polygon2D::addPoint(Vector2D point){
	mPoints.push_back(point);
}

Vector2D Polygon2D::getPoint(int i) const{
	return mPoints[i];
}

void Polygon2D::deletePoints(){
	mPoints.clear();
}

int Polygon2D::numPoints() const{
	return mPoints.size();
}

void Polygon2D::draw() const{
	glBegin(GL_LINE_LOOP);
	for (int i = 0 ; i < mPoints.size() ; i++)
	glVertex2f(mPoints[i].x(), mPoints[i].y());
	glEnd();
}