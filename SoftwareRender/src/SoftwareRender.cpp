#include "SoftwareRender.h"
#include <cmath>
#include <algorithm>

using namespace std;

/* PUBLIC */

SoftwareRender::SoftwareRender(int renderWidth,
                               int renderHeight,
                               uint32_t* renderOutput) {
  width = renderWidth;
  height = renderHeight;
  pixels = renderOutput;  
}

SoftwareRender::~SoftwareRender() {
}

void SoftwareRender::setPixel(int x, int y, uint32_t color) {
  if ((x < width) && (y < height) && (x >= 0) && (y >= 0))
    pixels[pixelIndex(x,y)] = color;
}



/* PRIVATE */

void SoftwareRender::clear(uint32_t color) {
  std::fill_n(pixels, width * height, color);
}

int SoftwareRender::pixelIndex(int x, int y) {
  return ((height-y)*width + x);
}

void SoftwareRender::setPixelUnsafe(int x, int y, uint32_t color) {
  pixels[pixelIndex(x,y)] = color;
}

void SoftwareRender::drawLine(int x1, int y1, int x2, int y2, uint32_t color) {
  // В какую сторону смещаемся.
  int dx = (x2 - x1 >= 0 ? 1 : -1);
  int dy = (y2 - y1 >= 0 ? 1 : -1);
  // Проекции на оси
  int lengthX = abs(x2 - x1);
  int lengthY = abs(y2 - y1);
  //  Не является ли отрезок точкой
  int length = max(lengthX, lengthY);
  if (length == 0)
  {
        setPixel(x1, y1, color);
  }
  // Основная ось - X
  if (lengthY <= lengthX)
  {
        // Начальные значения
        int x = x1;
        int y = y1;
        int d = -lengthX;

        // Основной цикл
        length++;
        while(length--)
        {
              setPixel(x, y, color);
              x += dx;
              d += lengthY << 1; // * 2
              if (d > 0) {
                    d -= lengthX << 1; 
                    y += dy;
              }
        }
  }
  else
  {
        // Начальные значения
        int x = x1;
        int y = y1;
        int d = - lengthY;

        // Основной цикл
        length++;
        while(length--)
        {
              setPixel(x, y, color);
              y += dy;
              d += lengthX << 1;
              if (d > 0) {
                    d -= lengthY << 1;
                    x += dx;
              }
        }
  }
}