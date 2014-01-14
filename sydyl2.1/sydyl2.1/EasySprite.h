#ifndef EASYSPRITE
#define EASYSPRITE

#include "SDL_Setup.h"
#include <string>
#include "SDL.h"
#include "SDL_image.h"
#include "KolizjaRect.h"

class EasySprite
{
private:
	SDL_Texture* image;
	SDL_Texture* collitest;
	SDL_Rect rect;
	SDL_Rect crop;
	SDL_Rect Kamera;

	int img_wdth;
	int img_hght;

	int animDelay;
	int CurrentFrame;
	int Amount_Frame_X;
	int Amount_Frame_Y;

	float *CameraX;
	float *CameraY;

	SDL_Renderer* renderer;

	KolizjaRect Zderzacz;

public:
	EasySprite(SDL_Renderer* p_renderer, std::string FilePath, int x, int y, int w, int h, float *pCameraX, float *pCameraY, KolizjaRect pZderzacz);
	~EasySprite(void);

	void PlayAnimation(int BeginFrame, int EndFrame, int Side, float Speed);
	void SetupAnimation(int pass_X, int pass_Y);

	void Draw();
	void DrawHero();


	void SetX(int X);
	void SetY(int Y);
	void SetPosition(int X, int Y);


	int GetX();
	int GetY();

	SDL_Rect GetCam(){return Kamera;}

	bool isColiding(KolizjaRect ZderzaczA);
	KolizjaRect GetZderzacz(){return Zderzacz;}
};

#endif