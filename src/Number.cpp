#include "Number.h"

void Number::init(const flat2d::GameData *gameData)
{
	SDL_Renderer *renderer = gameData->getRenderData()->getRenderer();
	setTexture(flat2d::MediaUtil::loadTexture("textures/Numbers.png", renderer));
}

void Number::setValue(int value)
{
	this->value = value;
}

void Number::render(const flat2d::RenderData *renderData) const
{
	SDL_Renderer *renderer = renderData->getRenderer();
	int v = value;
	int rest;
	SDL_Rect clip = { 0, 0, 8, 13 };
	SDL_Rect box = { entityProperties.getXpos() + (9*3), entityProperties.getYpos(), 8, 13 };

	while (v > 0) {
		rest = v % 10;
		clip.x = rest * 8;
		SDL_RenderCopy(renderer, texture, &clip, &box);
		v = (v - rest) / 10;
		clip.x = 0;
		box.x -= 9;
	}
}

