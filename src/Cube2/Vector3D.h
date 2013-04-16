/*******************************************************************************
 *  Vector2D.h
 *
 *  (C) 2004 AG Computergraphik
 *           Universitaet Koblenz-Landau
 ******************************************************************************/


#ifndef CG1_VECTOR3D_H
#define CG1_VECTOR3D_H


//--- Konstanten ---------------------------------------------------------------

const int X = 0;
const int Y = 1;
const int Z = 2;


//--- Klassendefinition --------------------------------------------------------

class Vector3D
{
   public:
      Vector3D();
      Vector3D(float x, float y, float z);

      float x() const;
      float y() const;
	  float z() const;

      void setX(float value);
      void setY(float value);
	  void setZ(float value);

      void setXYZ(float newX, float newY, float newZ);

      float get(int index) const;
      void  set(int index, float value);

      float length() const;

     


   protected:
      float mElement[3];
};


//--- Verwandte Funktionen -----------------------------------------------------



#endif   // !CG1_VECTOR2D_H
