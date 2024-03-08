#pragma once
#include"Component.h"
#include"Actor.h"
#include"Message.h"

class BaseGridAttackComponent :public Component
{
private:
	int Hp;
	float Power;
	std::string ActorName;
	std::string OnAttackActor;
	
	

public:
	

	bool IsDead();

	BaseGridAttackComponent(class GridActor* inActor) :Component(inActor)
	{

	}

	BaseGridAttackComponent& SetHp(int inHp);

	BaseGridAttackComponent& SetPower(float inPower);

	BaseGridAttackComponent& SetActorName(std::string inActorName);

	const BaseGridAttackComponent& FinshBuilding();


	/*static std::vector<BaseGridAttackComponent*>& LiveMessageHouse();*/

	
	void SearchEnemy();

	void ProcessMessage(Message inMessage);

	point GetMessageA{};

	void OnAttacked(float inPower);

	

	
	
};