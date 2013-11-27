#include "SDL.h"
#include "SDL_image.h"
#include "stdafx.h"

Main::Main(void)
{
	quit = false;
	
	SDLiclass = new SDL_Setup(&quit);

	GrassTex=NULL;
	GrassTex= IMG_LoadTexture(SDLiclass->GetRenderer, "data/grass.bmp");

	if(GrassTex == NULL){
		std::cout << "Couldnt find texture" << std::endl;
	}
	GrassRect.x=0;
	GrassRect.y=0;
	GrassRect.w=1360;
	GrassRect.h=768;

	playa=NULL;
	playa= IMG_LoadTexture(SDLiclass->GetRenderer, "data/playa.bmp");

	if(playa == NULL){
		std::cout << "Couldnt find texture" << std::endl;
	}
	PlayaRect.x =300 ;
	PlayaRect.y =350 ;
	PlayaRect.w =100 ;
	PlayaRect.h =100 ;
}


Main::~Main(void)
{
	SDL_DestroyTexture(GrassTex);
	SDL_DestroyTexture(playa);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(SDLiclass->GetRenderer);
	delete mainEvent;
}

void Main::GameLoop(){
	while(!quit && mainEvent->type !=SDL_QUIT){
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(SDLiclass->GetRenderer);

		SDL_RenderCopy(renderer, GrassTex, NULL, &GrassRect);
		SDL_RenderCopy(renderer, playa, NULL, &PlayaRect);

		SDL_RenderPresent(renderer);
	}
}