#include "Vec2D.h"

Vec2D::Vec2D()
    : x{0}, y{0}
{
}

Vec2D::Vec2D(float x, float y)
    : x{x}, y{y}
{
}

float Vec2D::get_x()
{
    return this->x;
}

float Vec2D::get_y()
{
    return this->y;
}

void Vec2D::set_x(float input_x)
{
    this->x = input_x;
}

void Vec2D::set_y(float input_y)
{
    this->y = input_y;
}
