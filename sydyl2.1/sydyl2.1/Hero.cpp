#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Hero.h"
#include <math.h>

Hero::Hero(SDL_Setup* pSDLClass){
	SDLclass = pSDLClass;
	TimeCheck = SDL_GetTicks();
	MoveUp = false;
	MoveDown = false;
	MoveLeft = false;
	MoveRight = false;
	player = new EasySprite(SDLclass->GetRenderer(), "data/playa.bmp", 100,100,10,10);
	
}
Hero::~Hero(void){
	delete player;
}
void Hero::HeroMove(){
	switch(SDLclass->GetMainEvent()->type){
		case SDL_KEYDOWN:
			switch(SDLclass->GetMainEvent()->key.keysym.sym){
			case SDLK_w:
				MoveUp = true;
				break;
			case SDLK_s:
				MoveDown = true;
				break;
			case SDLK_a:
				MoveLeft = true;
				break;
			case SDLK_d:
				MoveRight = true;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch(SDLclass->GetMainEvent()->key.keysym.sym){
			case SDLK_w:
				MoveUp = false;
				break;
			case SDLK_s:
				MoveDown = false;
				break;
			case SDLK_a:
				MoveLeft = false;
				break;
			case SDLK_d:
				MoveRight = false;
				break;
			default:
				break;
				}
			break;	
		default:
			break;
		}	
		if(TimeCheck+10 < SDL_GetTicks()){
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
	player->Draw();
}