#ifndef VEC2I_H
#define VEC2I_H

struct Vec2i {
    int x, y;
    Vec2i(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    int& operator[](int idx) {
        return (idx) ? y : x;
    }
    
    Vec2i mulRound(float k) {
        return {(int)(x*k),(int)(y*k)};
    }
};


/**
 * @brief add
 * @return a + b
 */
inline Vec2i operator+(Vec2i a, Vec2i b) {
    return {a.x+b.x, a.y+b.y};
}

/**
 * @brief sub
 * @return a + b
 */
inline Vec2i operator-(Vec2i a, Vec2i b) {
    return {a.x-b.x, a.y-b.y};
}

/**
 * @brief sub
 * @return (a) * b
 */
inline Vec2i operator*(Vec2i a, int b) {
    return {a.x*b, a.y*b};
}



#endif // VEC2I_H
