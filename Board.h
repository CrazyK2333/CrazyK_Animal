#pragma once
#include"SingleBlock.h"



class Board
{

public:
    static Board& GetGlobalBoard();


     SingleBoardBlocksinfo* pB;
     Board(int NumBlockX, int NumBlockY);
    
     Board();
    
     ~Board();

     SingleBoardBlocksinfo* SearchBlockAtIndexXY(int i_x, int i_y);
    
    bool IsPointPlaceableAtIndexXY(const point& inpoint);

    class GridActor* SearchGridActorAtIndexXY(int x,int y,const std::vector<GridActor*>& ActorWareHouse);
   
    
    

};

