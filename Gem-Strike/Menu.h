#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Image.h"
//#include "Gif.h"
#include "Text.h"
#include "Gem.h"

class Menu : public GameState
{
private:
	float _mouseX = 0;
	float _mouseY = 0;
	bool _leftclick = false;
	Platform* platform;
	Image* background;
	GameStateManager* manager;
	Text* text;
	Image* tile1;
	Image* tile2;
	Image* startButton;
	Image* startButton2;
	void drawTiles();
	Gem* Gem1;
	Gem* Gem2;
	Gem* Gem3;
	Gem* Gem4;
	Gem* Gem5;
	Gem* Gem6;
	Gem* Gem7;
	float y = 0;
public:
	Menu();
	~Menu();
	void Init(Platform* platform, GameStateManager* manager) override;
	void Draw() override;
	bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY) override;
	void Update() override;
	void Close() override;
	bool Ontop(Image image, float imageX, float imageY);
};