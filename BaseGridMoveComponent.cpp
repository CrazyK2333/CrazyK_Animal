#pragma once
#include"BaseGridMoveComponent.h"
#include"Board.h"
#include"SingleBlock.h"



bool BaseGridMoveComponent::MoveDelta(int inXDistance,int inYDistance)
{
	if(inXDistance==0&&inYDistance==0)
	{
		
		return false;
	}
	int MoveSpeedX;
	int MoveSpeedY;
	
	
	
	
	
		//Step 1 judge are an animal 's frontiers all in board
	point LeftTop{ParentActor->ZeroPoint};
	point LeftBottom{ ParentActor->ZeroPoint.x,ParentActor->ZeroPoint.y+ParentActor->height-1};
	point RightTop{ ParentActor->ZeroPoint.x+ParentActor->width-1,ParentActor->ZeroPoint.y };
	point RightBottom{ ParentActor->ZeroPoint.x + ParentActor->width - 1, ParentActor->ZeroPoint.y + ParentActor->height - 1 };

	point Delta{ inXDistance,inYDistance };
	LeftTop += Delta;
	LeftBottom += Delta;
	RightTop += Delta;
	RightBottom += Delta;

	MoveSpeedX = Delta.x;
	MoveSpeedY = Delta.y;

	if(ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x,LeftTop.y)==nullptr)
	{
		
		return false;
	
	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftBottom.x, LeftBottom.y) == nullptr)
	{
		
		return false;

	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(RightTop.x, RightTop.y) == nullptr)
	{
		
		return false;

	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(RightBottom.x, RightBottom.y) == nullptr)
	{
		
		return false;

	}
	if(ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x, LeftTop.y)->blockcolor != brushcolor::Black &&
		ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x, LeftTop.y)->GridActorPointer
		!=ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x, LeftTop.y)->FirstGridActorPointer())
	{
	    ReportCollision(LeftTop.x, LeftTop.y);
		return false;
	
	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftBottom.x, LeftBottom.y)->blockcolor != brushcolor::Black &&
		ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftBottom.x, LeftBottom.y)->GridActorPointer
		!= ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x, LeftTop.y)->FirstGridActorPointer())
	{
		ReportCollision(LeftBottom.x, LeftBottom.y);
		return false;

	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(RightTop.x, RightTop.y)->blockcolor != brushcolor::Black &&
		ParentActor->OriginBoard->SearchBlockAtIndexXY(RightTop.x, RightTop.y)->GridActorPointer
		!= ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x, LeftTop.y)->FirstGridActorPointer())
	{
		ReportCollision(RightTop.x, RightTop.y);
		return false;

	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(RightBottom.x, RightBottom.y)->blockcolor != brushcolor::Black &&
		ParentActor->OriginBoard->SearchBlockAtIndexXY(RightBottom.x, RightBottom.y)->GridActorPointer
		!= ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x, LeftTop.y)->FirstGridActorPointer())
	{
		ReportCollision(RightBottom.x, RightBottom.y);
		return false;

	}
	for (int x = LeftTop.x; x <= RightTop.x; x++)
	{


		for (int y = LeftTop.y; y <= RightBottom.y; y++)
		{

			if (ParentActor->OriginBoard->SearchBlockAtIndexXY(x, y)->blockcolor != brushcolor::Black &&
				ParentActor->OriginBoard->SearchBlockAtIndexXY(x, y)->GridActorPointer!= ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x,LeftTop.y)->GridActorPointer)
			{
				ReportCollision(x, y);
				return false;
			}


		}

	}
	/*if(ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x,LeftTop.y)->blockcolor!=brushcolor::Black&& 
		ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftTop.x, LeftTop.y)->blockcolor != ParentActor->FirstColor())
	{ 
		ReportCollision(LeftTop.x, LeftTop.y);
		return false;

	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftBottom.x, LeftBottom.y)->blockcolor != brushcolor::Black &&
		ParentActor->OriginBoard->SearchBlockAtIndexXY(LeftBottom.x, LeftBottom.y)->blockcolor != ParentActor->FirstColor())
	{
		ReportCollision(LeftBottom.x, LeftBottom.y);
		return false;

	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(RightTop.x, RightTop.y)->blockcolor != brushcolor::Black &&
		ParentActor->OriginBoard->SearchBlockAtIndexXY(RightTop.x, RightTop.y)->blockcolor != ParentActor->FirstColor())
	{
		ReportCollision(RightTop.x, RightTop.y);
		return false;

	}
	if (ParentActor->OriginBoard->SearchBlockAtIndexXY(RightBottom.x, RightBottom.y)->blockcolor != brushcolor::Black &&
		ParentActor->OriginBoard->SearchBlockAtIndexXY(RightBottom.x, RightBottom.y)->blockcolor != ParentActor->FirstColor())
	{
		ReportCollision(RightBottom.x, RightBottom.y);
		return false;

	}*/
	/*for (int x = LeftTop.x; x <= RightTop.x; x++)
	{
		
		
		for (int y = LeftTop.y; y <=RightBottom.y; y++)
		{
			
			if(ParentActor->OriginBoard->SearchBlockAtIndexXY(x, y)->blockcolor != brushcolor::Black &&
			ParentActor->OriginBoard->SearchBlockAtIndexXY(x, y)->blockcolor != ParentActor->FirstColor())
		    {
				ReportCollision(x, y);
			    return false;
		    }
			

		}

	}*/
	ParentActor->ClearDrawActor();
	ParentActor->ZeroPoint += Delta;
	

	/*ParentActor->DrawActor();*/
	/*DeBugOutputW(L"x =%d y=%d",ParentActor->ZeroPoint.x,ParentActor->ZeroPoint.y);*/

	
	return true;


}

bool BaseGridMoveComponent::JumpToNewAddress(int NewX,int NewY)
{
	int JumpDeltaX = NewX - ParentActor->ZeroPoint.x;
	int JumpDeltaY = NewY - ParentActor->ZeroPoint.y;

	return MoveDelta(JumpDeltaX,JumpDeltaY);
	

	

}

void BaseGridMoveComponent::ReportCollision(int attackedX, int attackedY)
{
	Message ToMyself;
	Message ToOthers;
	
	ToMyself.SetIdentifier("YouHaveCollided");
	ToMyself.SetValue_0<point>(point{ attackedX,attackedY });
	ToOthers.SetIdentifier("YouAreAttacked");
	ToOthers.SetValue_0<point>(point{ this->ParentActor->ZeroPoint.x,this->ParentActor->ZeroPoint.y });

	ParentActor->GridActorSendMessage(ToMyself);
	
	/*GridActor* SearchGridActorReslut = nullptr;*/
	//SearchGridActorReslut =Board::GetGlobalBoard().SearchGridActorAtIndexXY(attackedX, attackedY, GridActor::GetGlobalWareActorHouse())
	//	/*->GridActorSendMessage(ToOthers)*/;
	
	



}



void BaseGridMoveComponent::UpDateComponent(float IntervalTime)
{
	Component::UpDateComponent(IntervalTime);

}

bool BaseGridMoveComponent::Move()
{
	
	return false;
	SayC("ok");
}

void BaseGridMoveComponent::ProcessMessage(Message inMessage)
{
	if (inMessage.GetIdentifier() == "ReportCollision")
	{
		OutputDebugStringA("Message is OK");
		
	}

}

void BaseGridMoveComponent::GetWithoutMessageM()
{
	GetMessageM = TransferMessage.GetValue_0<point>();

}




