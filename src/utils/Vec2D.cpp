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
    return Dot(*this);
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

float Vec2D::Dot(const Vec2D &vec) const
{
    return x * vec.x + y * vec.y;
}

Vec2D Vec2D::ProjectOnto(const Vec2D &vec2) const
{

    Vec2D unitVec2 = vec2.get_unit_vec();

    float dot = Dot(unitVec2);

    return unitVec2 * dot;
}

float Vec2D::AngleBetween(const Vec2D &vec2) const
{

    return acosf(get_unit_vec().Dot(vec2.get_unit_vec()));
}

Vec2D Vec2D::Reflect(const Vec2D &normal) const
{

    return *this - 2 * ProjectOnto(normal);
}

void Vec2D::Rotate(float angle, const Vec2D &aroundPoint)
{

    float cosine = cosf(angle);
    float sine = sinf(angle);

    Vec2D thisVec(x, y);

    thisVec -= aroundPoint;

    float xRot = thisVec.x * cosine - thisVec.y * sine;
    float yRot = thisVec.x * sine + thisVec.y * cosine;

    Vec2D rot = Vec2D(xRot, yRot);

    *this = rot + aroundPoint;
}
Vec2D Vec2D::RotationResult(float angle, const Vec2D &aroundPoint) const
{

    float cosine = cosf(angle);
    float sine = sin(angle);

    Vec2D thisVec(x, y);

    thisVec -= aroundPoint;

    float xRot = thisVec.x * cosine - thisVec.y * sine;
    float yRot = thisVec.x * sine + thisVec.y * cosine;

    Vec2D rot = Vec2D(xRot, yRot);

    return rot + aroundPoint;
}