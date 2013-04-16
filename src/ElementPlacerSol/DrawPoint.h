#ifndef _DRAW_POINT_HEADER_
#define _DRAW_POINT_HEADER_

#include "DrawElement.h"

//Derive from the class DrawElement
class DrawPoint : public DrawElement
{
public:
    DrawPoint(float x, float y);
    ~DrawPoint();

    //Declare the implementation for the virtual function draw()
    //This is a const-function because the classes' member variables are not changed
    virtual void draw() const;
};

#endif //_DRAW_POINT_HEADER_