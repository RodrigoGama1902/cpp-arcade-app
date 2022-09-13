#include "Screen.h"
#include "Vec2D.h"
#include "SDL2/SDL.h"
#include <iostream>
#include <cassert>

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

void Screen::ClearScreen()
{
    assert(moptrWindow);
    if (moptrWindow)
    {
        SDL_FillRect(mnoptrWindowSurface, nullptr, mClearColor.GetPixelColor()); // Fill the window surface with the clear color
    }
}
