#include "Vec2D.h"
#include "Utils.h"

#include <cassert>
#include <cmath>
#include <iostream>

const Vec2D Vec2D::Zero;

//------------------------------
// Constructor
//------------------------------

Vec2D::Vec2D()
    : x{0}, y{0}
{
}

Vec2D::Vec2D(float x, float y)
    : x{x}, y{y}
{
}

Vec2D::Vec2D(const Vec2D &src)
    : x{src.x}, y{src.y}
{
    std::cout << "Copy Constructor" << std::endl;
}

//------------------------------
// Friend Functions
//------------------------------

Vec2D operator*(float scalar, const Vec2D &vec)
{
    return vec * scalar;
}

std::ostream &operator<<(std::ostream &ostream_ref, const Vec2D vec)
{
    ostream_ref << "(" << vec.x << ", " << vec.y << ")" << std::endl;
    return ostream_ref;
}

//------------------------------
// Getters/Setters Methods
//------------------------------

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

//------------------------------
// Class Methods
//------------------------------

float Vec2D::Mag2() const
{
    return x * x + y * y;
}
float Vec2D::Mag() const
{
    return sqrt(Mag2());
}

Vec2D Vec2D::get_unit_vec() const
{

    float mag = Mag();

    if (mag > EPSILON)
    {
        return *this / mag;
    }

    return Vec2D::Zero;
}

Vec2D &Vec2D::normalize()
{
    float mag = Mag();

    if (mag > EPSILON)
    {
        *this /= mag;
    }

    return *this;
}

float Vec2D::Distance(const Vec2D &vec) const
{
    return (vec - *this).Mag();
}

//------------------------------
// Unary Operator Overload
//------------------------------

Vec2D Vec2D::operator-() const
{
    return Vec2D(-x, -y);
}

//------------------------------
// Binary Operator Overload
//------------------------------

bool Vec2D::operator==(const Vec2D &vec2) const
{
    return is_equal(x, vec2.x) && is_equal(y, vec2.y);
}

bool Vec2D::operator!=(const Vec2D &vec2) const
{
    return !(*this == vec2);
}

Vec2D Vec2D::operator*(float scalar) const
{
    return Vec2D(x * scalar, y * scalar);
}

Vec2D Vec2D::operator/(float scale) const
{
    assert(fabsf(scale) > EPSILON);
    return Vec2D(x / scale, y / scale);
}

Vec2D Vec2D::operator+(const Vec2D &vec2) const
{
    return Vec2D(x + vec2.x, y + vec2.y);
}

Vec2D Vec2D::operator-(const Vec2D &vec2) const
{
    return Vec2D(x - vec2.x, y - vec2.y);
}

Vec2D &Vec2D::operator*=(float scale)
{
    *this = *this * scale;
    return *this;
}

Vec2D &Vec2D::operator/=(float scale)
{
    assert(fabsf(scale) > EPSILON);
    *this = *this / scale;
    return *this;
}

Vec2D &Vec2D::operator+=(const Vec2D &vec2)
{
    *this = *this + vec2;
    return *this;
}

Vec2D &Vec2D::operator-=(const Vec2D &vec2)
{
    *this = *this - vec2;
    return *this;
}