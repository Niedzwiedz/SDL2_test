#include "SDL_Setup.h"
#include "EasySprite.h"
class Main
{
public:
	Main(void);
	void GameLoop();
	~Main(void);
private:
	bool quit;
	SDL_Setup* SDLiclass;
	EasySprite* trawa;
	EasySprite* player;
};

