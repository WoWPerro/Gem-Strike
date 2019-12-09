#include "Menu.h"
#include "Game.h"
#include<iostream>


Menu::Menu()
{

}

Menu::~Menu()
{
}

void Menu::Init(Platform* platform, GameStateManager* manager)
{
	std::cout << " Menu Init" << std::endl;
	this->platform = platform;
	this->manager = manager;

	text = new Text("../Assets/Fonts/8-BIT WONDER.TTF", 25, "Ya tengo texto en mi jueguitow", { 255, 0, 0, 255 });
	tile1 = new Image();
	tile1->LoadImage("../Assets/Images/Tile.png");
	tile2 = new Image();
	tile2->LoadImage("../Assets/Images/Tile2.png");
	background = new Image();
	background->LoadImage("../Assets/Images/BackGround.png");
	startButton = new Image();
	startButton->LoadImage("../Assets/Images/Start.png");
	startButton2 = new Image();
	startButton2->LoadImage("../Assets/Images/Start2.png");
	Gem1 = new Gem(0, 0, 0);
	Gem2 = new Gem(1, 0, 0);
	Gem3 = new Gem(2, 0, 0);
	Gem4 = new Gem(3, 0, 0);
	Gem5 = new Gem(4, 0, 0);
	Gem6 = new Gem(5, 0, 0);
	Gem7 = new Gem(6, 0, 0);
	Gem1->state = Idling;
	Gem2->state = Idling;
	Gem3->state = Idling;
	Gem4->state = Idling;
	Gem5->state = Idling;
	Gem6->state = Idling;
	Gem7->state = Idling;
}

void Menu::Draw()
{
	y += .01f;
	platform->RenderClear();
	std::cout << " Menu Draw" << std::endl;
	//drawTiles();
	text->Display(0, 0);
	platform->RenderImage(background, 0, 0, 0);
	Gem1->Draw();
	Gem2->Draw();
	Gem3->Draw();
	Gem4->Draw();
	Gem5->Draw();
	Gem6->Draw();
	Gem7->Draw();
	
	platform->RenderImage(Gem1->_actualImage, (platform->width / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y*3), 0);
	platform->RenderImage(Gem2->_actualImage, (platform->width*2 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf((y*3) + 1), 0);
	platform->RenderImage(Gem3->_actualImage, (platform->width*3 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf((y*3) + 2), 0);
	platform->RenderImage(Gem4->_actualImage, (platform->width*4 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf((y*3) + 3), 0);
	platform->RenderImage(Gem5->_actualImage, (platform->width*5 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf((y*3) + 4), 0);
	platform->RenderImage(Gem6->_actualImage, (platform->width*6 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf((y*3) + 5), 0);
	platform->RenderImage(Gem7->_actualImage, (platform->width*7 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf((y*3) + 6), 0);

	if (Ontop(*Gem1->_actualImage, (platform->width / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 1) && _leftclick)
	{
		Gem1->state =  Destroying;
	}

	if (Ontop(*Gem2->_actualImage, (platform->width * 2 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 2) && _leftclick)
	{
		Gem2->state = Destroying;
	}

	if (Ontop(*Gem3->_actualImage, (platform->width * 3 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 3) && _leftclick)
	{
		Gem3->state =  Destroying;
	}

	if (Ontop(*Gem4->_actualImage, (platform->width * 4 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 4) && _leftclick)
	{
		Gem4->state =  Destroying;
	}

	if (Ontop(*Gem5->_actualImage, (platform->width * 5 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 5) && _leftclick)
	{
		Gem5->state =  Destroying;
	}

	if (Ontop(*Gem6->_actualImage, (platform->width * 6 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 6) && _leftclick)
	{
		Gem6->state =  Destroying;
	}

	if (Ontop(*Gem7->_actualImage, (platform->width*7 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 7) && _leftclick)
	{
		Gem7->state = Destroying;
	}


	/*if (Ontop(*Gem1->_actualImage, (platform->width / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 1) && _leftclick)
	{
		Gem1->state = Destroying;
	}
	if (Ontop(*Gem2->_actualImage, (platform->width * 2 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 2) && _leftclick)
	{
		Gem2->state = Destroying;
	}
	if (Ontop(*Gem3->_actualImage, (platform->width * 3 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 3) && _leftclick)
	{
		Gem3->state = Destroying;
	}
	if (Ontop(*Gem4->_actualImage, (platform->width * 4 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 4) && _leftclick)
	{
		Gem4->state = Destroying;
	}
	if (Ontop(*Gem5->_actualImage, (platform->width * 5 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 5) && _leftclick)
	{
		Gem5->state = Destroying;
	}
	if (Ontop(*Gem6->_actualImage, (platform->width * 6 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 6) && _leftclick)
	{
		Gem6->state = Destroying;
	}
	if (Ontop(*Gem7->_actualImage, (platform->width * 7 / 7) - (startButton->GetWidth() / 2), (platform->height / 5) - (startButton->GetHeight() / 2) * sinf(y * 3) + 7) && _leftclick)
	{
		Gem7->state = Destroying;
	}*/


	if (Ontop(*startButton, (platform->width / 4) - (startButton->GetWidth() / 2), (platform->height * 3 / 4) - (startButton->GetHeight() / 2)))
	{
		platform->RenderImage(startButton, (platform->width/4) - (startButton->GetWidth()/2), (platform->height*3/4) - (startButton->GetHeight() / 2), 0);
	}
	else
	{
		platform->RenderImage(startButton2, (platform->width / 4) - (startButton2->GetWidth() / 2), (platform->height * 3 / 4) - (startButton2->GetHeight() / 2), 0);
	}
	if (Ontop(*startButton, (platform->width / 4) - (startButton->GetWidth() / 2), (platform->height * 3 / 4) - (startButton->GetHeight() / 2)) && _leftclick)
	{
		manager->SetState(new Game());
	}

	platform->RenderPresent();
}

bool Menu::Input(ListaT<int>* keyDowns, ListaT<int>* keyUps, bool* leftclick, float* mouseX, float* mouseY)
{
	std::cout << " Menu Input" << std::endl;

	if (!(keyUps->size == 0))
	{
		for (int i = 0; i < keyUps->size; i++)
		{
			int num = keyUps->get_at(i)->value;
			if (num == 27)
			{
				exit(1);
			}
			else
			{
				manager->SetState(new Game());
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

	return false;
}

void Menu::Update()
{
	std::cout << " Menu Update" << std::endl;
	Gem1->Update();
	Gem2->Update();
	Gem3->Update();
	Gem4->Update();
	Gem5->Update();
	Gem6->Update();
	Gem7->Update();
}

void Menu::Close()
{
	std::cout << " Close Init" << std::endl;
}

void Menu::drawTiles()
{
	int w = tile1->GetWidth();
	int h = tile1->GetHeight();
	bool switch1 = false;
	for (int i = 0; i <= platform->height; i++)
	{
		for (int j = 0; j <= platform->width; j++)
		{
			if (switch1)
			{
				platform->RenderImage(tile1, w * j, h * i, 0);
				switch1 = !switch1;
			}

			else
			{
				platform->RenderImage(tile2, w * j, h * i, 0);
				switch1 = !switch1;
			}
		}
	}
}

bool Menu::Ontop(Image image, float imageX, float imageY)
{
	if (_mouseX > imageX && _mouseX < imageX + image.GetWidth())
	{
		if (_mouseY > imageY&& _mouseY < imageY + image.GetHeight())
		{
			return true;
		}
	}
	return false;
}