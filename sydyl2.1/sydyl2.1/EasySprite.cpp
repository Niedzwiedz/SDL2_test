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
		std::cout << "Couldnt load" << FilePath.c_str() <<  std::endl;
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