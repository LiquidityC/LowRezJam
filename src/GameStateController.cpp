#include "GameStateController.h"
#include "JamJar.h"
#include "Wall.h"
#include "Floor.h"
#include "Jam.h"
#include "Spoon.h"

void GameStateController::handle(const SDL_Event& event)
{
	
}

bool GameStateController::gameStateCheck(flat2d::GameData *gameData)
{
	generator.generate(gameData);
	return false;
}

void GameStateController::resetGame(flat2d::GameData *gameData)
{
	flat2d::EntityContainer *container = gameData->getEntityContainer();
	container->unregisterAllObjects();

	gameData->getRenderData()->getCamera()->setMapDimensions(64, 64);

	// Create the Jam jar
	JamJar *jamJar = new JamJar(28, 50);
	jamJar->init(gameData);
	container->registerObject(jamJar);

	// Add the side walls
	container->registerObject(new Wall(-9));
	container->registerObject(new Wall(65));
	container->registerObject(new Floor(59));

	Jam *jam = new Jam(50);
	jam->init(gameData);
	container->registerObject(jam);

	Spoon *spoon = new Spoon(30);
	spoon->init(gameData);
	container->registerObject(spoon);
}
