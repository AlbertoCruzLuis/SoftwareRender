#ifndef SDLAPP_H
#define SDLAPP_H

#include <SDL2/SDL.h>
#include <cstdint>
#include <IAppHandler.h>

#include <SoftwareRender.h>
/*
 * Класс-синглетон, ООП-обёотка над нужным для создания окна, по-пиксельной
 * отрисовки и робработки событий библиотеки SDL2.
 */
class SDLApp {
  private:
    //  Скрываем конструкторы, оператор присвоения, деструктор
    SDLApp();
    SDLApp(SDLApp& rhs);
    SDLApp& operator=(SDLApp& rhs);
    ~SDLApp();
    // Поля для работы с SDL
    SDL_Window* sdlWindow;
    SDL_Renderer* sdlRenderer;
    SDL_Texture* sdlTexture;
    // Экземпляр рендера
    SoftwareRender* renderer;
    // Для получения delta-time
    float dt;
    // Размеры экрана
    unsigned int scrWidth;
    unsigned int scrHeight;

  public:
    static SDLApp& getInstance();
    bool start(unsigned int width, unsigned int height, IAppHandler* handler);
    SoftwareRender& getRenderer();
    unsigned int getScreenWidth();
    unsigned int getScreenHeight();
};

#endif // SDLAPP_H
