#ifndef _POLYGON2D_H
#define _POLYGON2D_H

#include "Vector3D.h"
#include <vector>

using namespace std;

class Cube 
{
public:
    Cube();
    ~Cube();

    void addPoint(Vector3D point);                    // neuen Punkt anfuegen
    Vector3D getPoint(int i) const;                   // Punkt i zureuckliefern
    void deletePoints();                              // alle Punkte loeschen
    int numPoints() const;                            // Anzahl Punkte
    void draw() const;                                // Polygon zeichnen
    void setRotateX(float f);
	float getRotateX();
	 void setRotateY(float f);
	float getRotateY();

private:
    
	vector<Vector3D> mPoints;                         // dyn. Array der Punkte
	float rotateX;
	float rotateY;
};

#endif

