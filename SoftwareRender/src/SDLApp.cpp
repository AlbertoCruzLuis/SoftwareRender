#include "SDLApp.h"
#include "SDL2/SDL.h"
#include <algorithm>

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
  // Выделение памяти под массив данных о экране, и инициализируем в 0xFFFFFFFF
  pixels = new uint32_t[width * height];
  std::fill_n(pixels, width * height, 0xFFFFFFFF);
  // Создаём экземпляр рендера
  renderer = new SoftwareRender(width, height, pixels);
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
    } else if (lastEvent.type == SDL_KEYDOWN) {
      if (lastEvent.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
        exitFlag = true;
    }
    // Рендер
    // Вызываем оперделяемый пользователем метод отрисовки
    handler->onDraw(*renderer);
    // Обновляем данные текстуры
    SDL_UpdateTexture(sdlTexture, nullptr, pixels, width * sizeof(uint32_t));
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

SDLApp& SDLApp::getInstance() {
  static SDLApp inst;
  return inst;
}

SDLApp::SDLApp() {
}

SDLApp::~SDLApp() {
  delete renderer;
  delete[] pixels;
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
