#include "DrawPoint.h"
#include <GL/glut.h>

//Constructor with initialization
//The Super-constructor DrawElement(x,y) is called in the initialization list
//and initializes the members x,y. 
DrawPoint::DrawPoint(float x, float y) : DrawElement(x,y)
{

}

DrawPoint::~DrawPoint()
{

}

//Implement the virtual function draw
void DrawPoint::draw() const
{
    //Draw a white point at (x,y)
    glBegin(GL_POINTS);
    glColor3f(1.0f,1.0f,1.0f);
    glVertex3f(this->x,this->y,0.0f);
    glEnd();
}
