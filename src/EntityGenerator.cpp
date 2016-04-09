#include <random>
#include "EntityGenerator.h"
#include "Jam.h"
#include "Spoon.h"
#include "Layers.h"

void EntityGenerator::generate(const flat2d::GameData *gameData)
{
	unsigned int generateTime = 4000 / level;
	if (jamTimer.getTicks() > generateTime) {
		jamTimer.stop();
		jamTimer.start();
		for (int i = 0; i < (level % 6); i++) {
			generateJam(gameData);
		}
	}
	if (spoonTimer.getTicks() > generateTime) {
		spoonTimer.stop();
		spoonTimer.start();
		for (int i = 0; i < (level % 4); i++) {
			generateSpoon(gameData);
		}
	}
}

void EntityGenerator::generateSpoon(const flat2d::GameData *gameData)
{
	flat2d::EntityContainer *entityContainer = gameData->getEntityContainer();

	flat2d::Entity *entity = new Spoon(getRandomNumber(0, 59), getRandomNumber(30, 70));
	entity->init(gameData);
	entityContainer->registerObject(entity, FG);
}

void EntityGenerator::generateJam(const flat2d::GameData *gameData)
{
	flat2d::EntityContainer *entityContainer = gameData->getEntityContainer();

	flat2d::Entity *entity = new Jam(getRandomNumber(0, 59), getRandomNumber(30, 50));
	entity->init(gameData);
	entityContainer->registerObject(entity, FG);
}

int EntityGenerator::getRandomNumber(int min, int max) const
{
	std::random_device random;
	std::mt19937 engine(random());
	std::uniform_int_distribution<int> dist(min, max);

	return dist(engine);
}

void EntityGenerator::setLevel(int level)
{
	this->level = level;
}

int EntityGenerator::getLevel() const
{
	return level;
}
