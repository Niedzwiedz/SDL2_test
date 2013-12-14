#include "SDL_Setup.h"
#include "EasySprite.h"


class Hero
{
public:
	Hero(SDL_Setup* pSDLClass);
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
};

