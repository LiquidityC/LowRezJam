#include "Spoon.h"

void Spoon::init(const flat2d::GameData *gameData)
{
	setTexture(flat2d::MediaUtil::loadTexture("textures/Spoon.png",
				gameData->getRenderData()->getRenderer()));

}

void Spoon::preMove(const flat2d::GameData *gameData)
{
	if (clipTimer.getTicks() > 60) {
		clipTimer.stop();
		clipTimer.start();

		clipIndex++;
		clipIndex = clipIndex % 6;
		SDL_Rect rect = { clipIndex * 5, 0, 5, 10 };
		setClip(rect);
	}
}

bool Spoon::onVerticalCollision(flat2d::Entity *collider, const flat2d::GameData *gameData)
{
	switch (collider->getType()) {
		case EntityType::SPOON:
			return true;
		case EntityType::JAM:
			return true;
		default:
			break;
	}

	setDead(true);
	return true;
}
