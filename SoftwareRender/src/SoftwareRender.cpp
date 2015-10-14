#include "SoftwareRender.h"
#include <cmath>
#include <algorithm>
#include "Vec3f.h"
#include "Vec2f.h"
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

void SoftwareRender::drawTriangle(Vec3f modelVerts[3], uint32_t color) {
    
    Vec3f verts3D[3] =  {
        transMatrix.transformVec(modelVerts[0]),
        transMatrix.transformVec(modelVerts[1]),
        transMatrix.transformVec(modelVerts[2])};   
 /*
    if (verts3D[0].y>verts3D[1].y) std::swap(verts3D[0], verts3D[1]);
    if (verts3D[0].y>verts3D[2].y) std::swap(verts3D[0], verts3D[2]);
    if (verts3D[1].y>verts3D[2].y) std::swap(verts3D[1], verts3D[2]);
            */
    if(!(isInClipBox(verts3D[0]) && isInClipBox(verts3D[1]) &&
         isInClipBox(verts3D[2])))
        return;
    Vec2f verts[3];
    for (int i = 0; i < 3; i++) {
        Vec3f tmpVec;
        tmpVec = screenMatrix.transformVec(verts3D[i]); 
        verts[i].x = tmpVec.x;
        verts[i].y = tmpVec.y;
    }



    Vec3f n = ((verts3D[1]-verts3D[0])^(verts3D[2]-verts3D[0])).norm();
    float intensity = n*Vec3f(0,0,1);
    std::cout << intensity << ";  " <<endl;
    
    if (intensity < 0)
        return;
    
    if (verts[0].y>verts[1].y) std::swap(verts[0], verts[1]);
    if (verts[0].y>verts[2].y) std::swap(verts[0], verts[2]);
    if (verts[1].y>verts[2].y) std::swap(verts[1], verts[2]);
    
    if (verts[0].y==verts[1].y && verts[0].y==verts[2].y) 
        return; 
    // sort the verts3D by y
    int total_height = verts[2].y-verts[0].y;
    for (int i=0; i<total_height; i++) {
        bool second_half = i>verts[1].y-verts[0].y || verts[1].y==verts[0].y;
        int segment_height = second_half ? verts[2].y-verts[1].y : verts[1].y-verts[0].y;
        float alpha = (float)i/total_height;
        float beta  = (float)(i-(second_half ? verts[1].y-verts[0].y : 0))/segment_height; // be careful: with above conditions no division by zero here
        Vec2f A =               verts[0] + (verts[2]-verts[0])*alpha;
        Vec2f B = second_half ? verts[1] + (verts[2]-verts[1])*beta : verts[0] + (verts[1]-verts[0])*beta;
        if (A.x>B.x) std::swap(A, B);
        for (int j=A.x; j<=B.x; j++) {
            uint8_t c = (uint8_t)(0xFF*intensity);
            uint32_t cc = (c<<24)|(c<<16)|(c<<8)|0xFF;
            setPixel(j,(int)(verts[0].y+i),cc);
        }
    }

/*
    if (intensity>0) {
        drawLine(verts[0],verts[1],0xFFFFFFFF,true);
        drawLine(verts[1],verts[2],0xFFFFFFFF,true);
        drawLine(verts[2],verts[0],0xFFFFFFFF,true);
    }*/

}

/**
 * @brief set new transform matrix
 * @param transMatrix new matrix
 */
void SoftwareRender::setTransformMatrix(Mat4 transMatrix) {
    this->transMatrix = transMatrix;
}
