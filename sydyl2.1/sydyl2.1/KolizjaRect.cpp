#include "KolizjaRect.h"

KolizjaRect::KolizjaRect(){
	OffsetX = 0;
	OffsetY = 0;
	SetRect(0,0,0,0);
}

KolizjaRect::KolizjaRect(int x, int y, int w, int h){
	OffsetX = x;
	OffsetY = y;
	SetRect(0,0,w,h);
}


KolizjaRect::~KolizjaRect(void)
{
}

void KolizjaRect::SetRect(int x, int y, int w, int h){
	Zderzacz.x=x + OffsetX;
	Zderzacz.y=y + OffsetY;
	Zderzacz.w=w;
	Zderzacz.h=h;
}