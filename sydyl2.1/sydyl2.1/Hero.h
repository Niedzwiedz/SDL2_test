#ifndef HERO
#define HERO

#include "EasySprite.h"
#include "Srodowisko.h"

class Hero
{
public:
	Hero(SDL_Setup* pSDLClass, float *pCameraX, float *pCameraY, Srodowisko* passedSrodowisko);
	~Hero(void);

	void HeroMove();
	void HeroAnim();

	void Draw();
	void Update();
private:
	EasySprite* player;
	Srodowisko* srodowisko;
	SDL_Setup* SDLclass;
	int a;
	int k;

	int img_width;
	int img_height;
	int Side;
	bool Jump;
	int JumpTime;

	float *CameraX;
	float *CameraY;

	int TimeCheck;
	bool MoveUp;
	bool MoveDown;
	bool MoveLeft;
	bool MoveRight;
	bool colis;
};

#endif