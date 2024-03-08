#pragma once
#include"Actor.h"
#include "point.h"
#include"Board.h"
#include"Component.h"



inline brushcolor GridActor::FirstColor()
{
	return this->mColor;

}

//bool GridActor::IsDead()
//{
//	if (this->Hp <= 0)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int GridActor::GetHp()
//{
//	return this->Hp;
//}
//
//void GridActor::TestSurvive(int DeltaHp)
//{
//	if (IsDead())
//	{
//		return;
//	}
//	if (DeltaHp == 0)
//	{
//		return;
//	}
//	this->Hp =this->Hp+DeltaHp;
//
//	if (IsDead())
//	{
//		this->Live=this->Live-1;
//	}
//}
//
//void GridActor::Attack(GridActor* Targetanimal)
//{
//	Targetanimal->OnAttacked(this);
//
//}
//
//void GridActor::OnAttacked(GridActor* Attacker)
//{
//	TestSurvive(-Attacker->Power);
//	
//}





void GridActor::DrawActor()
{

	for (int i = 0; i < width; i++)
	{
		

		for (int j = 0; j < height; j++)
		{
			OriginBoard->SearchBlockAtIndexXY(ZeroPoint.x + i, ZeroPoint.y + j)->blockcolor = FirstColor();
			OriginBoard->SearchBlockAtIndexXY(ZeroPoint.x + i, ZeroPoint.y + j)->ChangePointer(OriginBoard->SearchBlockAtIndexXY(ZeroPoint.x, ZeroPoint.y)->GridActorPointer);
		}

	}
	
}

void GridActor::ClearDrawActor()
{

	for (int i = 0; i < width; i++)
	{


		for (int j = 0; j < height; j++)
		{
			OriginBoard->SearchBlockAtIndexXY(ZeroPoint.x + i, ZeroPoint.y + j)->blockcolor=brushcolor::Black;
			OriginBoard->SearchBlockAtIndexXY(ZeroPoint.x + i, ZeroPoint.y + j)->ChangePointer(nullptr);
		}

	}

}


GridActor::GridActor()
{
	
}

GridActor::GridActor(int inwidth, int inheight, std::string inActorName)
{
	this->width = inwidth;
	this->height = inheight;
	this->mActorName = inActorName;
	mOperationTime = 0;
}

GridActor::GridActor(Board* inOriginBoard, int inwidth, int inheight, point inZeroPoint, std::string inActorName,brushcolor inColor):GridActor(inwidth,inheight,inActorName)
{
	ActorOriginColor = inColor;
	mColor = inColor;
	if (inOriginBoard != nullptr)
	{
		this->OriginBoard = inOriginBoard;
		this->ZeroPoint = inZeroPoint;
	}
	else
	{
		abort();
	}

};
std::vector<GridActor*>& GridActor::GetGlobalWareActorHouse()
{
	static std::vector<GridActor*> GlobalWareActorHouse;
	return GlobalWareActorHouse;

}
void GridActor::UpDate(float IntervalTime)
{
	mOperationTime += IntervalTime;
	if(!mInitOk)
	{
		InitEveryThing();
	}
	for(Component*CurComponent:ComponentHouse)
	{
		CurComponent->UpDateComponent(IntervalTime);
		if (MessageHouse.size() > 0)
		{
			CurComponent->ReSendMessage(MessageHouse.back());
		
		}
		
		
	}
	if (MessageHouse.size() > 0)
	{
		MessageHouse.pop_back();
	
	}

}
GridActor::~GridActor()
{
	
	for (Component* CurComponent : ComponentHouse)
	{
		if (CurComponent!=nullptr)
		{
			delete CurComponent;
		}
		
	}
}

void GridActor::GridActorSendMessage(const Message& inSaveMessage)
{
	MessageHouse.push_back(inSaveMessage);
	

}








//template<typename T>
//void GridActor::AddComponent()
