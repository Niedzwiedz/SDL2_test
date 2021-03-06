#ifndef SDLSETUP
#define SDLSETUP
#include <iostream>
#include<Windows.h>
#include"SDL.h"

class SDL_Setup
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
public:
	SDL_Setup(bool* quit, int pSCREEN_WIDTH, int pSCREEN_HEIGHT);
	~SDL_Setup(void);
	
	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();
};

#endif