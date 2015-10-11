#ifndef VEC2F_H
#define VEC2F_H

struct Vec2f {
    float x, y;
    Vec2f(float x = 0, float y = 0) {
        this->x = x;
        this->y = y;
    }
    
    float& operator [](int idx) {
        return (!idx)?x:y;
    }    
    
};

#endif // VEC2F_H
