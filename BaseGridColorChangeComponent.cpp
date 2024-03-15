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
	if(!AColorChangeIsOver)
	{
		SwtichToColorState(ParentActor->mColor != brushcolor::LightPink);
		if (ColorChangeStartTime > 0)
		{
			ColorChangeFinishTime = ParentActor->mOperationTime;
		}
	}
	
	//少用任何条件跳转（如if）;

	/*!((x && y||z)=!(x&&y)&&!(z)=(!x||!y)&&!(z)
	!((x && y) || (z))= !(x && y) && !(z)=!(xy)&&!(z)=()*/
	
	




}

void BaseGridColorChangeComponent::UpDateComponent(float IntervalTime)
{
	Component::UpDateComponent(IntervalTime);
	//To be completed
	if(!AColorChangeIsOver)
	{
		if (this->ActorOnattacked)
		{
			this->ActorOnattacked = false;
			this->Activate(1.0f);
			if (ColorChangeStartTime < 0)
			{
				ColorChangeStartTime = ParentActor->mOperationTime;

			}
			/*DeBugOutputNormal("starttime is %f\n", this->ColorChangeStartTime);*/

		}
		if (mActorLastOnAttacked >= 0.f)
		{

			this->ToggleColor();


		}
		if (ColorChangeStartTime > 0 && ColorChangeFinishTime > 0 && ColorChangeFinishTime - ColorChangeStartTime >= 4.0f)
		{
			AColorChangeIsOver = true;
			ParentActor->mColor = ParentActor->ActorOriginColor;

		}
	
	}
	if(AColorChangeIsOver)
	{
		mActorLastOnAttacked = -2.f;
		AColorChangeIsOver = false;
		ColorChangeFinishTime = -2.f;
		ColorChangeStartTime = -2.f;
		
		
	
	
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

void BaseGridColorChangeComponent::ProcessMessage(Message inMessage)
{
	if(inMessage.GetIdentifier()== "YouHaveCollided")
	{
		ActorOnattacked = true;
	
	}

}

//brushcolor BaseGridColorChangeComponent::GetColor()
//{
//	return;
//
//}
