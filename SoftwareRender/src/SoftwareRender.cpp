#include "SoftwareRender.h"
#include <cmath>
#include <algorithm>
#include "Vec3f.h"
#include "Vec2f.h"
#include "Vec3i.h"
#include "Mat4.h"
#include <iostream>

using namespace std;

/* PUBLIC */

/**
 * @brief Standard constructor
 * @param renderWidth render area width
 * @param renderHeight render area height
 * @param renderOutput memory block pointer with size w*h*4
 */
SoftwareRender::SoftwareRender(int renderWidth,
                               int renderHeight) {
    // reset matrixes
    screenMatrix =
        Mat4::newTranslate(renderWidth/2.,renderHeight/2.,0) * 
        Mat4::newScale(renderWidth/2., - renderHeight/2.,1);
    setTransformMatrix(Mat4::newIdentity());
    width = renderWidth;
    height = renderHeight;
    pixels = new uint32_t[width*height];
    zBuffer = new int[width*height];
    clear(0);
}

SoftwareRender::~SoftwareRender() {
    delete[] pixels;
    delete[] zBuffer;
}

void SoftwareRender::setPixel(int x, int y, uint32_t color) {
    if((x < width) && (y < height) && (x >= 0) && (y >= 0))
        pixels[pixelIndex(x, y)] = color;
}

/* PRIVATE */

/**
 * @brief clear render area
 * @param color clear color
 */
void SoftwareRender::clear(uint32_t color) {
    std::fill_n(pixels, width * height, color);
    std::fill_n(zBuffer, width * height, MIN_Z_BUFFER);
}

int SoftwareRender::pixelIndex(int x, int y) {
    return (y * width + x);
}

void SoftwareRender::setPixelUnsafe(int x, int y, uint32_t color) {
    pixels[pixelIndex(x, y)] = color;
}

bool SoftwareRender::isInClipBox(Vec3f v) const{
    if ( (v.x > 1) || (v.x < -1) || 
         (v.y > 1) || (v.y < -1) ||
         (v.z > 1) || (v.z < -1) )
             return false;
    return true;
}

/**
 * @brief Draw line
 * @param v1 first point
 * @param v2 second point
 * @param color color of line
 */
void SoftwareRender::drawLine(Vec3f v1, Vec3f v2, uint32_t color, bool direct) {
    if (!direct) {
        v1 = transMatrix.transformVec(v1);
        v2 = transMatrix.transformVec(v2);
    if (!(isInClipBox(v1) && isInClipBox(v2)))
        return;
        v1 = screenMatrix.transformVec(v1);
        v2 = screenMatrix.transformVec(v2);         
    }
    int x1 = v1.x, x2 = v2.x, y1 = v1.y, y2 = v2.y;
    // В какую сторону смещаемся.
    int dx = (x2 - x1 >= 0 ? 1 : -1);
    int dy = (y2 - y1 >= 0 ? 1 : -1);
    // Проекции на оси
    int lengthX = abs(x2 - x1);
    int lengthY = abs(y2 - y1);
    //  Не является ли отрезок точкой
    int length = max(lengthX, lengthY);
    if(length == 0) {
        setPixel(x1, y1, color);
    }
    // Основная ось - X
    if(lengthY <= lengthX) {
        // Начальные значения
        int x = x1;
        int y = y1;
        int d = -lengthX;

        // Основной цикл
        length++;
        while(length--) {
            setPixel(x, y, color);
            x += dx;
            d += lengthY << 1; // * 2
            if(d > 0) {
                d -= lengthX << 1;
                y += dy;
            }
        }
    } else {
        // Начальные значения
        int x = x1;
        int y = y1;
        int d = -lengthY;

        // Основной цикл
        length++;
        while(length--) {
            setPixel(x, y, color);
            y += dy;
            d += lengthX << 1;
            if(d > 0) {
                d -= lengthY << 1;
                x += dx;
            }
        }
    }
}

