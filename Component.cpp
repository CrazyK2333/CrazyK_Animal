#include "Component.h"

void Component::UpDateComponent(float IntervalTime)
{
	if(ComponentMessageHouse.size()!=0)
	{
		ComponentMessage = ComponentMessageHouse.back();
		this->ProcessMessage(ComponentMessage);
		ComponentMessageHouse.pop_back();
	}

	
	

}

void Component::ReSendMessage(Message inMessage)
{
	ComponentMessageHouse.push_back(inMessage);

	


}
