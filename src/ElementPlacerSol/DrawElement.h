#ifndef _DRAW_ELEMENT_HEADER_
#define _DRAW_ELEMENT_HEADER_

class DrawElement
{
public:
    DrawElement(float x, float y);
    virtual ~DrawElement();

    //Declare a pure virtual function that MUST be implemented by all instanceable derivatives
    virtual void draw() const=0;


//These variables are accessible by this class and all derivatives
protected:
    float x;
    float y;
};


#endif //_DRAW_ELEMENT_HEADER_
