#include "Gem.h"

Gem::Gem()
{
	_Destruction = new Gif(false);
	_Idle = new Gif(true);
	LoadGifs(_type);
}

void Gem::LoadGifs(int type)
{
	switch (type)
	{
	case 0:
	{
		_image = new Image();
		_image->LoadImage("../Assets/Gifs/Diamond/Diamond.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/Diamond.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction1.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction2.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction3.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction4.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction5.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction6.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction7.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction8.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction9.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction10.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction11.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction12.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction13.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction14.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction15.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction16.png");
		_Destruction->AddImage("../Assets/Gifs/Diamond/DiamondDestruction17.png");
		_Destruction->AddImage("../Assets/Images/void.png");
		_Destruction->SetVelocity(50);
		_Idle->AddImage("../Assets/Gifs/Diamond/Diamond.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/DiamondIdle1.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/DiamondIdle2.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/DiamondIdle3.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/DiamondIdle4.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/DiamondIdle5.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/DiamondIdle6.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/DiamondIdle7.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/Diamond.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/Diamond.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/Diamond.png");
		_Idle->AddImage("../Assets/Gifs/Diamond/DiamondIdle7.png");
		_Idle->SetVelocity(100);
	}
		
		break;
	case 1:
	{
		_image = new Image();
		_image->LoadImage("../Assets/Gifs/Lapiz/Lapiz.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/Lapiz.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction1.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction2.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction3.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction4.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction5.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction6.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction7.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction8.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction9.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction10.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction11.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction12.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction13.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction14.png");
		_Destruction->AddImage("../Assets/Gifs/Lapiz/LapizDestruction15.png");
		_Destruction->AddImage("../Assets/Images/void.png");
		_Destruction->SetVelocity(50);
		_Idle->AddImage("../Assets/Gifs/Lapiz/Lapiz.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/LapizIdle1.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/LapizIdle2.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/LapizIdle3.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/LapizIdle4.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/LapizIdle5.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/LapizIdle6.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/Lapiz.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/Lapiz.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/Lapiz.png");
		_Idle->AddImage("../Assets/Gifs/Lapiz/LapizIdle7.png");
		_Idle->SetVelocity(100);
	}
		
		break;
	case 2:
	{
		_image = new Image();
		_image->LoadImage("../Assets/Gifs/Emerald/Emerald.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/Emerald.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction1.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction2.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction3.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction4.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction5.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction6.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction7.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction8.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction9.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction10.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction11.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction12.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction13.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction14.png");
		_Destruction->AddImage("../Assets/Gifs/Emerald/EmeraldDestruction15.png");
		_Destruction->AddImage("../Assets/Images/void.png");
		_Destruction->SetVelocity(50);
		_Idle->AddImage("../Assets/Gifs/Emerald/Emerald.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/EmeraldIdle1.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/EmeraldIdle2.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/EmeraldIdle3.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/EmeraldIdle4.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/EmeraldIdle5.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/EmeraldIdle6.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/EmeraldIdle7.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/Emerald.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/Emerald.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/Emerald.png");
		_Idle->AddImage("../Assets/Gifs/Emerald/EmeraldIdle8.png");
		_Idle->SetVelocity(100);
	}
		break;
	case 3:
	{
		_image = new Image();
		_image->LoadImage("../Assets/Gifs/Triangle/Triangle.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/Triangle.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction1.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction2.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction3.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction4.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction5.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction6.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction7.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction8.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction9.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction10.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction11.png");
		_Destruction->AddImage("../Assets/Gifs/Triangle/TriangleDestruction12.png");
		_Destruction->AddImage("../Assets/Images/void.png");
		_Destruction->SetVelocity(50);
		_Idle->AddImage("../Assets/Gifs/Triangle/Triangle.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/TriangleIdle1.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/TriangleIdle2.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/TriangleIdle3.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/TriangleIdle4.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/TriangleIdle5.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/TriangleIdle6.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/TriangleIdle7.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/Triangle.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/Triangle.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/Triangle.png");
		_Idle->AddImage("../Assets/Gifs/Triangle/TriangleIdle8.png");
		_Idle->SetVelocity(100);
	}
		break;
	case 4:
	{
		_image = new Image();
		_image->LoadImage("../Assets/Gifs/Amatista/Amatista.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/Amatista.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction1.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction2.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction3.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction4.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction5.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction6.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction7.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction8.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction9.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction10.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction11.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction12.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction13.png");
		_Destruction->AddImage("../Assets/Gifs/Amatista/AmatistaDestruction14.png");
		_Destruction->AddImage("../Assets/Images/void.png");
		_Destruction->SetVelocity(50);
		_Idle->AddImage("../Assets/Gifs/Amatista/Amatista.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle1.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle2.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle3.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle4.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle5.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle6.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle7.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle8.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/Amatista.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/Amatista.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/Amatista.png");
		_Idle->AddImage("../Assets/Gifs/Amatista/AmatistaIdle9.png");
		_Idle->SetVelocity(100);
	}
		break;
	case 5:
	{
		_image = new Image();
		_image->LoadImage("../Assets/Gifs/Obsidian/Obsidian.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/Obsidian.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction1.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction2.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction3.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction4.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction5.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction6.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction7.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction8.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction9.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction10.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction11.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction12.png");
		_Destruction->AddImage("../Assets/Gifs/Obsidian/ObsidianDestruction13.png");
		_Destruction->AddImage("../Assets/Images/void.png");
		_Destruction->SetVelocity(50);
		_Idle->AddImage("../Assets/Gifs/Obsidian/Obsidian.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/ObsidianIdle1.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/ObsidianIdle2.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/ObsidianIdle3.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/ObsidianIdle4.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/ObsidianIdle5.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/ObsidianIdle6.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/ObsidianIdle7.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/Obsidian.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/Obsidian.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/Obsidian.png");
		_Idle->AddImage("../Assets/Gifs/Obsidian/ObsidianIdle8.png");
		_Idle->SetVelocity(100);
	}
		break;
	case 6:
	{
		_image = new Image();
		_image->LoadImage("../Assets/Gifs/Ambar/Ambar.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/Ambar.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction1.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction2.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction3.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction4.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction5.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction6.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction7.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction8.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction9.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction10.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction11.png");
		_Destruction->AddImage("../Assets/Gifs/Ambar/AmbarDestruction12.png");
		_Destruction->AddImage("../Assets/Images/void.png");
		_Destruction->SetVelocity(50);
		_Idle->AddImage("../Assets/Gifs/Ambar/Ambar.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/AmbarIdle1.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/AmbarIdle2.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/AmbarIdle3.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/AmbarIdle4.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/AmbarIdle5.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/AmbarIdle6.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/AmbarIdle7.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/Ambar.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/Ambar.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/Ambar.png");
		_Idle->AddImage("../Assets/Gifs/Ambar/AmbarIdle8.png");
		_Idle->SetVelocity(100);
	}
		break;
	}
}

Gem::Gem(int type, int _x, int _y)
{
	_type = type;
	_Destruction = new Gif(false);
	_Idle = new Gif(true);
	LoadGifs(_type);
	x = _x;
	y = _y;
}

Gem::~Gem()
{

}

void Gem::Draw()
{
	if (state == Destroying)
	{
		_actualImage = &(_Destruction->currentFrame);
	}
	else if (state == Idling)
	{
		_actualImage = &(_Idle->currentFrame);
	}
	else if (state == Normal)
	{
		_actualImage = _image;
	}
}

void Gem::Input(ListaT<int>* keyUps, ListaT<int>* keyDowns)
{

}

void Gem::Update()
{
	if (state == Destroying)
	{
		_Destruction->update();
	}
	else if (state == Idling)
	{
		_Idle->update();
	}
	else if (state == Normal)
	{
		_actualImage = _image;
	}
}

float Gem::GetPositionX()
{
	return 0;
}

float Gem::GetPositionY()
{
	return 0;
}
