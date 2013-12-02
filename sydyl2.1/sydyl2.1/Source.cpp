#include "SDL.h"
#include "SDL_image.h"
#include "stdafx.h"




int main(int argc, char **argv){
	Main* glowny = new Main(1360, 768);

	glowny->GameLoop();

	return 0;
}