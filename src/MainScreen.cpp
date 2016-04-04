#include "MainScreen.h"

void MainScreen::init(const flat2d::GameData *gameData)
{
	SDL_Renderer *renderer = gameData->getRenderData()->getRenderer();
	setTexture(flat2d::MediaUtil::loadTexture("textures/MainMenu.png", renderer));
}
