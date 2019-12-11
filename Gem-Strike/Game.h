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
	std::string GemClickPosition;
	void DrawTiles();
	void DrawGems();
	void UpdateGems();
	int offsetx = 0;
	int offsety = 0;
	bool transitionFinish = false;
	bool select1 = false;
	bool select2 = false;
	int selectedgem1i = 0;
	int selectedgem1j = 0;
	int selectedgem2i = 0;
	int selectedgem2j = 0;
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
	void DrawTransition(int i1, int j1, int i2, int j2, int type);
};

