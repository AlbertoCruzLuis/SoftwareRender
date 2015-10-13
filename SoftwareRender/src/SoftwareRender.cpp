#include "SoftwareRender.h"
#include <cmath>
#include <algorithm>
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
                               int renderHeight,
                               uint32_t* renderOutput) {
    // reset matrixes
    screenMatrix =
        Mat4::newTranslate(renderWidth/2.,renderHeight/2.,0) * 
        Mat4::newScale(renderWidth/2., - renderHeight/2.,1);
    setTransformMatrix(Mat4::newIdentity());
    width = renderWidth;
    height = renderHeight;
    pixels = renderOutput;
}

SoftwareRender::~SoftwareRender() {
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
void SoftwareRender::drawLine(Vec3f v1, Vec3f v2, uint32_t color) {
    v1 = transMatrix.transformVec(v1);
    v2 = transMatrix.transformVec(v2);
    if (!(isInClipBox(v1) && isInClipBox(v2)))
        return;
    //if (v1.z < 0)
    //std::cout << "v1: " << v1.x << ';' << v1.y << ';' << v1.z << endl;
    
    v1 = screenMatrix.transformVec(v1);
    v2 = screenMatrix.transformVec(v2);     
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

/**
 * @brief set new transform matrix
 * @param transMatrix new matrix
 */
void SoftwareRender::setTransformMatrix(Mat4 transMatrix) {
    this->transMatrix = transMatrix;
}
