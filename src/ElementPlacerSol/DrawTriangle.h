#ifndef _DRAW_TRIANGLE_HEADER_
#define _DRAW_TRIANGLE_HEADER_

#include "DrawElement.h"

//Derive from the class DrawElement
class DrawTriangle : public DrawElement
{
public:
    DrawTriangle(float x, float y, float size, float red=1.0f, float green=1.0f, float blue=1.0f);
    ~DrawTriangle();

    //Declare the implementation for the virtual function draw()
    //This is a const-function because the classes' member variables are not changed
    virtual void draw() const;

//These variables are accessible by this class and all derivatives
protected:
    float size;
    float red;
    float green;
    float blue;
};

#endif //_DRAW_TRIANGLE_HEADER_