void SoftwareRender::drawTriangle(ModelVert _mVerts[3], uint32_t color) {
    ModelVert mVerts[3];
    std::copy_n(_mVerts,3,mVerts);
    mVerts[0].pos = transMatrix.transformVec(mVerts[0].pos);
    mVerts[1].pos = transMatrix.transformVec(mVerts[1].pos);
    mVerts[2].pos = transMatrix.transformVec(mVerts[2].pos);
    mVerts[0].normal = transMatrix.transformVec(mVerts[0].normal).norm()*(-1);
    mVerts[1].normal = transMatrix.transformVec(mVerts[1].normal).norm()*(-1);
    mVerts[2].normal = transMatrix.transformVec(mVerts[2].normal).norm()*(-1);

    if(!(isInClipBox(mVerts[0].pos) && isInClipBox(mVerts[1].pos) &&
         isInClipBox(mVerts[2].pos)))
        return;
        
    // calc triangle normal
    Vec3f n = ((mVerts[1].pos-mVerts[0].pos)^(mVerts[2].pos-mVerts[0].pos)).norm();
    float intensity = n*Vec3f(0,0,1);

    //back-face culling
    if (intensity < 0)
        return;
    
    uint8_t cg = (uint8_t)(intensity*0xFF);
    uint32_t c  = (cg << 24)|(cg << 16)|(cg << 8)|0xFF;
    
    Vec3f mVertsScr[3];
    Vec3f mVertsScrTmp[3];

    for (int i = 0; i < 3; i++) {
        Vec3f tmpVec;
        tmpVec = screenMatrix.transformVec(mVerts[i].pos); 
        mVertsScr[i].x = (int)(tmpVec.x);
        mVertsScr[i].y = (int)(tmpVec.y);
        mVertsScr[i].z = (tmpVec.z) * MIN_Z_BUFFER;
    }
    std::copy_n(mVertsScr,3,mVertsScrTmp);
    MathUtils::SortVerts(mVertsScr,0); //by X;
    int BBxMin = (int)mVertsScr[0].x, BBxMax = (int)mVertsScr[2].x;
    MathUtils::SortVerts(mVertsScr,1); // by Y;
    int BByMin = (int)mVertsScr[0].y, BByMax = (int)mVertsScr[2].y;
    std::copy_n(mVertsScrTmp,3,mVertsScr);
    
    
    for (int i = BByMin; i <= BByMax; i++) {
        for (int j = BBxMin; j <= BBxMax; j++) {
            int idx = j+i*width;
            Vec3f P(j,i,0);
            Vec3f bar = MathUtils::Barycentric(mVertsScr[0],mVertsScr[1],mVertsScr[2],P);
            P.z = mVertsScr[0].z*bar[0] + mVertsScr[1].z*bar[1] + mVertsScr[2].z*bar[2];
            if ((bar[0] >= 0)&&(bar[1] >= 0)&&(bar[2] >= 0)&&(bar[0] <= 1)&&(bar[1] <= 1)&&(bar[2] <= 1)) {
                if (zBuffer[idx] < (P.z)) {
                    zBuffer[idx] = (P.z);
                    n = (mVerts[0].normal *bar[0] + mVerts[1].normal *bar[1] + mVerts[2].normal *bar[2]);
                    intensity = (n)*Vec3f(0,0,1);
                    cg = (uint8_t)(0xFF*intensity);
                    //cg = (uint8_t)((zBuffer[idx]/(float)MIN_Z_BUFFER)*0xFF);
                    c = (cg<<24)|(cg<<16)|(cg<<8)|0xFF;
                    //c &= 0x7AEECCDD;
                    setPixel(j, i, c);
                }
            }
        }   
    } 
    
}

/**
 * @brief set new transform matrix
 * @param transMatrix new matrix
 */
void SoftwareRender::setTransformMatrix(Mat4 transMatrix) {
    this->transMatrix = transMatrix;
}
