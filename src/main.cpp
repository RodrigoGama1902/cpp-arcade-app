#include "utils/Vec2D.h"
#include <iostream>
#include "SDL2/SDL.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

int main(int argc, char *argv[])
{

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window *optrWindow = SDL_CreateWindow("Arcade",
                                              SDL_WINDOWPOS_CENTERED,
                                              SDL_WINDOWPOS_CENTERED,
                                              SCREEN_WIDTH,
                                              SCREEN_HEIGHT,
                                              SDL_WINDOW_SHOWN);

    if (optrWindow == nullptr)
    {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Event sdlEvent;
    bool running = true;

    while (running)
    {
        while (SDL_PollEvent(&sdlEvent))
        {
            switch (sdlEvent.type)
            {
            case SDL_QUIT:
                running = false;
                break;
            }
        }
    }

    SDL_DestroyWindow(optrWindow);
    SDL_Quit();

    return 0;
}