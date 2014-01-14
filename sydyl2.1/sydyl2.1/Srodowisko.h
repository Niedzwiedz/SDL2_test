#ifndef SRODOWISKO
#define SRODOWISKO

#include <iostream>
#include <fstream>
#include "Block.h"
#include <vector>


class Srodowisko
{
public:
	Srodowisko(SDL_Setup* pSDLClass,int SCRWDTH, int SCRHGT, float* passedCameraX, float* passedCameraY);
	~Srodowisko(void);

	void LoadFromFile();

	void DrawBack();
	void DrawFront();

	std::vector<Block*> GetBlocks(){ return block;}
private:
	SDL_Setup* sdlclass;

	float* CameraX;
	float* CameraY;

	EasySprite* trawa[2][1];
	std::vector<Block*> block;
};

#endif