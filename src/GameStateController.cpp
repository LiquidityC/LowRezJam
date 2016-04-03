#include "GameStateController.h"
#include "Wall.h"
#include "Floor.h"
#include "Jam.h"
#include "Spoon.h"
#include "Background.h"

void GameStateController::handle(const SDL_Event& event)
{
	
}

bool GameStateController::gameStateCheck(flat2d::GameData *gameData)
{
	generator.generate(gameData);
	return false;
}

bool GameStateController::quit()
{
	return jamJar != nullptr && (jamJar->isBroken() || jamJar->isFull());
}

void GameStateController::resetGame(flat2d::GameData *gameData)
{
	flat2d::EntityContainer *container = gameData->getEntityContainer();
	container->unregisterAllObjects();

	gameData->getRenderData()->getCamera()->setMapDimensions(64, 64);

	flat2d::Entity *bg = new Background();
	bg->init(gameData);
	container->registerObject(bg);

	// Create the Jam jar
	if (jamJar) {
		delete jamJar;
	}

	jamJar = new JamJar(28, 50);
	jamJar->init(gameData);
	container->registerObject(jamJar);

	// Add the side walls
	container->registerObject(new Wall(-9));
	container->registerObject(new Wall(65));
	container->registerObject(new Floor(59));
}
