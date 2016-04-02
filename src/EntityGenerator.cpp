#include <random>
#include "EntityGenerator.h"
#include "Jam.h"
#include "Spoon.h"

void EntityGenerator::generate(const flat2d::GameData *gameData)
{
	if (jamTimer.getTicks() > 4000) {
		jamTimer.stop();
		jamTimer.start();
		generateJam(gameData);
	}
	if (spoonTimer.getTicks() > 4500) {
		spoonTimer.stop();
		spoonTimer.start();
		generateSpoon(gameData);
	}
}

void EntityGenerator::generateSpoon(const flat2d::GameData *gameData)
{
	flat2d::EntityContainer *entityContainer = gameData->getEntityContainer();

	flat2d::Entity *entity = new Spoon(getRandomNumber(0, 59));
	entity->init(gameData);
	entityContainer->registerObject(entity);
}

void EntityGenerator::generateJam(const flat2d::GameData *gameData)
{
	flat2d::EntityContainer *entityContainer = gameData->getEntityContainer();

	flat2d::Entity *entity = new Jam(getRandomNumber(0, 59));
	entity->init(gameData);
	entityContainer->registerObject(entity);
}

int EntityGenerator::getRandomNumber(int min, int max) const
{
	std::random_device random;
	std::mt19937 engine(random());
	std::uniform_int_distribution<int> dist(min, max);

	return dist(engine);
}
