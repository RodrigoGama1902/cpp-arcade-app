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

private:
    float x;
    float y;
};

#endif