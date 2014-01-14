#include <iostream>
#include "Srodowisko.h"
#include "Hero.h"
class Main
{
public:
	Main(int p_SCR_WIDTH, int p_SCR_HEIGHT);
	void GameLoop();
	~Main(void);
private:
	float KameraX;
	float KameraY;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	bool quit;
	SDL_Setup* SDLiclass;
	Hero* player;
	Srodowisko* plansza;
};

