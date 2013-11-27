#include "SDL.h"
#include "SDL_image.h"
#include "Main.h"
#include <iostream>

Main::Main(void)
{
	quit = false;
	SDLiclass = new SDL_Setup(&quit);
	trawa = new EasySprite(SDLiclass->GetRenderer(), "data/grass.bmp", 0,0,1360,768);
}


Main::~Main(void)
{
}

void Main::GameLoop(){
	while(!quit && SDLiclass->GetMainEvent()->type !=SDL_QUIT){
		SDLiclass->Begin();
		trawa -> Draw();
		SDLiclass->End();
	}
}