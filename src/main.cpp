#include "utils/Vec2D.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "graphics/Color.h"
#include "graphics/Screen.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int SCREEN_MAGNIFICATION = 3;

int main(int argc, char *argv[])
{

    Screen theScreen;

    theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_MAGNIFICATION);
    theScreen.Draw(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, Color::Red());
    theScreen.SwapScreen();

    // Event loop
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

    return 0;
}
