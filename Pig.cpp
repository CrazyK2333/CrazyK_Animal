#pragma once
#include"Pig.h"
#include"BaseGridMoveComponent.h"
#include"BaseGridAttackComponent.h"
#include"BaseGridColorChangeComponent.h"

void Pig::InitEveryThing()
{
	mLastMoveElapsed = 0.f;
	mInitOk = true;

}

void Pig::UpDate(float IntervalTime)
{
	GridActor::UpDate(IntervalTime);
	if(mInitOk )
	{
		mLastMoveElapsed += IntervalTime;
		/*debugoutputw(l"lastmoveelapsedtime is %f\n", mlastmoveelapsed)*/;
		//DeBugOutputW(L"Pig's mlastmoveelapsed is%f\n", mLastMoveElapsed);
		if (mLastMoveElapsed >= 5.0)
		{
			Component* TestElapsed = ComponentHouse.back();
			if (TestElapsed != nullptr)
			{
				/*bool MoveSuccess = ((BaseGridMoveComponent*)TestElapsed)->MoveDelta(-1, 0);*/
				mLastMoveElapsed = 0;


			}

		}
	
	
	}
	
}

Pig::Pig(class Board* inOriginBoard, int inwidth, int inheight, struct point inZeroPoint, std::string inActorName,brushcolor inColor) :GridActor{ inOriginBoard, inwidth, inheight, inZeroPoint,inActorName,inColor}
{
	SingleBoardBlocksinfo* PigZeroPointBoard= this->OriginBoard->SearchBlockAtIndexXY(inZeroPoint.x, inZeroPoint.y);
	

	this->mColor = brushcolor::Pink;
	
	BaseGridAttackComponent* NewAttackComponent;
	NewAttackComponent = new BaseGridAttackComponent(this);
	NewAttackComponent->SetHp(200).SetPower(3).SetActorName("Pig").FinshBuilding();
	PigZeroPointBoard->ChangePointer((void*)"Pig");


	AddComponent<BaseGridAttackComponent>(NewAttackComponent);
	/*AddComponent<BaseGridColorChangeComponent>();*/
	AddComponent<BaseGridMoveComponent>();
	/*DeBugOutputNormal("Pig's Hp is %f\n",NewAttackCo);*/
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