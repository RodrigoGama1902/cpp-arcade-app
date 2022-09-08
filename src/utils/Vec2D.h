#ifndef _VEC2D_H_
#define _VEC2D_H_

#include <ostream>

class Vec2D
{
public:
    Vec2D();
    Vec2D(float x, float y);

    float get_x();
    float get_y();
    void set_x(float x);
    void set_y(float y);

    friend std::ostream &operator<<(std::ostream &ostream_ref, const Vec2D vec);

    bool operator==(const Vec2D &vec2) const;
    bool operator!=(const Vec2D &vec2) const;

    Vec2D operator-() const;            // unary minus - Negating vector
    Vec2D operator*(float scale) const; // scalar multiplication
    Vec2D operator/(float scale) const;
    Vec2D operator+(const Vec2D &vec2) const;
    Vec2D operator-(const Vec2D &vec2) const;
    Vec2D &operator*=(float scale);
    Vec2D &operator/=(float scale);

    friend Vec2D operator*(float scalar, const Vec2D &vec);

private:
    float x;
    float y;
};

#endif