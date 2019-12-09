#pragma once
#include "GameState.h"
#include "Gem.h"

class Game : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
	Image* tile1;
	Image* tile2;
	Gem* gem1;
	void DrawTiles();
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
	bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY) override;
	void Update() override;
	void Close() override;
};

