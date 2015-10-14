#ifndef VEC3F_H
#define VEC3F_H

#include <cmath>

struct Vec3f {
    float x, y, z;
    /**
     * @brief Universal constructor
     * @param x x-coord
     * @param y y-coord
     * @param z z-coord
     */
    Vec3f(float x = 0, float y = 0, float z = 0) {
        this->x = x;
        this->y = y;
        this->z = z;
    };
    
    float& operator[](int idx) {
        return (idx < 2)?((idx==0)?x:y):z;
    };
    
    float len() {
        return std::sqrt(x*x + y*y + z*z);
    }
    
    Vec3f norm() {     
        float l = len();
        return {x/l, y/l, z/l};
    }
};

/**
 * @brief Cross product 
 * @return a x b
 */
inline Vec3f operator^(Vec3f a, Vec3f b) {
    /*
     *          |   i   j   k  |
     *  a x b = |  a.x a.y a.z |
     *          |  b.x b.y b.z |
     * 
     */
    Vec3f tmp;
    tmp.x = a.y*b.z - a.z*b.y;
    tmp.y = a.z*b.x - a.x*b.z;
    tmp.z = a.x*b.y - a.y*b.x;
    return tmp;
}


/**
 * @brief Dot product
 * @return a * b
 */
inline float operator*(Vec3f a, Vec3f b) {
    /*
     *  d = a.x*b.x + a.y*b.y + a.z*b.z
     */
    return (a.x*b.x + a.y*b.y + a.z*b.z);
}

/**
 * @brief add
 * @return a + b
 */
inline Vec3f operator+(Vec3f a, Vec3f b) {
    return {a.x+b.x, a.y+b.y, a.z+b.z};
}

/**
 * @brief sub
 * @return a + b
 */
inline Vec3f operator-(Vec3f a, Vec3f b) {
    return {a.x-b.x, a.y-b.y, a.z-b.z};
}

#endif // VEC3F_H
