#include "SDL.h"
#include "SDL_image.h"
#include "Main.h"
#include <iostream>

Main::Main(int p_SCR_WIDTH, int p_SCR_HEIGHT)
{
	SCREEN_WIDTH = p_SCR_WIDTH;
	SCREEN_HEIGHT = p_SCR_HEIGHT;
	quit = false;
	SDLiclass = new SDL_Setup(&quit, SCREEN_WIDTH, SCREEN_HEIGHT);
	trawa = new EasySprite(SDLiclass->GetRenderer(), "data/grass.bmp", 0,0,SCREEN_WIDTH,SCREEN_HEIGHT);
	player = new EasySprite(SDLiclass->GetRenderer(), "data/playa.bmp", 100,100,10,10);
	
	MoveUp = false;
	MoveDown = false;
	MoveLeft = false;
	MoveRight = false;

	TimeCheck = SDL_GetTicks();
}


Main::~Main(void)
{

}

void Main::GameLoop(){
	while(!quit && SDLiclass->GetMainEvent()->type !=SDL_QUIT){
		SDLiclass->Begin();
		trawa -> Draw();
		player -> Draw();

		switch(SDLiclass->GetMainEvent()->type){
		case SDL_KEYDOWN:
			switch(SDLiclass->GetMainEvent()->key.keysym.sym){
			case SDLK_UP:
				MoveUp = true;
				break;
			case SDLK_DOWN:
				MoveDown = true;
				break;
			case SDLK_LEFT:
				MoveLeft = true;
				break;
			case SDLK_RIGHT:
				MoveRight = true;
				break;
			case SDLK_ESCAPE:
				quit = true;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch(SDLiclass->GetMainEvent()->key.keysym.sym){
			case SDLK_UP:
				MoveUp = false;
				break;
			case SDLK_DOWN:
				MoveDown = false;
				break;
			case SDLK_LEFT:
				MoveLeft = false;
				break;
			case SDLK_RIGHT:
				MoveRight = false;
				break;
			default:
				break;
				}
			break;	
		default:
			break;
		}	
		if(TimeCheck+10 < SDL_GetTicks())
		{
			if(MoveUp){
				player->SetY(player->GetY() - 2);
			}
			if(MoveDown){
				player->SetY(player->GetY() + 2);
			}
			if(MoveLeft){
				player->SetX(player->GetX() - 2);
			}
			if(MoveRight){
				player->SetX(player->GetX() + 2);
			}
			TimeCheck=SDL_GetTicks();
		}
		SDLiclass->End();
	}
}