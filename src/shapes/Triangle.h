#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape
{

public:
    Triangle();
    Triangle(const Vec2D &point1, const Vec2D &point2, const Vec2D &point3);

    inline void SetP0(const Vec2D &point) { mPoints[0] = point; }
    inline void SetP1(const Vec2D &point) { mPoints[1] = point; }
    inline void SetP2(const Vec2D &point) { mPoints[2] = point; }

    inline Vec2D GetP0() const { return mPoints[0]; }
    inline Vec2D GetP1() const { return mPoints[1]; }
    inline Vec2D GetP2() const { return mPoints[2]; }

    virtual Vec2D GetCenterPoint() const override;
    virtual std::vector<Vec2D> GetPoints() const override;

    float GetArea() const;

    bool ConstainsPoint(const Vec2D &point) const;

private:
    float GetArea(const Vec2D &p0, const Vec2D &p1, const Vec2D &p2) const;
};

#endif