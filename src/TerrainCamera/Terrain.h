#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <vector>

using namespace std;

class Terrain {
public:
    Terrain(int resolution, float interval);
    ~Terrain();
    
    void generate(int x1, int z1, int x2, int z2, float interval);

    void draw();
    void setHeight(int x, int z, float height);
    float getHeight(int x, int z);
    
private:     
    int mResolution;         // number of points in x and z direction
    vector<float> mHeight;
};


#endif

