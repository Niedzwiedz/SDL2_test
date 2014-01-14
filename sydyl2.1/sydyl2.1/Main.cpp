
#include "Main.h"

#include <iostream>

Main::Main(int p_SCR_WIDTH, int p_SCR_HEIGHT){
	
	SCREEN_WIDTH = p_SCR_WIDTH;
	SCREEN_HEIGHT = p_SCR_HEIGHT;
	KameraX = 0;
	KameraY = 0;
	quit = false;
	SDLiclass = new SDL_Setup(&quit, SCREEN_WIDTH, SCREEN_HEIGHT);
	plansza = new Srodowisko(SDLiclass, SCREEN_WIDTH, SCREEN_HEIGHT, &KameraX, &KameraY);
	player = new Hero(SDLiclass, &KameraX, &KameraY, plansza);
}


Main::~Main(void)
{
	delete SDLiclass;
	delete plansza;
	delete player;
}

void Main::GameLoop(){
	while(!quit && SDLiclass->GetMainEvent()->type !=SDL_QUIT && SDLiclass->GetMainEvent()->key.keysym.sym != SDLK_ESCAPE ){
		SDLiclass->Begin();
		plansza->DrawBack();
		
		player->Update();
		player->HeroMove();


		plansza->DrawFront();

		SDLiclass->End();
	}
}