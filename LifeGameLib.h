// header.h: 标准系统包含文件的包含文件，
// 或特定于项目的包含文件
//

#pragma once

#include "BasicDefines.h"


class LifeGameLib
{
public:
    static bool inBoard(int i_x, int i_y)
    {
        return i_x < NUMBLOCK && i_x >= 0 && i_y < NUMBLOCK && i_y >= 0;
    }

    static bool inRange(int x1, int x2, int value)
    {
        return (value >= x1 && value <= x2) || (value >= x2 && value <= x1);
    }

    static void ActualPointToIndexPoint(int x, int y, int& i_x, int& i_y)
    {
        i_x = x / BLOCKLENGTH;
        i_y = y / BLOCKLENGTH;;
    }

    static void IndexPointToActualPoint(int i_x, int i_y, int& x, int& y)
    {
        x = i_x * BLOCKLENGTH + BLOCKLENGTH / 2;
        y = i_y * BLOCKLENGTH + BLOCKLENGTH / 2;
    }

    static HBRUSH Pinkbrush;
    static HBRUSH Whitebrush;
    static HBRUSH Bluebrush;
    static HBRUSH LightPinkbrush;

};

