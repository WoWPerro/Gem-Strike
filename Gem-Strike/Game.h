#pragma once
#include "GameState.h"

class Game : public GameState
{
private:
	Platform* platform;
	/*Tank* player;
	HeavyTank* enemy;
	Bullet* bullet;
	Map* map;*/

	/*std::list<GameObject*> bulletPool;
	std::list<GameObject*> bulletPoolEnemy;
	std::list<GameObject*> tilePool;
	std::list<GameObject*> tankPool;
	std::list<float*> tankPosX;
	std::list<float*> tankPosY;*/

public:
	Game();
	~Game();
	void Init(Platform* platform, GameStateManager* manager) override;
	void Draw() override;
	bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps) override;
	void Update() override;
	void Close() override;
};

