
class Main
{
public:
	Main(void);
	void GameLoop();
	~Main(void);
private:
	bool quit;
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
	SDL_Texture* GrassTex;
	SDL_Rect GrassRect;
	SDL_Texture* playa;
	SDL_Rect PlayaRect;
};

