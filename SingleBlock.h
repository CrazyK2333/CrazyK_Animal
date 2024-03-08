
#pragma once
#include"point.h"
#include"LifeGameLib.h"

struct SingleBoardBlocksinfo
{
    
    static const int len = BLOCKLENGTH;
    brushcolor blockcolor{ brushcolor::Black }; //0 unplaced 1 placed with white 2 placed with pink;
    int _X{ 0 };
    int _Y{ 0 };
    RECT rec;
    void InitSingle(brushcolor blockcolor, int x, int y);
   
    void DrawMySelfAsRectangle(HDC memDc);

    void* GridActorPointer=nullptr;

    void* FirstGridActorPointer();

    void* ChangePointer(void* inID);

    


};




