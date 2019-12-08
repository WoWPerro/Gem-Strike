#pragma once
#include "GameState.h"
#include "GameStateManager.h"
#include "Image.h"
//#include "Gif.h"
#include "Text.h"

class Menu : public GameState
{
private:
	Platform* platform;
	Image* background;
	GameStateManager* manager;
	Text* text;
	Image* tile1;
	Image* tile2;
	void drawTiles();
	//Gif* test;
	//Gif* test2;
public:
	Menu();
	~Menu();
	void Init(Platform* platform, GameStateManager* manager) override;
	void Draw() override;
	bool Input(ListaT<int>* keyDowns, ListaT<int>* keyUps) override;
	void Update() override;
	void Close() override;
};