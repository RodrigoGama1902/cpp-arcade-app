#include "utils/Vec2D.h"
#include <iostream>
#include "SDL2/SDL.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;

void SetPixel(SDL_Surface *noptrWindowSurface, uint32_t color, int x, int y);

size_t GetIndex(SDL_Surface *noptrSurface, int r, int c);

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

    SDL_Surface *noptrWindowSurface = SDL_GetWindowSurface(optrWindow);

    SDL_PixelFormat *noptrFormat = noptrWindowSurface->format;

    std::cout << "The window pixel format is: " << SDL_GetPixelFormatName(noptrFormat->format) << std::endl;

    uint32_t color = 0xFF0000;

    SetPixel(noptrWindowSurface, color, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    SDL_UpdateWindowSurface(optrWindow);

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

void SetPixel(SDL_Surface *noptrWindowSurface, uint32_t color, int x, int y)
{
    SDL_LockSurface(noptrWindowSurface);

    uint32_t *pixels = (uint32_t *)noptrWindowSurface->pixels;

    size_t index = GetIndex(noptrWindowSurface, y, x);

    pixels[index] = color;

    SDL_UnlockSurface(noptrWindowSurface);
}

size_t GetIndex(SDL_Surface *noptrSurface, int r, int c)
{
    return r * noptrSurface->w + c;
}