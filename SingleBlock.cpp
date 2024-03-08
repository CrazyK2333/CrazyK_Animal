#pragma once
#include"SingleBlock.h"

void SingleBoardBlocksinfo::InitSingle(brushcolor blockcolor, int x, int y)
{
 
    this->blockcolor = blockcolor;
    this->_X = x;
    this->_Y = y;
    int tmp = SingleBoardBlocksinfo::len;
    rec.left = x * tmp;
    rec.right = rec.left + tmp;
    rec.top = y * tmp;
    rec.bottom = rec.top + tmp;


}

void SingleBoardBlocksinfo::DrawMySelfAsRectangle(HDC memDc)
{
    if (blockcolor == brushcolor::Black);

    else if (blockcolor == brushcolor::White)
        FillRect(memDc, &rec, LifeGameLib::Whitebrush);
    else if (blockcolor == brushcolor::Pink)
        FillRect(memDc, &rec, LifeGameLib::Pinkbrush);
    else if (blockcolor == brushcolor::Blue)
        FillRect(memDc, &rec, LifeGameLib::Bluebrush);
    else if (blockcolor == brushcolor::LightPink)
        FillRect(memDc, &rec, LifeGameLib::LightPinkbrush);

}

void* SingleBoardBlocksinfo::FirstGridActorPointer()
{
    return this->GridActorPointer;
}

void* SingleBoardBlocksinfo::ChangePointer(void* inID)
{
    this->GridActorPointer = inID;
    return this;
    
}





