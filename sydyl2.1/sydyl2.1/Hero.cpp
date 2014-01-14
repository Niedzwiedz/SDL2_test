#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Hero.h"

#include <math.h>

Hero::Hero(SDL_Setup* pSDLClass, float *pCameraX, float *pCameraY, Srodowisko* passedSrodowisko){

	srodowisko = passedSrodowisko;

	SDLclass = pSDLClass;
	TimeCheck = SDL_GetTicks();

	CameraX = pCameraX;
	CameraY = pCameraY;

	MoveUp = false;
	MoveDown = false;
	MoveLeft = false;
	MoveRight = false;
	Side = 0;
	Jump = false;
	JumpTime = 0;
	player = new EasySprite(SDLclass->GetRenderer(), "data/characters/spacesuitmove2.bmp", 1366/2,786/2,40,40,CameraX, CameraY,KolizjaRect(1366/2,786/2,40,40));
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

		if(TimeCheck +5 < SDL_GetTicks())
		{
			bool kolizja = false;
			for(int i = 0; i < srodowisko->GetBlocks().size(); i++)
			{
				if(player->isColiding( srodowisko->GetBlocks()[i]->GetBlock()->GetZderzacz()))
				{
					std::cout<< " KOLIZJA! " << std::endl;
					if(MoveUp){
						*CameraY-=11;
					}
					 if(MoveDown){
						*CameraY+=11;

					}
					 if(MoveLeft){
						*CameraX-=11;

					}
					 if(MoveRight){
						*CameraX+=11;
						
					}
					colis =true;
					kolizja = true;
				}
			}
			if(!kolizja){
				if(MoveUp== true){
					Jump = true;
					JumpTime = SDL_GetTicks();
					*CameraY +=1;
					
					/*player->SetY(player->GetY() - 2);*/
			
				}
				if(MoveDown== true){
					Jump = false;
					*CameraY -=1;
			
					/*player->SetY(player->GetY() + 2);*/

				}
				if(MoveLeft== true){
					Side = 1;
					/*player->SetX(player->GetX() - 2);*/
					*CameraX +=1;
			
			
				}
				if(MoveRight== true){
					Side = 0;
					/*player->SetX(player->GetX() + 2);	*/
					*CameraX -=1;
				
				}	
			}
		TimeCheck=SDL_GetTicks();	
	}	
}

void Hero::HeroAnim(){
	player->SetupAnimation(5,2);
	if(MoveUp==false && MoveDown==false && MoveLeft==false && MoveRight==false){
		player->PlayAnimation(0,0,Side,250);
	}
	else{
		if(Jump == false){
			player->PlayAnimation(0,3,Side,250);
		}
		else if(Jump == true){
			
				player->PlayAnimation(4,4,Side,250);
				if(JumpTime+5 < SDL_GetTicks()){
					Jump=false;
				}
				JumpTime = SDL_GetTicks();
		}
	}
}

void Hero::Draw(){
	player->DrawHero();
}
void Hero::Update(){
	Draw();
	HeroAnim();

	/*for(int i = 0; i < srodowisko->GetBlocks().size(); i++)
		if(player->isColiding( srodowisko->GetBlocks()[i]->GetBlock()->GetZderzacz())){
			std::cout<< " KOLIZJA! " << std::endl;
		}*/
}