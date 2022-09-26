#ifndef _AARETANGLE_H_
#define _AARETANGLE_H_

#include "Shape.h"

class AARectangle : public Shape
{
public:
    AARectangle();
    AARectangle(const Vec2D &topLeft, unsigned int width, unsigned int height);
    AARectangle(const Vec2D &topLeft, const Vec2D &bottomRight);

    inline void SetTopLeft(const Vec2D &topLeft) { mPoints[0] = topLeft; };
    inline void SetBottomRight(const Vec2D &bottomRight) { mPoints[1] = bottomRight; }

    Vec2D GetTopLeft() const { return mPoints[0]; }
    Vec2D GetBottomRight() const { return mPoints[1]; }

    float GetWidth() const;
    float GetHeight() const;

    void MoveTo(const Vec2D &newTopLeft);

    virtual Vec2D GetCenterPoint() const override;

    bool Intersects(const AARectangle &other) const;
    bool ContainsPoint(const Vec2D &point) const;

    static AARectangle Inset(const AARectangle &rect, float insets);

    virtual std::vector<Vec2D> GetPoints() const override;
};

#endif