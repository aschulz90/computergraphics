/*******************************************************************************
 *  Vector2D.h
 *
 *  (C) 2004 AG Computergraphik
 *           Universitaet Koblenz-Landau
 ******************************************************************************/


#ifndef CG1_VECTOR2D_H
#define CG1_VECTOR2D_H


//--- Konstanten ---------------------------------------------------------------

const int X = 0;
const int Y = 1;


//--- Klassendefinition --------------------------------------------------------

class Vector2D
{
   public:
      Vector2D();
      Vector2D(float x, float y);

      float x() const;
      float y() const;

      void setX(float value);
      void setY(float value);
      void setXY(float newX, float newY);

      float get(int index) const;
      void  set(int index, float value);

      float length() const;

      Vector2D& operator +=(const Vector2D& rhs);
      Vector2D& operator -=(const Vector2D& rhs);

      Vector2D& operator *=(float rhs);
      Vector2D& operator /=(float rhs);


   protected:
      float mElement[2];
};


//--- Verwandte Funktionen -----------------------------------------------------

const Vector2D operator +(const Vector2D& lhs, const Vector2D& rhs);
const Vector2D operator -(const Vector2D& lhs, const Vector2D& rhs);

const Vector2D operator *(float lhs, const Vector2D& rhs);
const Vector2D operator *(const Vector2D& lhs, float rhs);
const Vector2D operator /(const Vector2D& lhs, float rhs);

float dot(const Vector2D& lhs, const Vector2D& rhs);


#endif   // !CG1_VECTOR2D_H
