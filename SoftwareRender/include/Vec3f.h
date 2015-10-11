#ifndef VEC3F_H
#define VEC3F_H

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
    
    
};

#endif // VEC3F_H
