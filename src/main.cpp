
#include <iostream>
#include "app/App.h"

const int SCREEN_WIDTH = 224;
const int SCREEN_HEIGHT = 288;
const int SCREEN_MAG = 3;

int main(int argc, const char *argv[])
{
    if (App::Singleton().Init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_MAG))
    {
        App::Singleton().Run();
    }

    return 0;
}
