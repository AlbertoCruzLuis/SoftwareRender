#include "SDLApp.h"
#include "SDL2/SDL.h"
#include <algorithm>

/**
 * @brief Start instance of SDLApp
 * @param width window width
 * @param height window height
 * @param handler poiner to app handler object [IAppHandler]
 * @return 
 */
bool
SDLApp::start(unsigned int width, unsigned int height, IAppHandler* handler) {
    scrWidth = width;
    scrHeight = height;
    //Инициализация SDL
    sdlWindow = SDL_CreateWindow("Software renderer",
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 width,
                                 height,
                                 0);
    sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC);
    sdlTexture = SDL_CreateTexture(sdlRenderer,
                                   SDL_PIXELFORMAT_RGBA8888,
                                   SDL_TEXTUREACCESS_STREAMING,
                                   width,
                                   height);
    // Создаём экземпляр рендера
    renderer = new SoftwareRender(width, height);
    // Вызываем оперделяемый пользователем метод инициализации
    handler->onInit();
    // Main loop
    uint32_t lastTicks;
    uint32_t currentTicks;
    SDL_Event lastEvent;
    bool exitFlag = false;
    lastTicks = SDL_GetTicks();
    while(!exitFlag) {
        // Обработка логики
        SDL_PollEvent(&lastEvent);
        // Вызываем оперделяемый пользователем метод обработки логики
        handler->onProc(dt, lastEvent);
        if(lastEvent.type == SDL_QUIT) {
            exitFlag = true;
        } else if(lastEvent.type == SDL_KEYDOWN) {
            if(lastEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
                exitFlag = true;
        }
        // Рендер
        // Вызываем оперделяемый пользователем метод отрисовки
        handler->onDraw(*renderer);
        // Обновляем данные текстуры
        SDL_UpdateTexture(
            sdlTexture, nullptr, renderer->getPixelsPtr(), width * sizeof(uint32_t));
        // Очистка  экрана и копирования содержания текстуры на него
        SDL_RenderClear(sdlRenderer);
        SDL_RenderCopy(sdlRenderer, sdlTexture, nullptr, nullptr);
        // Выводим экран
        SDL_RenderPresent(sdlRenderer);
        // Обновление данных о delta time
        currentTicks = SDL_GetTicks();
        dt = (currentTicks - lastTicks) / 1000.0;
        lastTicks = currentTicks;
        SDL_SetWindowTitle(sdlWindow, std::to_string(dt).c_str());
    }
    // Вызываем оперделяемый пользователем метод завершения работы
    handler->onExit();
    return true;
}

/**
 * @brief get reference to instance of singleton
 * @return 
 */
SDLApp& SDLApp::getInstance() {
    static SDLApp inst;
    return inst;
}

SDLApp::SDLApp() {
}

SDLApp::~SDLApp() {
    delete renderer;
    SDL_DestroyTexture(sdlTexture);
    SDL_DestroyRenderer(sdlRenderer);
    SDL_Quit();
}

unsigned int SDLApp::getScreenHeight() {
    return scrHeight;
}

unsigned int SDLApp::getScreenWidth() {
    return scrWidth;
}

SoftwareRender& SDLApp::getRenderer() {
    return *renderer;
}
