#include <string>
class EasySprite
{
private:
	SDL_Texture* image;
	SDL_Rect rect;

	SDL_Renderer* renderer;

public:
	EasySprite(SDL_Renderer* p_renderer, std::string FilePath, int x, int y, int w, int h);
	~EasySprite(void);
	void Draw();

	void SetX(int X);
	void SetY(int Y);
	void SetPosition(int X, int Y);

	int GetX();
	int GetY();
};

