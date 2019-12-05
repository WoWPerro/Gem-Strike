#pragma once
#include "Platform.h"
//#include <vector>
#include "ListaT.h"

class Platform;
class GameStateManager;

class GameState
{
public:
	virtual void Init(Platform* platform, GameStateManager* manager) = 0;
	virtual void Draw() = 0;
	//virtual bool Input(std::vector<int>* keyDowns, std::vector<int>* keyUps) = 0;
	virtual bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps) = 0;
	virtual void Update() = 0;
	virtual void Close() = 0;
};