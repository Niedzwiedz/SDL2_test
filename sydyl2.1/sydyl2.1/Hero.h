#pragma once
#include "EasySprite.h"
#include "SDL_Setup.h"
class Hero
{
public:
	Hero(SDL_Setup* pSDLClass, bool quit);
	~Hero(void);

	void HeroMove();

	void Draw();
private:
	EasySprite* player;
	
	SDL_Setup* SDLclass;

	int TimeCheck;
	bool MoveUp;
	bool MoveDown;
	bool MoveLeft;
	bool MoveRight;

	bool quit;
};

