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
    float n = 1;
    float f = 5;
    double time;
  public:
    virtual void onInit() {
        // load our model of head
        model = new Model("../data/model.obj");
        modelMatrix = Mat4::newTranslate(0,0,-2);
        time = 0;
    };
    virtual void onDraw(SoftwareRender& render) {
        render.setTransformMatrix(projMatrix * modelMatrix * tMat);
        render.clear(0);        
        Vec3f tri[3];
        for(int i = 0; i < model->facesCount(); i++) {
            for (int j = 0; j < 3; j++)
                tri[j] = model->vert(i, j);
            render.drawTriangle(tri);
        }
    };
    virtual void onProc(double dt, SDL_Event& lastEvent){
        time += dt;
        
        if (lastEvent.type == SDL_KEYDOWN) {
            if (lastEvent.key.keysym.scancode == SDL_SCANCODE_1)
                n -= 0.05;
            if (lastEvent.key.keysym.scancode == SDL_SCANCODE_2)
                n += 0.05;                
            if (lastEvent.key.keysym.scancode == SDL_SCANCODE_3)
                f -= 0.05;
            if (lastEvent.key.keysym.scancode == SDL_SCANCODE_4)
                f += 0.05;    
           std::cout << "n:" << n << "; f:" << f << std::endl;
        }   
        projMatrix = 
            Mat4::newPerspective(75 * DEG2RAD, 4./3., n, f);
        tMat =  
            Mat4::newRotateX(time/2) * 
            Mat4::newRotateY(time/2) * 
            Mat4::newRotateZ(time/2);
        
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