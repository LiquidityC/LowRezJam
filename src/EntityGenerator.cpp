#include <random>
#include "EntityGenerator.h"
#include "Jam.h"
#include "Spoon.h"
#include "Layers.h"

void EntityGenerator::generate(const flat2d::GameData *gameData)
{
	unsigned int time = 500;
	if (level > 10) {
		time = time / ((level - (level / 10))/10);
	}

	if (timer.getTicks() > time) {
		timer.stop();
		timer.start();

		bool genSpoon = getRandomNumber(1, 10) <= level;
		bool genJam = getRandomNumber(1, 10) <= level;

		if (genJam) {
			generateJam(gameData);
		}
		if (genSpoon) {
			generateSpoon(gameData);
		}

		if (genJam || genSpoon) {
			dontGetBoringTimer.stop();
			dontGetBoringTimer.start();
		}

		if (dontGetBoringTimer.getTicks() > 2000) {
			if (getRandomNumber(1, 2) == 1) {
				generateSpoon(gameData);
			} else {
				generateJam(gameData);
			}
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
	static std::random_device random;
	static std::mt19937 engine(random());
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
