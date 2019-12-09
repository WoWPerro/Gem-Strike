#include "Game.h"
#include<iostream>
#include "Gem.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Init(Platform* platform, GameStateManager* manager)
{
	std::cout << " Game Init" << std::endl;
	this->platform = platform;
	this->manager = manager;

	tile1 = new Image();
	tile1->LoadImage("../Assets/Images/Tile.png");
	tile2 = new Image();
	tile2->LoadImage("../Assets/Images/Tile2.png");
	gem1 = new Gem(6, 0,0);
	/*player = new Tank();
	player->Init(platform);
	player->SetPool(&bulletPool, &tilePool, &tankPosX, &tankPosY);
	player->getPool(&bulletPoolEnemy);

	enemy = new HeavyTank();
	enemy->Init(platform);
	enemy->SetPool(&bulletPoolEnemy, &tilePool, &tankPosX, &tankPosY);
	enemy->getPool(&bulletPool);

	bullet = new Bullet(100, 100, player->GetAngle(), 10, 1);
	bullet->Init(platform);
	bullet->SetPool(&tilePool);

	map = new Map();
	map->SetPool(&tilePool);
	map->Init(platform);*/

	this->platform = platform;
	std::cout << " Game Init" << std::endl;
}

void Game::Draw()
{
	std::cout << " Game Draw" << std::endl;
	platform->RenderClear();
	DrawTiles();
	gem1->Draw();
	platform->RenderImage(gem1->_actualImage, 0, 0, 0);
	/*player->Draw();
	enemy->Draw();*/

	//A mayor numero menor velocidad del Gif

	/*for (auto object : bulletPool)
	{
		object->Draw();
	}

	for (auto object : bulletPoolEnemy)
	{
		object->Draw();
	}

	map->Draw();*/
	platform->RenderPresent();
}

bool Game::Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY)
{
	if (!(keyUps->size == 0))
	{
		for (int i = 0; i < keyUps->size; i++)
		{
			int num = keyUps->get_at(i)->value;
			if (num == 27)
			{
				exit(1);
			}
		}
	}

	if (!(keyDowns->size == 0))
	{
		for (int i = 0; i < keyDowns->size; i++)
		{
			int num = keyDowns->get_at(i)->value;
		}
	}

	//player->Input(keyUps, keyDowns);

	std::cout << " Game Input" << std::endl;
	return false;
}

void Game::Update()
{
	/*for (auto object : bulletPool)
	{
		object->Update();
	}

	for (auto object : bulletPoolEnemy)
	{
		object->Update();
	}*/

	/*enemy->SetPositionsTank(player->GetPositionX() + player->GetRadius() / 2, player->GetPositionY() + player->GetRadius() / 2);
	enemy->Update();
	player->Update();*/

	std::cout << " Game Update" << std::endl;

}

void Game::Close()
{
	std::cout << " Close Init" << std::endl;
}

void Game::DrawTiles()
{
	int w = tile1->GetWidth();
	int h = tile1->GetHeight();
	bool switch1 = false;
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 0; j <= 7; j++)
		{
			if (switch1)
			{
				platform->RenderImage(tile1, ((platform->width /2) - 4*w) + (i*w), ((platform->height / 2) - 4*h) + (j * h), 0);
				switch1 = !switch1;
			}

			else
			{
				platform->RenderImage(tile2, ((platform->width /2) - 4*w) + (i * w), ((platform->height / 2) - 4*h) + (j * h), 0);
				switch1 = !switch1;
			}
		}
		switch1 = !switch1;
	}
}