#ifndef VEC3I_H
#define VEC3I_H

#include "Vec3f.h"

struct Vec3i {
    int x, y, z;
    Vec3i(int x = 0, int y = 0, int z= 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vec3i(Vec3f vf) {
        this->x = (int)vf.x + 0.5;
        this->y = (int)vf.y + 0.5;
        this->z = (int)vf.z + 0.5;  
    }
    
    operator Vec3f() {
        return {x, y, z};
    }
    
    int& operator[](int idx) {
        return (idx>1) ? z : ((idx) ? y : x);
    }
    
    Vec3i mulRound(float k) {
        return {(int)(x*k),(int)(y*k),(int)(z*k)};
    }
};


/**
 * @brief add
 * @return a + b
 */
inline Vec3i operator+(Vec3i a, Vec3i b) {
    return {a.x+b.x, a.y+b.y, a.z + b.z};
}

/**
 * @brief sub
 * @return a + b
 */
inline Vec3i operator-(Vec3i a, Vec3i b) {
    return {a.x-b.x, a.y-b.y, a.z-b.z};
}

/**
 * @brief sub
 * @return (a) * b
 */
inline Vec3i operator*(Vec3i a, int b) {
    return {a.x*b, a.y*b, a.z*b};
}


#endif // VEC3I_H
