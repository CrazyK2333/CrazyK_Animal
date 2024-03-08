#pragma once

#include"BasicDefines.h"
struct point
{
public:
    int x;
    int y;
    point() {}
    point(int _x, int _y) :x(_x), y(_y) {}
    bool operator==(const point& input)
    {

        if (x == input.x && y == input.y)
        {

            return true;
        }
        else
            return false;
    }
    point operator+(const point& addpoint)
    {
        return point(addpoint.x + x, addpoint.y + y);
    }
    point operator-(const point& addpoint)
    {
        return point(-addpoint.x + x, -addpoint.y + y);
    }
    point& operator+=(const point&addpoint)
    {
        this->x += addpoint.x ;
        this->y += addpoint.y ;
        return *this;
    
    }
    point& operator-=(const point& addpoint)
    {
        this->x -= addpoint.x;
        this->y -= addpoint.y;
        return *this;
    
    }
};