#include "Triangle.h"
#include <cmath>
#include "Utils.h"

Triangle::Triangle(const Vec2D &point1, const Vec2D &point2, const Vec2D &point3)
{
    mPoints.push_back(point1);
    mPoints.push_back(point2);
    mPoints.push_back(point3);
}

Vec2D Triangle::GetCenterPoint() const
{
    return Vec2D((mPoints[0].GetX() + mPoints[1].GetX() + mPoints[2].GetX()) / 3.0f, (mPoints[0].GetY() + mPoints[1].GetY() + mPoints[2].GetY()) / 3.0f);
}

float Triangle::GetArea() const
{
    return GetArea(mPoints[0], mPoints[1], mPoints[2]);
}

float Triangle::GetArea(const Vec2D &p0, const Vec2D &p1, const Vec2D &p2) const
{
    return std::abs((p0.GetX() * (p1.GetY() - p2.GetY()) + p1.GetX() * (p2.GetY() - p0.GetY()) + p2.GetX() * (p0.GetY() - p1.GetY())) / 2.0f);
}

bool Triangle::ConstainsPoint(const Vec2D &point) const
{
    float thisArea = GetArea();

    float a1 = GetArea(point, GetP1(), GetP2());
    float a2 = GetArea(GetP0(), point, GetP2());
    float a3 = GetArea(GetP0(), GetP1(), point);

    return is_equal(thisArea, a1 + a2 + a3);

    return false;
}

std::vector<Vec2D> Triangle::GetPoints() const
{
    return mPoints;
}