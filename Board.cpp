#pragma once
#include"Board.h"
#include"Actor.h"

Board& Board::GetGlobalBoard()
{
    static Board GlobalBoard{ NUMBLOCK,NUMBLOCK };
    return GlobalBoard;
    // TODO: 在此处插入 return 语句
}

Board::Board(int NumBlockX, int NumBlockY)
{
    pB = new SingleBoardBlocksinfo[NumBlockX * NumBlockY];
    for (int i = 0; i < NumBlockX; i++)
    {
        for (int j = 0; j < NumBlockY; j++)
        {
            pB[i + NumBlockY * j].InitSingle(brushcolor::Black, i, j);
        }
    }
}
Board::Board()
{
    pB = nullptr;
}
Board::~Board()
{
    delete[] pB;
}
SingleBoardBlocksinfo* Board::SearchBlockAtIndexXY(int i_x, int i_y)
{

    if (LifeGameLib::inBoard(i_x, i_y))
    {
        return &pB[i_x + NUMBLOCK * i_y];
    }
    return nullptr;
}
//check whether this point is available for us to place a block
bool Board::IsPointPlaceableAtIndexXY(const point& inpoint)
{
    if (LifeGameLib::inBoard(inpoint.x, inpoint.y) && SearchBlockAtIndexXY(inpoint.x, inpoint.y)->blockcolor == brushcolor::Black)
        return true; 
    return false;
}
GridActor* Board::SearchGridActorAtIndexXY(int x,int y,const std::vector<GridActor*>& ActorWareHouse)
{
    
    if(ActorWareHouse.size()>0)
    {
        for(GridActor*CurActor:ActorWareHouse)
        {
            if(CurActor!=nullptr)
            {

                if (x <= CurActor->ZeroPoint.x + CurActor->width && x >= CurActor->ZeroPoint.x
                    && y <= CurActor->ZeroPoint.y + CurActor->height && y >= CurActor->ZeroPoint.y)
                {
                    return CurActor;

                }
            
            }
            
        }
        return nullptr;
    
    
    }

    return nullptr;
}
//extract alive slots of a line that you can place you block and return one of them .if no place for growing return false and the line is dead you can delete it from the linesets in side info sturct
