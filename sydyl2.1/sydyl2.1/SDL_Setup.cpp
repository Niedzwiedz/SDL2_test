#include "SDL.h"
#include "SDL_image.h"
#include "SDL_Setup.h"
#include <iostream>

SDL_Setup::SDL_Setup(bool* quit)
{
	window = NULL;
	window = SDL_CreateWindow("Some bullshit on classes", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
	if(window == NULL){
		std::cout << "Window, couldnt be created" << std::endl;
		*quit = true;
	}

	renderer = NULL;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	mainEvent= new SDL_Event();
}


SDL_Setup::~SDL_Setup(void)
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	delete mainEvent;
}

SDL_Renderer* SDL_Setup::GetRenderer(){
	return renderer;
}

SDL_Event* SDL_Setup::GetMainEvent(){
	return mainEvent;
}
