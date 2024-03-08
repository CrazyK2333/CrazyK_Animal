#pragma once
#include"Actor.h"
#include"Component.h"

class Pig :public GridActor
{
public:
	float mLastMoveElapsed{ 0.f };
	void InitEveryThing();
	virtual void UpDate(float IntervalTime);

	Pig(int inwidth, int inheight) :GridActor(inwidth, inheight,"Pig")
	{


	}

	Pig(class Board* inOriginBoard, int inwidth, int inheight, struct point inZeroPoint, std::string inActorName, brushcolor inColor);


};