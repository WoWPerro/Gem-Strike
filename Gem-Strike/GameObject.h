#pragma once
#include "Platform.h"
class GameObject
{
protected:
	float positionX, positionY;
public:
	GameObject() {};
	~GameObject() {};
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Input(ListaT<int>* keyUps, ListaT<int>* keyDowns) = 0;
	float GetPositionX();
	float GetPositionY();
};