#ifndef IAPPHANDLER_H
#define IAPPHANDLER_H

#include <SoftwareRender.h>
#include <SDL2/SDL_events.h>
class SDLApp;

/**
 * @class IAppHandler
 * @brief interface of app handler
 */
class IAppHandler {
public:
    /**
    * @brief on app init
    */
    virtual void onInit() = 0;
    /**
     * @brief on each frame draw
     * @param render passed by renderer, current renderer reference
     */
    virtual void onDraw(SoftwareRender& render) = 0;
    /**
     * @brief after each frame
     * @param dt time from last onProc invoke
     * @param lastEvent last SDL event (pool)
     */
    virtual void onProc(double dt, SDL_Event& lastEvent) = 0;
    /**
     * @brief on app exit
     */
    virtual void onExit() = 0;
};

#endif // IAPPHANDLER_H
