#pragma once
#include "point.h"
#include"Message.h"
#include"Board.h"

class Component
{
public:
	std::vector<Message>ComponentMessageHouse;
	Message ComponentMessage;
	virtual void UpDateComponent(float IntervalTime) ;
    Component(class GridActor*inParentActor)
	{
		ParentActor = inParentActor;
		if(inParentActor==nullptr)
		{
			abort();
		}
	
	}
	virtual void ReSendMessage(Message inMessage);
	virtual void ProcessMessage(Message)=0;
	
protected:
	class GridActor* ParentActor{nullptr};


};

