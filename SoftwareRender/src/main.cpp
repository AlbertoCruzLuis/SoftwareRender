#include <iostream>
#include <SDL2/SDL.h>
#include "SDLApp.h"
#include "IAppHandler.h"
#include "Model.h"

class TestApp : public IAppHandler {
private:  
  Model* model;
public:
  virtual void onInit() {
    model = new Model("../data/model.obj");
  };
  virtual void onDraw(SoftwareRender& render) {
    render.clear(0);
    // Матриц пока нет, по этому делаем коррекции вот так, криво :D
    for(int i = 0; i < model->facesCount(); i++) {
      render.drawLine(512 + (model->vert(i, 0).x) / 2 * 1024,
                      384 + (model->vert(i, 0).y) / 2 * 768,
                      512 + (model->vert(i, 1).x) / 2 * 1024,
                      384 + (model->vert(i, 1).y) / 2 * 768,
                      0xFFFFFFFF);
      render.drawLine(512 + (model->vert(i, 1).x) / 2 * 1024,
                      384 + (model->vert(i, 1).y) / 2 * 768,
                      512 + (model->vert(i, 2).x) / 2 * 1024,
                      384 + (model->vert(i, 2).y) / 2 * 768,
                      0xFFFFFFFF);
      render.drawLine(512 + (model->vert(i, 2).x) / 2 * 1024,
                      384 + (model->vert(i, 2).y) / 2 * 768,
                      512 + (model->vert(i, 0).x) / 2 * 1024,
                      384 + (model->vert(i, 0).y) / 2 * 768,
                      0xFFFFFFFF);
    }
  };
  virtual void onProc(double dt, SDL_Event& lastEvent){

  };
  virtual void onExit() {
    delete model;
  };
};

int main(int argc, char** argv) {
  SDLApp& application = SDLApp::getInstance();
  TestApp appHandler;
  application.start(1024, 768, &appHandler);
  return 0;
}