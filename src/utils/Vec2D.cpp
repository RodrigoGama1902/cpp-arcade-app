#include "Vec2D.h"
#include "Utils.h"

#include <cassert>
#include <cmath>

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

float Vec2D::mag2() const
{
    return x * x + y + y;
}
float Vec2D::mag() const
{
    return sqrt(mag2());
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