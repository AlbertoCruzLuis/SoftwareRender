#ifndef SOFTWARERENDER_H
#define SOFTWARERENDER_H

#include <cstdint>
#include "Mat4.h"
#include "Vec3f.h"

class SoftwareRender {
  private:
    int width, height;
    uint32_t* pixels;
    // Matrix ndc => screen coords
    Mat4 screenMatrix;
    // Maint transform matrix ( = screen * trans)
    Mat4 transMatrix;
    inline int pixelIndex(int x, int y);
    inline void setPixelUnsafe(int x, int y, uint32_t color);
    inline bool isInClipBox(Vec3f v) const;

  public:
    SoftwareRender(int renderWidth, int renderHeight, uint32_t* renderOutput);
    ~SoftwareRender();
    void clear(uint32_t color);
    void setPixel(int x, int y, uint32_t color);
    void drawLine(Vec3f v1,
                  Vec3f v2,
                  uint32_t color = 0xFFFFFFFF,
                  bool direct = false);
    void drawTriangle(Vec3f verts[3], uint32_t color = 0xFFFFFFFF);
    void setTransformMatrix(Mat4 transMatrix);
};

#endif // SOFTWARERENDER_H
