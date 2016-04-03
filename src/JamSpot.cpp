#include "JamSpot.h"

void JamSpot::init(const flat2d::GameData *gameData)
{
	SDL_Renderer *renderer = gameData->getRenderData()->getRenderer();
	setTexture(flat2d::MediaUtil::loadTexture("textures/JamSpot.png", renderer));
}
