#include <iostream>
#include <SDL2/SDL.h>
#include <cmath>
#include "SDLApp.h"
#include "IAppHandler.h"
#include "Model.h"
#include "Vec4f.h"
#include "Mat4.h"

const float DEG2RAD = 0.0174533;

// Test App class
class TestApp : public IAppHandler {
  private:
    Model* model;
    Mat4 modelMatrix;
    Mat4 projMatrix;
    Mat4 tMat;
    double time;
  public:
    virtual void onInit() {
        // load our model of head
        model = new Model("../data/model.obj");
        modelMatrix =  Mat4::newTranslate(0,0,-1.7) * Mat4::newScale(0.5,0.5,0.5);
        time = 0;
        //projMatrix = Mat4::newOrtho(1,1,1,10);
        projMatrix = 
            Mat4::newPerspective(45 * DEG2RAD, 4./3., 1, 100);
    };
    virtual void onDraw(SoftwareRender& render) {
        render.setTransformMatrix(projMatrix * modelMatrix * tMat);
        render.clear(0);        
        ModelVert tri[3];
            
        for(int i = 0; i < model->vertsCount(); i+=3) {
            for (int j = i; j < i+3; j++) {
                tri[j-i] = model->vert(j);
            }
            render.drawTriangle(tri);
        }

    };
    virtual void onProc(double dt, SDL_Event& lastEvent){
        time += dt;
        tMat =  
            //Mat4::newTranslate(0,0,std::sin(time/2)) * 
            Mat4::newRotateX(time/4) * 
            Mat4::newRotateY(time/4) * 
            Mat4::newRotateZ(time/4);
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