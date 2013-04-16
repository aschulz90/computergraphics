#ifndef _POLYGON2D_H
#define _POLYGON2D_H
#include "Vector2D.h"
#include <vector>
using namespace std;

class Polygon2D {
public:
	Polygon2D();
	~Polygon2D();
	void		addPoint(Vector2D point);	// neuen Punkt anfuegen
	Vector2D	getPoint(int i) const; // Punkt i zurueckliefern
	void		deletePoints(); // alle Punkte loeschen
	int			numPoints() const; // Anzahl Punkte
	void		draw() const; // Polygon zeichnen
	private:
		vector<Vector2D> mPoints; // dyn. Array der Punkte
};
#endif