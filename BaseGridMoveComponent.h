#pragma once
#include"Component.h"
#include"Actor.h"
#include"Message.h"

class BaseGridMoveComponent :public Component
{
public:
	
	
	virtual bool MoveDelta(int inXDistance, int inYDistance);
	virtual bool JumpToNewAddress(int NewX,int NewY );

	void ReportCollision(int attackedX,int attackedY);
	
	void UpDateComponent(float IntervalTime);
	BaseGridMoveComponent(class GridActor*inActor):Component(inActor)
	{

	}
	
	bool Move();

	void ProcessMessage(Message inMessage);
	
	point GetMessageM{};

	Message TransferMessage{};

	void GetWithoutMessageM();

	


};