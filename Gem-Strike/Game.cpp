#include "Game.h"
#include<iostream>
#include "Gem.h"
#include <sstream> 

ListaT<int> extractIntegerWords(std::string str)
{
	ListaT<int> Results;
	std::stringstream ss;

	/* Storing the whole string into string stream */
	ss << str;

	/* Running loop till the end of the stream */
	std::string temp;
	int found;
	while (!ss.eof())
	{

		/* extracting word by word from stream */
		ss >> temp;

		/* Checking the given word is integer or not */
		if (std::stringstream(temp) >> found)
			Results.push_back(found);
	}
	return Results;
}

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
	GemClickPosition = "HOLA";
	Score = new Text("../Assets/Fonts/8-BIT WONDER.TTF", 25, GemClickPosition, { 255, 0, 0, 255 });
	std::cout << " Game Init" << std::endl;
}

void Game::Draw()
{
	std::cout << " Game Draw" << std::endl;
	platform->RenderClear();
	DrawTiles();
	gem1->Draw();
	platform->RenderImage(gem1->_actualImage, 0, 0, 0);
	if (select1 && select2)
	{
		int typeT = 0;
		if (selectedgem1i == selectedgem2i)
		{
			typeT = 1;
			if (selectedgem1j < selectedgem2j)
			{
				if (transitionFinish == false)
				{
					DrawTransition(selectedgem1i, selectedgem1j, selectedgem2i, selectedgem2j, typeT);
					if (transitionFinish)
					{
						select1 = false;
						select2 = false;
						int temp = Gemgrid.GetGemAt(selectedgem2i, selectedgem2j)->_type;
						int temp2 = Gemgrid.GetGemAt(selectedgem1i, selectedgem1j)->_type;
						Gemgrid.GetGemAt(selectedgem2i, selectedgem2j)->ChangeType(temp2);
						Gemgrid.GetGemAt(selectedgem1i, selectedgem1j)->ChangeType(temp);
						transitionFinish = false;
						offsety = 0;
						offsetx = 0;
					}
				}
			}
			else
			{
				if (transitionFinish == false)
				{
					DrawTransition(selectedgem2i, selectedgem2j, selectedgem1i, selectedgem1j, typeT);
					if (transitionFinish)
					{
						select1 = false;
						select2 = false;
						int temp = Gemgrid.GetGemAt(selectedgem2i, selectedgem2j)->_type;
						int temp2 = Gemgrid.GetGemAt(selectedgem1i, selectedgem1j)->_type;
						Gemgrid.GetGemAt(selectedgem2i, selectedgem2j)->ChangeType(temp2);
						Gemgrid.GetGemAt(selectedgem1i, selectedgem1j)->ChangeType(temp);
						transitionFinish = false;
						offsety = 0;
						offsetx = 0;
					}
				}
			}
		}
		else if (selectedgem1j == selectedgem2j)
		{
			typeT = 2;
			if (selectedgem1i < selectedgem2i)
			{
				if (transitionFinish == false)
				{
					DrawTransition(selectedgem1i, selectedgem1j, selectedgem2i, selectedgem2j, typeT);
					if (transitionFinish)
					{
						select1 = false;
						select2 = false;
						int temp = Gemgrid.GetGemAt(selectedgem2i, selectedgem2j)->_type;
						int temp2 = Gemgrid.GetGemAt(selectedgem1i, selectedgem1j)->_type;
						Gemgrid.GetGemAt(selectedgem2i, selectedgem2j)->ChangeType(temp2);
						Gemgrid.GetGemAt(selectedgem1i, selectedgem1j)->ChangeType(temp);
						transitionFinish = false;
						offsety = 0;
						offsetx = 0;
					}
				}
			}
			else
			{
				if (transitionFinish == false)
				{
					DrawTransition(selectedgem2i, selectedgem2j, selectedgem1i, selectedgem1j, typeT);
					if (transitionFinish)
					{
						select1 = false;
						select2 = false;
						int temp = Gemgrid.GetGemAt(selectedgem2i, selectedgem2j)->_type;
						int temp2 = Gemgrid.GetGemAt(selectedgem1i, selectedgem1j)->_type;
						Gemgrid.GetGemAt(selectedgem2i, selectedgem2j)->ChangeType(temp2);
						Gemgrid.GetGemAt(selectedgem1i, selectedgem1j)->ChangeType(temp);
						transitionFinish = false;
						offsety = 0;
						offsetx = 0;
					}
				}
			}
		}

		
	}
	else
	{
		DrawGems();
	}
	//Score->Display(0, 0);
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
	_leftclick = *leftclick;

	std::cout << " Game Input" << std::endl;
	return false;
}

void Game::Update()
{
	if (_leftclick == true)
	{
		GemClickPosition = "";
		GemClickPosition = OntopOfGem();
		//Score->Update(GemClickPosition);
		Gemgrid.GetGemAt(extractIntegerWords(GemClickPosition).get_at(0)->value, extractIntegerWords(GemClickPosition).get_at(1)->value)->state = Idling;
		if (select1 == false)
		{
			selectedgem1i = extractIntegerWords(GemClickPosition).get_at(0)->value;
			selectedgem1j = extractIntegerWords(GemClickPosition).get_at(1)->value;
			Gemgrid.GetGemAt(extractIntegerWords(GemClickPosition).get_at(0)->value, extractIntegerWords(GemClickPosition).get_at(1)->value)->state = Idling;
			select1 = true;
		}
		else if (select2 == false)
		{
			selectedgem2i = extractIntegerWords(GemClickPosition).get_at(0)->value;
			selectedgem2j = extractIntegerWords(GemClickPosition).get_at(1)->value;
			Gemgrid.GetGemAt(extractIntegerWords(GemClickPosition).get_at(0)->value, extractIntegerWords(GemClickPosition).get_at(1)->value)->state = Idling;
			select2 = true;
		}
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

void Game::DrawTransition(int i1, int j1, int i2, int j2, int type)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int w = tile1->GetWidth();
			int h = tile1->GetHeight();
			
			if (i == i1 && j == j1)
			{
				Image* image = &Gemgrid.GetImage(i, j);
				int xPos = (((platform->width / 2) - 4 * w) + (i * w)) + offsetx;
				int yPos = (((platform->height / 2) - 4 * h) + (j * h)) + offsety;
				platform->RenderImage(image, xPos, yPos, 0);
				if (type == 2)
				{
					offsetx++;
					if (offsetx >= image->GetWidth())
					{
						transitionFinish = true;
					}
				}
				else if (type == 1)
				{
					offsety++;
					if (offsety >= image->GetHeight())
					{
					transitionFinish = true;
					}
				}
			}
			else if (i == i2 && j == j2)
			{
				Image* image = &Gemgrid.GetImage(i, j);
				int xPos = (((platform->width / 2) - 4 * w) + (i * w)) - offsetx;
				int yPos = (((platform->height / 2) - 4 * h) + (j * h)) - offsety;
				platform->RenderImage(image, xPos, yPos, 0);
				if (type == 2)
				{
					offsetx++;
					if (offsetx >= image->GetWidth())
					{
						transitionFinish = true;
					}
				}
				else if (type == 1)
				{
					offsety++;
					if (offsety >= image->GetHeight())
					{
						transitionFinish = true;
					}
				}
			}
			else
			{	
				Image* image = &Gemgrid.GetImage(i, j);
				platform->RenderImage(image, ((platform->width / 2) - 4 * w) + (i * w), ((platform->height / 2) - 4 * h) + (j * h), 0);
			}
			
		}
	}
}