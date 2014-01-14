#ifndef KOLIZJA
#define KOLIZJA
#include "SDL.h"
class KolizjaRect
{
public:
	KolizjaRect();
	KolizjaRect(int x, int y, int w, int h);
	~KolizjaRect(void);

	void SetRect(int x, int y, int w, int h);
	SDL_Rect GetRect() { return Zderzacz;}
	void SetX(int x) { Zderzacz.x = x + OffsetX;}
	void SetY(int y) { Zderzacz.y = y + OffsetY;}
private:
	int OffsetX;
	int OffsetY;

	SDL_Rect Zderzacz;
};

#endif