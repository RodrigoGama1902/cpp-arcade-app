#include "utils/Vec2D.h"
#include <iostream>
#include "SDL2/SDL.h"
#include "graphics/Color.h"
#include "graphics/Screen.h"
#include "Line2D.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int SCR_MAG = 3; // Screen magnification

int LAST_X = -1;
int LAST_Y = -1;

void draw_on_mouse_click(Screen &theScreen)
{
    int x, y;

    uint32_t buttons = SDL_GetMouseState(&x, &y);

    if ((buttons & SDL_BUTTON_LMASK) != 0)
    {
        if (LAST_X != -1 && LAST_Y != -1)
        {
            Line2D line(LAST_X, LAST_Y, x / SCR_MAG, y / SCR_MAG);
            theScreen.Draw(line, Color::Red());
        }
        else
        {
            theScreen.Draw(x / SCR_MAG, y / SCR_MAG, Color::Red());
        }

        LAST_X = x / SCR_MAG;
        LAST_Y = y / SCR_MAG;
    }

    theScreen.SwapScreen(true);
}

int main(int argc, char *argv[])
{

    uint32_t SDL_GetMouseState(int *x, int *y);

    Screen theScreen;

    theScreen.Init(SCREEN_WIDTH, SCREEN_HEIGHT, SCR_MAG);

    // Line2D line1(Vec2D(SCREEN_WIDTH, SCREEN_HEIGHT), Vec2D(0, 0));
    // theScreen.Draw(line1, Color::Red());

    // theScreen.SwapScreen();

    SDL_Event sdlEvent;

    bool running = true;
    bool drawing = false;

    while (running)
    {
        while (SDL_PollEvent(&sdlEvent))
        {

            switch (sdlEvent.type)
            {

            case SDL_MOUSEBUTTONDOWN:
                drawing = true;
                break;

            case SDL_MOUSEBUTTONUP:
                drawing = false;
                LAST_X = -1;
                LAST_Y = -1;
                break;

            case SDL_MOUSEMOTION:
                if (drawing)
                {
                    draw_on_mouse_click(theScreen);
                }
                break;

            case SDL_QUIT:
                running = false;
                break;
            }
        }
    }

    return 0;
}
