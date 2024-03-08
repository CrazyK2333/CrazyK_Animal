#include "BaseGridColorChangeComponent.h"
#include"BaseGridAttackComponent.h"
#include"Actor.h"

//void BaseGridColorChangeComponent::OverrideActorColor()
//{
//	if(ParentActor->mColor!=brushcolor::LightPink&&ParentActor->mColor!=brushcolor::Black)
//	{
//		mReStoreActorColor = ParentActor->mColor;
//		ParentActor->mColor = brushcolor::LightPink;
//	}
//
//	
//	
//	
//
//}

//void BaseGridColorChangeComponent::ManageMessage(Message inMessage)
//{
//	if(inMessage.GetIdentifier() =="OnAttacked")
//	{
//		return;
//	
//	}
//	
//
//
//}


void BaseGridColorChangeComponent::SwtichToColorState(bool IsFlashed)
{
	/*if(ParentActor->ActorOriginColor==brushcolor::Black&&IsFlashed)
	{
		mReStoreActorColor = ParentActor->mColor;
	    
	}*/
	if(IsFlashed)
	{
		ParentActor->mColor = brushcolor::LightPink;
		
	}
	else
	{
		ParentActor->mColor = ParentActor->ActorOriginColor;
	
	}
}

void BaseGridColorChangeComponent::ToggleColor()
{

	//!IsFlashed=false||false=mColor
	SwtichToColorState(ParentActor->mColor != brushcolor::LightPink);
	//少用任何条件跳转（如if）;

	/*!((x && y||z)=!(x&&y)&&!(z)=(!x||!y)&&!(z)
	!((x && y) || (z))= !(x && y) && !(z)=!(xy)&&!(z)=()*/



}

void BaseGridColorChangeComponent::UpDateComponent(float IntervalTime,Message inMesssage)
{
	Component::UpDateComponent(IntervalTime);
	//mcolor->mcolor!=lightpink->mcolor=lightpink->
	if(inMesssage.GetIdentifier()== "YouHaveCollided")
	{
		this->Activate(1.0f);
	}
	if(mActorLastOnAttacked>=0.f)
	{
		
		this->ToggleColor();
		
	   
	}

	

}

//void BaseGridColorChangeComponent::ReSetActorColor()
//{
//	/*class GridActor* AttackActor = GridActor::GetGlobalWareActorHouse().back();*/
//	if (mActorLastOnAttacked >= 2.0f)
//	{
//		mActorLastOnAttacked = -1;
//
//	}
//	if(mActorLastOnAttacked<0.f)
//	{
//		ParentActor->DrawActor();
//	
//	}
//
//
//
//}

void BaseGridColorChangeComponent::Activate(float FlashIntervalTime)
{
	mContrlIntervalTime = FlashIntervalTime;
	/*if(mActorLastOnAttacked>=2.0f)
	{
		mActorLastOnAttacked = -2;
	}
	if(mActorLastOnAttacked<0.f)
	{
		this->OverrideActorColor(brushcolor::LightPink);
	}
	if(mActorLastOnAttacked>=0.f&&mActorLastOnAttacked<2.f)
	{
		this->OverrideActorColor(ParentActor->FirstColor());
	}*/
	if(mActorLastOnAttacked<0.f)
	{
		mActorLastOnAttacked = ParentActor->mOperationTime;

	}





}

void BaseGridColorChangeComponent::DeActivate()
{
	mActorLastOnAttacked = -2.f;

}

void BaseGridColorChangeComponent::ProcessMessage(Message)
{


}

//brushcolor BaseGridColorChangeComponent::GetColor()
//{
//	return;
//
//}
