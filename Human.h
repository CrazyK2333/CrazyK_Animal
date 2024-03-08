#pragma once
#include"Actor.h"
#include"Component.h"
class Human :public GridActor
{
public:
	
	float mLastMoveElapsed{ 0 };

	virtual void UpDate(float IntervalTime);

	Human(int inwidth, int inheight) :GridActor(inwidth, inheight,"Human")
	{


	}

	Human(class Board* inOriginBoard, int inwidth, int inheight, struct point inZeroPoint, std::string inActorName/*, brushcolor inColor*/);



};