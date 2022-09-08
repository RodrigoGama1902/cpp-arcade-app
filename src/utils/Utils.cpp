#include "Utils.h"
#include <cmath>

bool is_equal(float x, float y)
{
    return fabsf(x - y) < EPSILON;
}

bool is_greater_than_or_equal(float x, float y)
{
    return x > y || is_equal(x, y);
}

bool is_less_than_or_equal(float x, float y)
{
    return x < y || is_equal(x, y);
}