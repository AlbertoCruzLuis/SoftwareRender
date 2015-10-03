#ifndef SOFTWARERENDER_H
#define SOFTWARERENDER_H

#include <cstdint>

class SoftwareRender
{
private:
  unsigned int width, height;
  uint32_t* pixels;
  inline int pixelIndex(int x, int y);
  inline void setPixelUnsafe(int x, int y, uint32_t color);
public:
  SoftwareRender(int renderWidth, int renderHeight, uint32_t* renderOutput);
  ~SoftwareRender();
  void clear(uint32_t color);
  void setPixel(int x, int y, uint32_t color);
  void drawLine(int x1, int y1, int x2, int y2, uint32_t color);
};

#endif // SOFTWARERENDER_H
