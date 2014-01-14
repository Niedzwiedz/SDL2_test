#include "Srodowisko.h"
#include "SDL.h"
#include "SDL_image.h"



Srodowisko::Srodowisko(SDL_Setup* pSDLClass, int SCRWDTH, int SCRHGT, float* passedCameraX, float* passedCameraY)
{
	CameraX = passedCameraX;
	CameraY = passedCameraY;
	sdlclass = pSDLClass;
	for(int i=0; i <= 1; i++){
		int j = 0;
		trawa[i][j] = new EasySprite(sdlclass->GetRenderer(), "data/envoirment/grass.bmp", SCRWDTH*i,SCRHGT*j,SCRWDTH,SCRHGT, CameraX,CameraY, KolizjaRect());
	}
	LoadFromFile();
}


Srodowisko::~Srodowisko(void)
{
	for(int i=0; i <= 1; i++){
			int j = 0;
			delete trawa[i][j];
		}
	for(std::vector<Block*>::iterator i = block.begin(); i!=block.end(); ++i){
		delete (*i);
	}
	block.clear();
}

void Srodowisko::LoadFromFile(){
	std::ifstream LoadedFile ("data/maps/test2.txt");
	int k = 0;
	int l = 0;
	
	int posx=0;
	int posy=0;
	char Tile;
	enum ObjectType{
		TypeNone,
		TypeBlock
	};
	int CurrentType = TypeNone;
	if(LoadedFile.is_open()){
		while(LoadedFile.good()){
			LoadedFile >> Tile;
			if(Tile == '#'){
				CurrentType=TypeBlock;
				k++;
				posx=40*k;
				posy=40*l;
				block.push_back(new Block(CameraX, CameraY, sdlclass, posx, posy));
			}
			else if(Tile == '.'){
				CurrentType=TypeNone;
				k++;
			}
			else if(Tile == '$'){
				l++;
				k = 0;
			}
		}
	}
	else{
		std::cout << "Map Error" << std::endl;
	}
	LoadedFile.close();
}

void Srodowisko::DrawBack(){
	for(int i=0; i <= 1; i++){
			int j = 0;
			trawa[i][j] -> Draw();
		}
	for(std::vector<Block*>::iterator i = block.begin(); i!=block.end(); ++i){
		(*i)->DrawBlock();
	}
}

void Srodowisko::DrawFront(){
	
}
