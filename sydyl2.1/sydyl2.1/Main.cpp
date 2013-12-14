#include "SDL.h"
#include "SDL_image.h"
#include "Main.h"
#include <iostream>

Main::Main(int p_SCR_WIDTH, int p_SCR_HEIGHT){
	SCREEN_WIDTH = p_SCR_WIDTH;
	SCREEN_HEIGHT = p_SCR_HEIGHT;
	quit = false;
	SDLiclass = new SDL_Setup(&quit, SCREEN_WIDTH, SCREEN_HEIGHT);
	trawa = new EasySprite(SDLiclass->GetRenderer(), "data/grass.bmp", 0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	player = new Hero(SDLiclass);
}


Main::~Main(void)
{

}

void Main::GameLoop(){
	while(!quit && SDLiclass->GetMainEvent()->type !=SDL_QUIT && SDLiclass->GetMainEvent()->key.keysym.sym != SDLK_ESCAPE ){
		SDLiclass->Begin();
		player->HeroMove();
		trawa -> Draw();
		player->Draw();
		
		
		
		SDLiclass->End();
	}
}