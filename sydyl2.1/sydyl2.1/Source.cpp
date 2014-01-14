#include "SDL.h"
#include "SDL_image.h"
#include "Main.h"


int main(int argc, char **argv){
	Main* glowny = new Main(1366, 786);

	glowny->GameLoop();

	return 0;
}