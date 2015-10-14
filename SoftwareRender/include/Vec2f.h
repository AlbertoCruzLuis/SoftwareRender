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


/**
 * @brief add
 * @return a + b
 */
inline Vec2f operator+(Vec2f a, Vec2f b) {
    return {a.x+b.x, a.y+b.y};
}

/**
 * @brief sub
 * @return a + b
 */
inline Vec2f operator-(Vec2f a, Vec2f b) {
    return {a.x-b.x, a.y-b.y};
}

/**
 * @brief sub
 * @return a + b
 */
inline Vec2f operator*(Vec2f a, float b) {
    return {a.x*b, a.y*b};
}

#endif // VEC2F_H
