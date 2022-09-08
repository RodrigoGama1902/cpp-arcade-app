#include "utils\Vec2D.h"
#include <iostream>

int main()
{

    Vec2D vec1(1, 4);
    Vec2D vec2(2, -2);

    std::cout << vec1 + vec2 << std::endl;
    std::cout << vec1 - vec2 << std::endl;
}