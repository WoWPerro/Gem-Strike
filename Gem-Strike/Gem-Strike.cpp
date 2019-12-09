// Gem-Strike.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "SDL.h"
#include "GameState.h"
#include "GameStateManager.h"
#include "Menu.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	GameStateManager* manager = new GameStateManager();
	manager->SetState(new Menu());
	manager->GameLoop();
	delete manager;
	return 0;
}