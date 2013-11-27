#include "SDL_Setup.h"
class Main
{
public:
	Main(void);
	void GameLoop();
	~Main(void);
private:
	bool quit;
	
	SDL_Setup* SDLiclass;

	SDL_Texture* GrassTex;
	SDL_Rect GrassRect;
	SDL_Texture* playa;
	SDL_Rect PlayaRect;
};

