#include "AARectangle.h"
#include "Utils.h"
#include <cmath>

AARectangle::AARectangle() : AARectangle(Vec2D(0.0f, 0.0f), Vec2D(0.0f, 0.0f))
{
}

AARectangle::AARectangle(const Vec2D &topLeft, unsigned int width, unsigned int height)
{
    mPoints.push_back(topLeft);
    mPoints.push_back(Vec2D(topLeft.GetX() + width - 1, topLeft.GetY() + height - 1));
}

AARectangle::AARectangle(const Vec2D &topLeft, const Vec2D &bottomRight)
{
    mPoints.push_back(topLeft);
    mPoints.push_back(bottomRight);
}

float AARectangle::GetWidth() const
{
    return GetBottomRight().GetX() - GetTopLeft().GetX() + 1;
}

float AARectangle::GetHeight() const
{
    return GetBottomRight().GetY() - GetTopLeft().GetY() + 1;
}

void AARectangle::MoveTo(const Vec2D &newTopLeft)
{
    float width = GetWidth();
    float height = GetHeight();

    SetTopLeft(newTopLeft);
    SetBottomRight(Vec2D(newTopLeft.GetX() + width - 1, newTopLeft.GetY() + height - 1));
}

Vec2D AARectangle::GetCenterPoint() const
{
    return Vec2D(GetTopLeft().GetX() + GetWidth() / 2.0f, GetTopLeft().GetY() + GetHeight() / 2.0f);
}

bool AARectangle::Intersects(const AARectangle &other) const
{
    return !(GetTopLeft().GetX() > other.GetBottomRight().GetX() ||
             GetBottomRight().GetX() < other.GetTopLeft().GetX() ||
             GetTopLeft().GetY() > other.GetBottomRight().GetY() ||
             GetBottomRight().GetY() < other.GetTopLeft().GetY());
}

bool AARectangle::ContainsPoint(const Vec2D &point) const
{
    bool withinX = point.GetX() >= GetTopLeft().GetX() && point.GetX() <= GetBottomRight().GetX();
    bool withinY = point.GetY() >= GetTopLeft().GetY() && point.GetY() <= GetBottomRight().GetY();

    return withinX && withinY;
}

AARectangle AARectangle::Inset(const AARectangle &rect, float insets)
{
    return AARectangle(Vec2D(rect.GetTopLeft().GetX() + insets, rect.GetTopLeft().GetY() + insets), Vec2D(rect.GetBottomRight().GetX() - insets, rect.GetBottomRight().GetY() - insets));
}

std::vector<Vec2D> AARectangle::GetPoints() const
{
    std::vector<Vec2D> points;
    points.push_back(GetTopLeft());
    points.push_back(Vec2D(GetBottomRight().GetX(), GetTopLeft().GetY()));
    points.push_back(GetBottomRight());
    points.push_back(Vec2D(GetTopLeft().GetX(), GetBottomRight().GetY()));
    return points;
}