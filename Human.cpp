#pragma once
#include"Human.h"
#include"BaseGridMoveComponent.h"
#include"BaseGridAttackComponent.h"
#include"BaseGridColorChangeComponent.h"

void Human::UpDate(float IntervalTime)
{
	GridActor::UpDate(IntervalTime);
	{
		mLastMoveElapsed += IntervalTime;
	    
	}
	
	/*DeBugOutputW(L"LastMoveElapsedTime is %f\n", mLastMoveElapsed)*/;
	if (mLastMoveElapsed >= 1.0)
	{
		Component* TestElapsed = ComponentHouse.back();
		if (TestElapsed != nullptr)
		{
			bool MoveSuccess = ((BaseGridMoveComponent*)TestElapsed)->MoveDelta(2, 0);
			mLastMoveElapsed = 0;
			
		}

	}
}

Human::Human(class Board* inOriginBoard, int inwidth, int inheight, struct point inZeroPoint, std::string inActorName/*, brushcolor inColor*/) :GridActor{ inOriginBoard, inwidth, inheight, inZeroPoint,inActorName}
{
	this->mColor = brushcolor::Blue;
	this->OriginColor();
	BaseGridAttackComponent* NewAttackComponent;
	NewAttackComponent = new BaseGridAttackComponent(this);
	NewAttackComponent->SetHp(100).SetPower(10).SetActorName("Human").FinshBuilding();
	AddComponent<BaseGridAttackComponent>(NewAttackComponent);
	AddComponent<BaseGridMoveComponent>();
	{

		if (inOriginBoard != nullptr)
		{
			this->OriginBoard = inOriginBoard;
			this->ZeroPoint = inZeroPoint;
		}
		else
		{
			abort();
		}
	}



}