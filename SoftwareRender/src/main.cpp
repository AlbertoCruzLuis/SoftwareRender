#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
#include "SDLApp.h"
#include "IAppHandler.h"
#include "Model.h"
#include "Vec4f.h"
#include "Mat4.h"
class TestApp : public IAppHandler {
  private:
    Model* model;
    Mat4 modelMatrix;
    Mat4 projMatrix;
    double time;
  public:
    virtual void onInit() {
        model = new Model("../data/model.obj");
        projMatrix = Mat4::newScale(100, 100, 100) 
                   * Mat4::newTranslate(4,4,200)
                   * Mat4::newPerspective(45*0.0174533,3./4.,0,100) ;
                   
        //projMatrix =   projMatrix ; 
        time = 0;
    };
    virtual void onDraw(SoftwareRender& render) {
        render.clear(0);
        // Матриц пока нет, поэтому делаем коррекции вот так, криво :D
        for(int i = 0; i < model->facesCount(); i++) {
            render.drawLine(model->vert(i, 0), model->vert(i, 1));
            render.drawLine(model->vert(i, 1), model->vert(i, 2));
            render.drawLine(model->vert(i, 2), model->vert(i, 0));
        }
    };
    virtual void onProc(double dt, SDL_Event& lastEvent){
        time += dt;
        modelMatrix = Mat4::newRotateY(time/3);
        SDLApp::getInstance().getRenderer().setTransformMatrix(projMatrix*modelMatrix);
    };
    virtual void onExit() {
        delete model;
    };
};

int main(int argc, char** argv) {
    Vec4f v;
    v[2] = 2;
    SDLApp& application = SDLApp::getInstance();
    TestApp appHandler;
    application.start(1024, 768, &appHandler);
    return 0;
}