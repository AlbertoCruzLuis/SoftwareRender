#ifndef MAT4_H
#define MAT4_H
#include <algorithm>
#include <cmath>
#include "Vec3f.h"
#include "Vec4f.h"
/**
 * @class Mat4
 * @brief simple 4x4 matrix class with some specific methods for transforms
 */
struct Mat4 {
    // real data array
    float data[16];
    // for more pretty indexing  mat[row][col]
    float* operator[](int idx) {
        return &(data[idx*4]);
    }
    // Mat = Mat1 * Mat2
    Mat4 operator*(Mat4 rhs) {
        return mul(rhs);
    }
    
    // Constuctor, makes identity matrix
    Mat4() {
        std::fill_n(data, 16, 0.0);
        for (int i = 0; i < 4; i++)
            data[i*4 + i] = 1;
    }
    
    // multiplication method
    Mat4 mul(const Mat4& rhs) {
        Mat4 out;
        std::fill_n(out.data, 16, 0.0);
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                for(int n = 0; n < 4; n++)
                    out.data[i * 4 + j] += data[i * 4 + n] * rhs.data[n * 4 + j];
        return out;
    }
    
    /**
     * @brief Transform 3D vector with 4x4 matrix 
     * [Cartesian->Homogeneous->Cartesian]
     * @param v vector to transform
     * @return new transformed vector
     */
    Vec3f transformVec(Vec3f& v) {
        Vec4f in {v.x, v.y, v.z, 1};
        Vec4f out;
        out.w = 0;
        for (int j = 0; j < 4; j++)
            for (int i = 0; i < 4; i++)
                out[j] += data[j * 4 + i] * in[i]; 
        return out.get3Dproj();
    }
    
    /**
     * @brief Create scale transform matrix
     * @param scaleX
     * @param scaleY
     * @param scaleZ
     * @return new matrix
     */
    static Mat4 newScale(float scaleX, float scaleY, float scaleZ) {
        Mat4 tmp;
        tmp[0][0] = scaleX;
        tmp[1][1] = scaleY;
        tmp[2][2] = scaleZ;
        return tmp;
    }
    
    /**
     * @brief Create translate transform matrix
     * @param tX 
     * @param tY
     * @param tZ
     * @return new matrix
     */
    static Mat4 newTranslate(float tX, float tY, float tZ) {
        Mat4 tmp;
        tmp[0][3] = tX;
        tmp[1][3] = tY;
        tmp[2][3] = tZ;
        return tmp;
    }

    static Mat4 newRotateX(float angle) {
        Mat4 tmp;
        tmp[1][1] =  std::cos(angle);
        tmp[1][2] = -std::sin(angle);
        tmp[2][1] =  std::sin(angle);
        tmp[2][2] =  std::cos(angle);
        return tmp;
    }
    
    static Mat4 newRotateY(float angle) {
        Mat4 tmp;
        tmp[0][0] =  std::cos(angle);
        tmp[0][2] =  std::sin(angle);
        tmp[2][0] = -std::sin(angle);
        tmp[2][2] =  std::cos(angle);
        return tmp;
    }
    
    static Mat4 newRotateZ(float angle) {
        Mat4 tmp;
        tmp[0][0] =  std::cos(angle);
        tmp[0][1] = -std::sin(angle);
        tmp[1][0] =  std::sin(angle);
        tmp[1][1] =  std::cos(angle);
        return tmp;
    }    
    
    static Mat4 newIdentity() {
        Mat4 tmp;
        return tmp;
    }
    
    static Mat4 newPerspective(float fov, float aspect, float n, float f) {
        Mat4 tmp;
        tmp[0][0] = (std::cos(fov/2.)/std::sin(fov/2.))/aspect;
        tmp[1][1] = std::cos(fov/2.)/std::sin(fov/2.);
        tmp[2][2] = (f+n)/(n-f);
        tmp[2][3] = (2*n*f)/(n-f);
        tmp[3][2] = -1;
        tmp[3][3] = 0;
        return tmp;
    }
    
};

#endif // MAT4_H
