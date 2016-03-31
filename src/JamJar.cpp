#include "JamJar.h"

void JamJar::init(const flat2d::GameData *gameData)
{
	setTexture(flat2d::MediaUtil::loadTexture("textures/JamJar.png",
				gameData->getRenderData()->getRenderer()));
	setInputHandler(true);
	entityProperties.setCollidable(true);
}

void JamJar::handle(const SDL_Event& event)
{
	if (event.type != SDL_KEYUP && event.type != SDL_KEYDOWN) {
		return;
	}

	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_LEFT) {
			entityProperties.setXvel(-100);
		}
		if (event.key.keysym.sym == SDLK_RIGHT) {
			entityProperties.setXvel(100);
		}
	} else {
		if (event.key.keysym.sym == SDLK_LEFT) {
			entityProperties.setXvel(0);
		}
		if (event.key.keysym.sym == SDLK_RIGHT) {
			entityProperties.setXvel(0);
		}
	}
}
