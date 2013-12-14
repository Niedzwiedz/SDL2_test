#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "EasySprite.h"


EasySprite::EasySprite(SDL_Renderer* p_renderer, std::string FilePath, int x, int y, int w, int h)
{
	renderer = p_renderer;
	image=NULL;
	image= IMG_LoadTexture(renderer, FilePath.c_str());

	if(image == NULL){
		std::cout << "Couldn't load" << FilePath.c_str() <<  std::endl;
	}
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
}


EasySprite::~EasySprite(void)
{
	SDL_DestroyTexture(image);
}

void EasySprite::Draw(){
	SDL_RenderCopy(renderer, image, NULL, &rect);
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