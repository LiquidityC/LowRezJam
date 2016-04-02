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

	activeKeys[event.key.keysym.sym] = event.type == SDL_KEYDOWN;
}

void JamJar::preMove(const flat2d::GameData *gameData)
{
	entityProperties.setXvel(0);
	if (activeKeys[SDLK_LEFT] ^ activeKeys[SDLK_RIGHT]) {
		entityProperties.setXvel(activeKeys[SDLK_LEFT] ? -100 : 100);
	}
}

bool JamJar::onVerticalCollision(flat2d::Entity *collider, const flat2d::GameData *gameData)
{
	switch (collider->getType()) {
		case EntityType::SPOON:
			jamContent--;
			break;
		case EntityType::JAM:
			jamContent++;
			break;
		default:
			break;
	}

	return false;
}
