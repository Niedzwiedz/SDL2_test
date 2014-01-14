#ifndef BLOCK
#define BLOCK
#include "EasySprite.h"
class Block
{
public:
	Block(float* CameraX, float* CameraY, SDL_Setup* pSDLClass, int x, int y);
	~Block(void);

	void DrawBlock();

	EasySprite *GetBlock(){ return block; }
private:
	EasySprite *block;
};

#endif