#include "utils\Vec2D.h"
#include <iostream>

int main()
{

    Vec2D vec1{7, 4};
    Vec2D vec2(vec1);

    Vec2D normalized(vec1.get_unit_vec());

    std::cout << normalized.Mag() << std::endl;
}