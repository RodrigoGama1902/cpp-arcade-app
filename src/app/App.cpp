
#include "App.h"
#include "SDL2/SDL.h"
#include "Line2D.h"

App &App::Singleton()
{
    static App theApp;
    return theApp;
}

bool App::Init(uint32_t width, uint32_t height, uint32_t mag)
{
    mnoptrWindow = mScreen.Init(width, height, mag);
    return mnoptrWindow != nullptr;
}

void App::Run()
{
    if (mnoptrWindow)
    {

        Line2D line1(Vec2D(mScreen.Width(), mScreen.Height()), Vec2D(0, 0));

        uint32_t lastTick = SDL_GetTicks();
        uint32_t currentTick = lastTick;

        uint32_t dt = 10;
        uint32_t accumulator = 0;

        SDL_Event sdlEvent;

        bool running = true;

        while (running)
        {

            currentTick = SDL_GetTicks();
            uint32_t frameTime = currentTick - lastTick;

            if (frameTime > 300)
            {
                frameTime = 300;
            }

            lastTick = currentTick;
            accumulator += frameTime;

            while (SDL_PollEvent(&sdlEvent))
            {

                switch (sdlEvent.type)
                {
                case SDL_QUIT:
                    running = false;
                    break;
                }
            }

            while (accumulator >= dt)
            {
                // Update current scene by dt
                accumulator -= dt;
            }

            // Render
            mScreen.Draw(line1, Color::Red());

            mScreen.SwapScreen();
        }
    }
}