#include "BaseGridAttackComponent.h"
#include"BasicDefines.h"
#include"Cat.h"
#include"Human.h"
#include"Pig.h"
#include"BaseGridMoveComponent.h"



//std::vector<BaseGridAttackComponent*>& BaseGridAttackComponent::LiveMessageHouse()
//{
//	static std::vector<BaseGridAttackComponent*> LiveMessage{};
//	return LiveMessage;
//}
//
//void LiveMessageSave()
//{
//	BaseGridAttackComponent::ComponentMessageHouse().push_back(new Cat{100,20});
//	BaseGridAttackComponent::ComponentMessageHouse().push_back(new Pig{200,10 });
//	BaseGridAttackComponent::ComponentMessageHouse().push_back(new Human{ 50,50 });
//}





void BaseGridAttackComponent::SearchEnemy()
{


}

void BaseGridAttackComponent::ProcessMessage(Message inMessage)
{
	if(inMessage.GetIdentifier()=="YouHaveCollided")
	{
		GridActor* TestSearchResult = nullptr;
		Board* TestOriginBoard = nullptr;
		Message AttackTarget;
		Message AttackStartTime;
		clock_t start_time = clock();
		clock_t end_time = clock();
		
		AttackTarget.SetIdentifier("OnAttacked");
		AttackTarget.SetValue_0<float>(this->Power);
		AttackStartTime.SetIdentifier("AttackStart");
		AttackStartTime.SetValue_0<double>((end_time - start_time) / CLOCKS_PER_SEC);

		BaseGridMoveComponent* MoveComponent = ParentActor->GetComponent<BaseGridMoveComponent>();
		/*AttackRespond->MoveDelta(-3, 0);*/
		if(MoveComponent!=nullptr&&this->ActorName=="Cat")
		{
			MoveComponent->MoveDelta(-3, 0);
		
		}
		if (MoveComponent != nullptr && this->ActorName == "Pig")
		{
			MoveComponent->MoveDelta(-5, 0);

		}
		if (MoveComponent != nullptr && this->ActorName == "Human")
		{
			MoveComponent->MoveDelta(-8, 0);

		}
		
		TestOriginBoard = ParentActor->OriginBoard;

		

		TestSearchResult = TestOriginBoard->
			SearchGridActorAtIndexXY(inMessage.GetValue_0<point>().x,
				inMessage.GetValue_0<point>().y,
				GridActor::GetGlobalWareActorHouse());
	    
	
		TestSearchResult->GridActorSendMessage(AttackTarget);
	}
	else if(inMessage.GetIdentifier()== "YouAreCollided")
	{
		Message Attacker;
		Attacker.SetIdentifier("OnAttacked");
		Attacker.SetValue_0<float>(this->Power);

		Board::GetGlobalBoard().SearchGridActorAtIndexXY(inMessage.GetValue_0<point>().x, 
			inMessage.GetValue_0<point>().y,
			GridActor::GetGlobalWareActorHouse())->
			GridActorSendMessage(Attacker);
	    
	
	}
	else if(inMessage.GetIdentifier()=="OnAttacked")
	{
		this->OnAttacked(inMessage.GetValue_0<float>());
	    
	
	}

	



}

void BaseGridAttackComponent::OnAttacked(float inPower)
{
	//AttackedActor.Hp-AttackingActor.Power;
	DeBugOutputNormal("An Actor is Attacked %s\n, Hp is %d\n", this->ParentActor->mActorName.c_str(), this->Hp);
	if(!IsDead())
	{
		this->Hp = this->Hp - inPower;
	
	}
	


}




bool BaseGridAttackComponent::IsDead()
{
	if(this->Hp<=0)
	{
		return true;
	
	}

	return false;
}

BaseGridAttackComponent& BaseGridAttackComponent::SetHp(int inHp)
{
	this->Hp = inHp;
	return *this;

}

BaseGridAttackComponent& BaseGridAttackComponent::SetPower(float inPower)
{
	this->Power = inPower;
	return *this;

}

BaseGridAttackComponent& BaseGridAttackComponent::SetActorName(std::string inActorName)
{
	this->ActorName = inActorName;
	return *this;
}


const BaseGridAttackComponent& BaseGridAttackComponent::FinshBuilding()
{
	return *this;



}









