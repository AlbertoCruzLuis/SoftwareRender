#ifndef IAPPHANDLER_H
#define IAPPHANDLER_H

#include <SoftwareRender.h>
#include <SDL2/SDL_events.h>
class SDLApp;

class IAppHandler {
public:  
  virtual void onInit() = 0;
  // Рендер как параметр для, более лаконичного вызова методов
  // отрисовки чего-либо
  virtual void onDraw(SoftwareRender& render) = 0;
  // Параметры - delta-time и последнее событие 
  virtual void onProc(double dt, SDL_Event& lastEvent) = 0;
  virtual void onExit() = 0;
};

#endif // IAPPHANDLER_H
