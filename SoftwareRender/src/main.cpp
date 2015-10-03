#include <iostream>
#include <SDL2/SDL.h>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include "SDLApp.h"
#include "IAppHandler.h"

const float PI = 3.14;

class TestApp : public IAppHandler {

public:
  virtual void onDraw(SoftwareRender& render) {
    //render.clear(0);
    int cx = 400, cy = 400;
    int r = 50 + std::rand() % 200;
    uint32_t color = ((std::rand() % 0xFFFFFF) << 8)|0xFF;
    for(float i = 0; i < 2 * PI; i += PI / 512.0) {
      render.drawLine(cx,
                      cy,
                      cx + std::cos(i) * r,
                      cy + std::sin(i) * r,
                      color);
    }
  };
  virtual void onExit(){

  };
  virtual void onInit(){

  };
  virtual void onProc(double dt, SDL_Event& lastEvent){

  };
};

int main(int argc, char** argv) {
  SDLApp& application = SDLApp::getInstance();
  TestApp appHandler;
  application.start(1024, 768, &appHandler);
  return 0;
}