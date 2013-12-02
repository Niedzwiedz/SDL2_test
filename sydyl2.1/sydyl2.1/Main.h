#include "SDL_Setup.h"
#include "EasySprite.h"
class Main
{
public:
	Main(int p_SCR_WIDTH, int p_SCR_HEIGHT);
	void GameLoop();
	~Main(void);
private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	bool quit;
	SDL_Setup* SDLiclass;
	EasySprite* trawa;
	EasySprite* player;

	bool MoveUp;
	bool MoveDown;
	bool MoveLeft;
	bool MoveRight;
};

