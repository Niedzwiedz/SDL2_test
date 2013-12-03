#include "Hero.h"
#include "SDL.h"
#include "SDL_image.h"

Hero::Hero(SDL_Setup* pSDLClass, bool pquit )
{
	SDLclass = pSDLClass;
	quit = pquit;
	TimeCheck = SDL_GetTicks();
	player = new EasySprite(SDLclass->GetRenderer(), "data/playa.bmp", 100,100,10,10);
}


Hero::~Hero(void)
{
}

void Hero::HeroMove(){
	switch(SDLclass->GetMainEvent()->type){
		case SDL_KEYDOWN:
			switch(SDLclass->GetMainEvent()->key.keysym.sym){
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
			switch(SDLclass->GetMainEvent()->key.keysym.sym){
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
}

void Hero::Draw(){
	player->Draw;
}