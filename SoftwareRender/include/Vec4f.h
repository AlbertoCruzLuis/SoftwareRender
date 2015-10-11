#ifndef VEC4F_H
#define VEC4F_H
#include <stdexcept>
#include <cmath>

#include "Vec3f.h"

struct Vec4f {        
    float x, y, z, w;
     /**
      * @brief Universal constructor
      * @param x x-coord
      * @param y y-coord
      * @param z z-coord
      * @param w w-coord (Homogeneous coordinates)
      */
    Vec4f(float x = 0, float y = 0, float z = 0, float w = 1) {
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    };
    /**
     * @brief Indexing of vector elements
     * @param idx element index { x, y, z, w}
     * @return Reference to element with index idx
     */
    inline float& operator [] (size_t idx) {
        return (idx < 2)?((idx==0)?x:y):((idx==2)?z:w);
    };    
    inline Vec3f get3Dproj() {
        return { x/w, y/w, z/w };
    };
};

#endif // VEC4F_H
