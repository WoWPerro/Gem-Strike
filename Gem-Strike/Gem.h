#pragma once
#include "GameObject.h"
#include "Gif.h"

enum State {
	Normal = 0,
	Idling = 1,
	Destroying = 2,
};

class Gem : GameObject
{
public:
	Gem();
	Gem(int type);
	~Gem();
	void Draw() override;
	void Input(ListaT<int>* keyUps, ListaT<int>* keyDowns) override;
	void Update() override;
	float GetPositionX();
	float GetPositionY();
	
	State state = Normal;
	Image* _actualImage;
private:
	void LoadGifs(int type);
	int _type;
	//float _positionX, _positionY;
	Image* _image;
	Gif* _Destruction;
	Gif* _Idle;
};

