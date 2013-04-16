#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <vector>

class Terrain 
{
private: 
    int mResolution;              // Gesamtanzahl Punkte
    std::vector<float> mHeight;   // alle Hoehenwerte

public:

    Terrain(int resolution, float interval);
    ~Terrain();
    
    void generate(int x1, int z1, int x2, int z2, float interval);

    void draw();
    void setHeight(int x, int z, float height);
    float getHeight(int x, int z);
	
    


};

#endif
