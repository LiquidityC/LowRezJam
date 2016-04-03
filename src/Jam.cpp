#include "Jam.h"
#include "JamSpot.h"

void Jam::init(const flat2d::GameData *gameData)
{
	setTexture(flat2d::MediaUtil::loadTexture("textures/Jam.png",
				gameData->getRenderData()->getRenderer()));

}

void Jam::preMove(const flat2d::GameData *gameData)
{
	if (clipTimer.getTicks() > 50) {
		clipTimer.stop();
		clipTimer.start();

		clipIndex++;
		clipIndex = clipIndex % 4;
		SDL_Rect rect = { clipIndex * 5, 0, 5, 5 };
		setClip(rect);
	}

	entityProperties.setYvel(35);
}

bool Jam::onVerticalCollision(flat2d::Entity *collider, const flat2d::GameData *gameData)
{
	bool createSpot = false;
	switch (collider->getType()) {
		case EntityType::SPOON:
			return true;
		case EntityType::JAM:
			return true;
		case EntityType::JAM_SPOT:
			return true;
		case EntityType::FLOOR:
			createSpot = true;
			break;
		default:
			break;
	}

	if (createSpot) {
		JamSpot *jamSpot = new JamSpot(entityProperties.getXpos(), entityProperties.getYpos() + 4);
		jamSpot->init(gameData);
		gameData->getEntityContainer()->registerObject(jamSpot);
	}

	setDead(true);
	return true;
}
