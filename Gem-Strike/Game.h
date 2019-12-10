#pragma once
#include "GameState.h"
#include "Gem.h"
#include "Grid.h"
#include "Text.h"

class Game : public GameState
{
private:
	float _mouseX = 0;
	float _mouseY = 0;
	bool _leftclick = false;
	Platform* platform;
	GameStateManager* manager;
	Image* tile1;
	Image* tile2;
	Gem* gem1;
	Grid Gemgrid;
	Text* Score;
	std::string scoreString;
	void DrawTiles();
	void DrawGems();
	void UpdateGems();

public:
	Game();
	~Game();
	void Init(Platform* platform, GameStateManager* manager) override;
	void Draw() override;
	bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY) override;
	void Update() override;
	void Close() override;
	bool Ontop(Image image, float imageX, float imageY);
	std::string OntopOfGem();
};

