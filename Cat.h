#pragma once
#include"Actor.h"
#include"Component.h"
#include"Message.h"

class Cat :public GridActor
{
public:
	float mCatLastMoveElapsed{0.f};
	void InitEveryThing();
	Message Test;
	class BaseGridColorChangeComponent* mChangeCatColorComponent{nullptr};
	
	virtual void UpDate(float IntervalTime);
	

	

	Cat(int inwidth, int inheight) :GridActor(inwidth, inheight,"Cat")
	{


	}

	Cat(class Board* inOriginBoard, int inwidth, int inheight, struct point inZeroPoint, std::string inActorName/*,brushcolor inColor*/);
	
	
};