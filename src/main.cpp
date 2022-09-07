#include "Vec2D.h"
#include <iostream>

std::ostream &operator<<(std::ostream &ostream_ref, const Vec2D vec)
{
    ostream_ref << "(" << vec.x << ", " << vec.y << ")" << std::endl;
    return ostream_ref;
}

int main()
{

    Vec2D my_vector2d_null;

    my_vector2d_null.set_x(1);
    my_vector2d_null.set_y(2.1);

    std::cout << my_vector2d_null << std::endl;

    return 0;
}