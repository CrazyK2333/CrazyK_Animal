#pragma once
#include"Cat.h"
#include"BaseGridMoveComponent.h"
#include"BaseGridAttackComponent.h"
#include"BaseGridColorChangeComponent.h"

void Cat::InitEveryThing()
{
	mCatLastMoveElapsed = 0.f;
	mInitOk = true;
	Test.SetIdentifier("TestParam");
	Test.SetValue_0<float>(555);
	
}



void Cat::UpDate(float IntervalTime)
{

	GridActor::UpDate(IntervalTime);
	 //逻辑代码在update中添加；
	/* if(IsDead())
	 {
		 this->ClearDrawActor();

	 }*/
	 /*if(!IsDead())
	 {*/
		 if (mInitOk)
		 {
			 Test.GetIdentifier();
			 Test.GetValue_0<float>();
			 //OutputDebugStringA("A is OK");
			 //DeBugOutputW(L"TestResult is %s\n", L"TestOK");
			 //DeBugOutputNormal("TestParam is %s\n ,TestParam is %f\n", Test.GetIdentifier(), Test.GetValue_0<float>());
			 
			 DeBugOutputNormal("OperationTime is %f\n", this->mOperationTime);
			 
			 mCatLastMoveElapsed += IntervalTime;
			 /*DeBugOutputW(L"LastMoveElapsedTime is %f\n", mLastMoveElapsed)*/;
			 if (mCatLastMoveElapsed >= 1.0f)
			 {
				 Component* TestElapsed = ComponentHouse.back();
				 if (TestElapsed != nullptr)
				 {
					 BaseGridMoveComponent* TestMove = (BaseGridMoveComponent*)TestElapsed;
					 bool MoveSuccess = TestMove->MoveDelta(1, 0);
					 mCatLastMoveElapsed = 0;

				 }

			 }
		 }
		 
	 /*
	 }*/
	 
	
}

Cat::Cat(class Board* inOriginBoard, int inwidth, int inheight, struct point inZeroPoint, std::string inActorName):GridActor { inOriginBoard, inwidth, inheight, inZeroPoint,inActorName }
{
	this->mColor = brushcolor::White;
	this->OriginColor();
	BaseGridAttackComponent* NewAttackComponent;
	NewAttackComponent = new BaseGridAttackComponent(this);
	NewAttackComponent->SetHp(50).SetPower(8).SetActorName("Cat").FinshBuilding();
	
	AddComponent<BaseGridAttackComponent>(NewAttackComponent);
	AddComponent<BaseGridColorChangeComponent>();
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