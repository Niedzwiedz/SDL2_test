#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "EasySprite.h"


EasySprite::EasySprite(SDL_Renderer* p_renderer, std::string FilePath, int x, int y, int w, int h, float *pCameraX, float *pCameraY, KolizjaRect pZderzacz)
{
	Zderzacz = pZderzacz;
	renderer = p_renderer;
	image=NULL;
	image= IMG_LoadTexture(renderer, FilePath.c_str());

	if(image == NULL){
		std::cout << "Couldn't load" << FilePath.c_str() <<  std::endl;
	}

	collitest = NULL;
	collitest= IMG_LoadTexture(renderer, "data/envoirment/coli.bmp");

	if(collitest == NULL){
		std::cout << "Couldn't load" << "Collision" <<  std::endl;
	}

	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;

	SDL_QueryTexture(image,NULL,NULL, &img_wdth, &img_hght);

	crop.x = 0;
	crop.y = 0;
	crop.w = img_wdth;
	crop.h = img_hght;

	CameraX = pCameraX;
	CameraY = pCameraY;

	Kamera.x = rect.x + *CameraX;
	Kamera.y = rect.y + *CameraY;
	Kamera.w = rect.w;
	Kamera.h = rect.h;

	CurrentFrame = 0;
	Amount_Frame_X = 0;
	Amount_Frame_Y = 0;
}


EasySprite::~EasySprite(void)
{
	SDL_DestroyTexture(image);
}

void EasySprite::SetupAnimation(int pass_X, int pass_Y){
	Amount_Frame_X = pass_X;
	Amount_Frame_Y = pass_Y;
}

void EasySprite::PlayAnimation(int BeginFrame, int EndFrame, int Side, float Speed){
	if(animDelay+Speed < SDL_GetTicks()){
		if(EndFrame <= CurrentFrame){
			CurrentFrame=BeginFrame;
		}
		else{
			CurrentFrame++;
		}
		crop.x = CurrentFrame*(img_wdth/Amount_Frame_X);
		crop.y = Side * (img_hght/Amount_Frame_Y);
		crop.w = img_wdth/Amount_Frame_X;
		crop.h = img_hght/Amount_Frame_Y;

		animDelay = SDL_GetTicks();
	}
}

void EasySprite::Draw(){
	
	Kamera.x = (rect.x + *CameraX);
	Kamera.y = (rect.y + *CameraY);

	Zderzacz.SetX(rect.x + *CameraX);
	Zderzacz.SetY(rect.y + *CameraY);

	SDL_RenderCopy(renderer, image, &crop, &Kamera);

	SDL_RenderCopy(renderer, collitest, NULL, &Zderzacz.GetRect());
	
}
void EasySprite::DrawHero(){
	SDL_RenderCopy(renderer, image, &crop, &rect);
	SDL_RenderCopy(renderer, collitest, NULL, &Zderzacz.GetRect());
	
}


void EasySprite::SetX(int X){
	rect.x = X;
}

void EasySprite::SetY(int Y){
	rect.y = Y;
}

void EasySprite::SetPosition(int X, int Y){
	rect.x = X;
	rect.y = Y;
}

int EasySprite::GetX(){
	return rect.x;
}
int EasySprite::GetY(){
	return rect.y;
}

bool EasySprite::isColiding(KolizjaRect ZderzaczA){
	return !(Zderzacz.GetRect().x + Zderzacz.GetRect().w <= ZderzaczA.GetRect().x ||
		Zderzacz.GetRect().y + Zderzacz.GetRect().h <= ZderzaczA.GetRect().y || 
		Zderzacz.GetRect().x >= ZderzaczA.GetRect().x + ZderzaczA.GetRect().w || 
		Zderzacz.GetRect().y >= ZderzaczA.GetRect().y + ZderzaczA.GetRect().h);
}
