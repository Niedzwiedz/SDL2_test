#pragma once
class SDL_Setup
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
public:
	SDL_Setup(bool* quit);
	~SDL_Setup(void);

	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();
};

