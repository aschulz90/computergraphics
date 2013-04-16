#include "DrawTriangle.h"
#include <GL/glut.h>

//Constructor with initialization of class members
//The Super-constructor DrawElement(x,y) is called in the initialization list
//and initializes the members x,y. 
DrawTriangle::DrawTriangle(float x, float y, float size,
                           float red, float green, float blue) : 
  DrawElement(x,y), size(size),
   red(red),
   green(green),
   blue(blue)
{

}

DrawTriangle::~DrawTriangle()
{

}

void DrawTriangle::draw() const
{
    glBegin(GL_TRIANGLES);
    glColor3f(this->red,this->green,this->blue);
    glVertex3f(this->x-this->size/2.f, this->y-this->size/2.f, 0.0f);
    glVertex3f(this->x+this->size/2.f, this->y-this->size/2.f, 0.0f);
    glVertex3f(this->x,                this->y+this->size/2.f, 0.0f);
    glEnd();
}
