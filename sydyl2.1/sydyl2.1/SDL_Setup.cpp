#include "SDL_Setup.h"
#include <iostream>

SDL_Setup::SDL_Setup(bool* quit, int pSCREEN_WIDTH, int pSCREEN_HEIGHT)
{
	SCREEN_WIDTH=pSCREEN_WIDTH;
	SCREEN_HEIGHT=pSCREEN_HEIGHT;
	window = NULL;
	window = SDL_CreateWindow("Some bullshit on classes", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP);
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

void SDL_Setup::Begin(){
	SDL_PollEvent(mainEvent);
	SDL_RenderClear(renderer);
}

void SDL_Setup::End(){
	SDL_RenderPresent(renderer);
}
