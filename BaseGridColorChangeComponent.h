#pragma once
#include"Component.h"
#include"Actor.h"
#include"Message.h"



class BaseGridColorChangeComponent:public Component
{
private:
	brushcolor mReStoreActorColor{ brushcolor::Black };
	double mActorLastOnAttacked{ -1.f };
	/*float IntervalTime{ 3.f };*/
	float mContrlIntervalTime{ 0.f };
	


public:
	BaseGridColorChangeComponent(class GridActor* inActor) :Component(inActor)
	{


	}

	void SwtichToColorState(bool IsFlashed);

	void ToggleColor();

	void UpDateComponent(float IntervalTime);

	void Activate(float FlashIntervalTime);

	void DeActivate();

	void ProcessMessage(Message);

	




};
