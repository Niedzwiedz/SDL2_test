#include "Block.h"


Block::Block(float* CameraX, float* CameraY, SDL_Setup* pSDLClass,int x, int y)
{
	block = new EasySprite(pSDLClass->GetRenderer(), "data/envoirment/sand.bmp", 400+x,400+y,40,40, CameraX,CameraY,KolizjaRect(0,0,40,40));
}


Block::~Block(void)
{
			delete block;
}

void Block::DrawBlock(){
			block->Draw();

}