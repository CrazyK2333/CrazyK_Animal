#pragma once
#include"BasicDefines.h"
#include"point.h"
#include"Component.h"
#include<vector>
#include"Message.h"

class GridActor 
{
public:
	/*static int Live;*/

	std::string mActorName{ "GridActor" };

	brushcolor mColor;
	brushcolor ActorOriginColor;

	float mOperationTime{ 0.f };
	
	static std::vector<GridActor*>&GetGlobalWareActorHouse();
	bool mInitOk{ false };
	virtual void InitEveryThing()
	{
		MessageHouse.resize(5);
	
	}
	std::vector<Component*>ComponentHouse;
    std::vector<Message>MessageHouse;
	

	template<typename T>
	Component* AddComponent() 
	{
		ComponentHouse.push_back(new T(this));
		return ComponentHouse.back();

	}
	template<typename T>
	Component* AddComponent(T*inComponent)
	{
		ComponentHouse.push_back(inComponent);
		return inComponent;

	}
	template<typename T>
	T* GetComponent()
	{
		
		for(Component*CurComponet:ComponentHouse )
		{
			T*tmp= dynamic_cast<T*>(CurComponet);
			if(tmp!=nullptr)
			{
				return tmp;
			}
			
		}
		return nullptr;


	}

	
	virtual void UpDate(float IntervalTime) ;
	
	class Board* OriginBoard{ nullptr };
	 
	struct point ZeroPoint;
	 
    int width;
    int height;
	
	brushcolor FirstColor();

	void DrawActor();
	
	void ClearDrawActor();
	GridActor();
	GridActor(int inwidth, int inheight, std::string inActorName);
	
	
	GridActor(class Board* inOriginBoard, int inwidth, int inheight, struct point inZeroPoint, std::string inActorName,brushcolor inColor);
	virtual ~GridActor();
	

	Message SaveMessage;
	


	void GridActorSendMessage(const Message& inSaveMessage);

	
	
    

};



