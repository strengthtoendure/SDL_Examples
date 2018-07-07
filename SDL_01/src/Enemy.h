#ifndef __ENEMY__
#define __ENEMY__
#include <iostream>
#include "GameObject.h"
#include <SDL2/SDL.h>

class Enemy : public GameObject
{
public:
	void load(int x, int y, int width, int height, std::string textureID);
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
};

#endif