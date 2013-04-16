/*******************************************************************************
 *  Vector2D.cpp
 *
 *  (C) 2004 AG Computergraphik
 *           Universitaet Koblenz-Landau
 ******************************************************************************/

//--- Includes -----------------------------------------------------------------

#include <cmath>
#include "Vector3D.h"


//--- Klassenimplementierung ---------------------------------------------------

Vector3D::Vector3D()
{
   setXYZ(0, 0,0);
}


Vector3D::Vector3D(float x, float y, float z)
{
   setXYZ(x, y, z);
}


float Vector3D::x() const
{
   return mElement[X];
}


float Vector3D::y() const
{
   return mElement[Y];
}


float Vector3D::z() const
{
   return mElement[Z];
}


float Vector3D::get(int index) const
{
   return mElement[index];
}


void Vector3D::set(int index, float value)
{
   mElement[index] = value;
}


void Vector3D::setX(float value)
{
   mElement[X] = value;
}


void Vector3D::setY(float value)
{
   mElement[Y] = value;
}


void Vector3D::setXYZ(float newX, float newY, float newZ)
{
   mElement[X] = newX;
   mElement[Y] = newY;
   mElement[Z] = newZ;
}
