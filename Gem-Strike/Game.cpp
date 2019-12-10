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
	Gemgrid.CreateGrid();
	std::cout << " Game Init" << std::endl;
	this->platform = platform;
	this->manager = manager;

	tile1 = new Image();
	tile1->LoadImage("../Assets/Images/Tile.png");
	tile2 = new Image();
	tile2->LoadImage("../Assets/Images/Tile2.png");
	gem1 = new Gem(6, 0,0);
	this->platform = platform;
	scoreString = "HOLA";
	Score = new Text("../Assets/Fonts/8-BIT WONDER.TTF", 25, scoreString, { 255, 0, 0, 255 });
	std::cout << " Game Init" << std::endl;
}

void Game::Draw()
{
	std::cout << " Game Draw" << std::endl;
	platform->RenderClear();
	DrawTiles();
	gem1->Draw();
	platform->RenderImage(gem1->_actualImage, 0, 0, 0);
	DrawGems();
	Score->Display(0, 0);
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

	_mouseX = *mouseX;
	_mouseY = *mouseY;
	_leftclick = leftclick;

	std::cout << " Game Input" << std::endl;
	return false;
}

void Game::Update()
{
	if (_leftclick == true)
	{
		scoreString = "";
		scoreString = OntopOfGem();
		Score->Update(scoreString);
	}
	UpdateGems();
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

void Game::DrawGems()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Image* image = &Gemgrid.GetImage(i, j);
			int w = tile1->GetWidth();
			int h = tile1->GetHeight();
			platform->RenderImage(image, ((platform->width / 2) - 4 * w) + (i * w), ((platform->height / 2) - 4 * h) + (j * h), 0);
		}
	}
}

void Game::UpdateGems()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			Gemgrid.UpdateGems(i, j);
		}
	}
}

bool Game::Ontop(Image image, float imageX, float imageY)
{
	if (_mouseX > imageX&& _mouseX < imageX + image.GetWidth())
	{
		if (_mouseY > imageY&& _mouseY < imageY + image.GetHeight())
		{
			return true;
		}
	}
	return false;
}

std::string Game::OntopOfGem()
{
	int w = tile1->GetWidth();
	int h = tile1->GetHeight();
	int x = (platform->width / 2) - (4 * w);
	int y = (platform->height / 2) - (4 * h);
	int w2 = x + (w*8);
	int h2 = x + (h*8);



	if (_mouseX > x && _mouseX < x + w2)
	{
		if (_mouseY > y && _mouseY < y + h2)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (_mouseX > x && _mouseX < x + w * i)
					{
						if (_mouseY > y && _mouseY < y + h * j)
						{
							std::string index = std::to_string(i - 1) + " " + std::to_string(j - 1);
							return index;
						}
					}
				}			
			}
		}
	}

	return "";
}