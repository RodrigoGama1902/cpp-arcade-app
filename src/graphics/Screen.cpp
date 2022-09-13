#include "Screen.h"
#include "Vec2D.h"
#include "Line2D.h"
#include "SDL2/SDL.h"
#include <iostream>
#include <cassert>
#include <cmath>

Screen::Screen() : mWidth(0), mHeight(0), moptrWindow(nullptr), mnoptrWindowSurface(nullptr)
{
}

Screen::~Screen()
{
    if (moptrWindow)
    {
        SDL_DestroyWindow(moptrWindow);
        moptrWindow = nullptr;
    }

    SDL_Quit();
}

SDL_Window *Screen::Init(uint32_t w, uint32_t h, uint32_t mag)
{

    // Initialize SDL

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    mWidth = w;
    mHeight = h;

    // Create a window

    moptrWindow = SDL_CreateWindow("Arcade",
                                   SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED,
                                   mWidth * mag,
                                   mHeight * mag,
                                   SDL_WINDOW_SHOWN);

    if (moptrWindow)
    {
        // Create a renderer

        mnoptrWindowSurface = SDL_GetWindowSurface(moptrWindow);
        SDL_PixelFormat *pixelFormat = mnoptrWindowSurface->format;

        Color::InitColorFormat(pixelFormat); // Initialize color format, so it will be the same as the window surface

        mClearColor = Color::Black();

        mBackBuffer.Init(pixelFormat->format, mWidth, mHeight); // Initialize screen buffer
        mBackBuffer.Clear(mClearColor);
    }

    return moptrWindow;
}

void Screen::SwapScreen()
{
    assert(moptrWindow);
    if (moptrWindow)
    {
        ClearScreen();

        SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, mnoptrWindowSurface, nullptr); // Blit the created screenBuffer pixels to the window surface

        SDL_UpdateWindowSurface(moptrWindow); // Update the window surface so the changed pixels will be shown

        mBackBuffer.Clear(mClearColor); // Clear the screen buffer
    }
}

void Screen::Draw(int x, int y, const Color &color)
{
    assert(moptrWindow);
    if (moptrWindow)
    {
        mBackBuffer.SetPixel(color, x, y);
    }
}

void Screen::Draw(const Vec2D &point, const Color &color)
{
    assert(moptrWindow);
    if (moptrWindow)
    {
        mBackBuffer.SetPixel(color, point.GetX(), point.GetY());
    }
}

void Screen::Draw(const Line2D &line, const Color &color)
{
    assert(moptrWindow);
    if (moptrWindow)
    {
        int dx, dy;

        int x0 = roundf(line.GetP0().GetX());
        int y0 = roundf(line.GetP0().GetY());
        int x1 = roundf(line.GetP1().GetX());
        int y1 = roundf(line.GetP1().GetY());

        dx = x1 - x0;
        dy = y1 - y0;

        signed const char ix((dx > 0) - (dx < 0)); // evaluate to 1 or -1
        signed const char iy((dy > 0) - (dy < 0));

        dx = abs(dx) * 2;
        dy = abs(dy) * 2;

        Draw(x0, y0, color);

        if (dx >= dy)
        {
            int d = dy - dx / 2;

            while (x0 != x1)
            {
                if (d >= 0)
                {
                    d -= dx;
                    y0 += iy;
                }
                d += dy;
                x0 += ix;

                Draw(x0, y0, color);
            }
        }
        else
        {
            int d = dx - dy / 2;

            while (y0 != y1)
            {
                if (d >= 0)
                {
                    d -= dy;
                    x0 += ix;
                }
                d += dx;
                y0 += iy;

                Draw(x0, y0, color);
            }
        }
    }
}

void Screen::ClearScreen()
{
    assert(moptrWindow);
    if (moptrWindow)
    {
        SDL_FillRect(mnoptrWindowSurface, nullptr, mClearColor.GetPixelColor()); // Fill the window surface with the clear color
    }
}
