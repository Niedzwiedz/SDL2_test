
class SDL_Setup
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event* mainEvent;
public:
	SDL_Setup(bool* quit, int pSCREEN_WIDTH, int pSCREEN_HEIGHT);
	~SDL_Setup(void);

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	SDL_Renderer* GetRenderer();
	SDL_Event* GetMainEvent();

	void Begin();
	void End();
};

