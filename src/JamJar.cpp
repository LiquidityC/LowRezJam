#include "JamJar.h"

void JamJar::init(const flat2d::GameData *gameData)
{
	SDL_Renderer *renderer = gameData->getRenderData()->getRenderer();
	setTexture(flat2d::MediaUtil::loadTexture("textures/JamJar.png", renderer));
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

void JamJar::postMove(const flat2d::GameData *gameData)
{
	// Update the jam with the JamJars position
}

void JamJar::render(const flat2d::RenderData *renderData) const
{
	for (auto it = jam.begin(); it != jam.end(); it++) {
		(*it)->render(renderData->getRenderer());
	}
	Entity::render(renderData);
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
