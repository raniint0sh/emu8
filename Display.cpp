#include "Display.h"


Display::Display(){

}

Display::~Display(){

}

int Display::Run(){

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("SDL3 Window", 640, 480, 0);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Delay(3000);  // Keep the window open for 3 seconds

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;

}
