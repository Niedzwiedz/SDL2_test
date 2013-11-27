#include "SDL.h"
#include "SDL_image.h"
#include "stdafx.h"

Main::Main(void)
{
	quit = false;
	window = NULL;
	window = SDL_CreateWindow("Some bullshit on classes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
	if(window == NULL){
		std::cout << "Window, couldnt be created" << std::endl;
		quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mainEvent= new SDL_Event();

	GrassTex=NULL;
	GrassTex= IMG_LoadTexture(renderer, "data/grass.bmp");

	if(GrassTex == NULL){
		std::cout << "Couldnt find texture" << std::endl;
	}
	GrassRect.x=0;
	GrassRect.y=0;
	GrassRect.w=1360;
	GrassRect.h=768;

	playa=NULL;
	playa= IMG_LoadTexture(renderer, "data/playa.bmp");

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
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

void Main::GameLoop(){
	while(!quit && mainEvent->type !=SDL_QUIT){
		SDL_PollEvent(mainEvent);
		SDL_RenderClear(renderer);

		SDL_RenderCopy(renderer, GrassTex, NULL, &GrassRect);
		SDL_RenderCopy(renderer, playa, NULL, &PlayaRect);

		SDL_RenderPresent(renderer);
	}
}