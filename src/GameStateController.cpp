#include "GameStateController.h"
#include "Wall.h"
#include "Floor.h"
#include "Jam.h"
#include "Spoon.h"
#include "Background.h"
#include "MainScreen.h"
#include "Layers.h"

void GameStateController::handle(const SDL_Event& event)
{
	if (state == GameState::MAIN_MENU) {
		if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
			setState(GameState::GAME);
		}
	}
}

void GameStateController::setState(GameState state)
{
	if (this->state != state) {
		this->state = state;
		stateChange = true;
	}
}

bool GameStateController::gameStateCheck(flat2d::GameData *gameData)
{
	// Game win
	if (jamJar != nullptr && jamJar->isFull()) {
		generator.setLevel(generator.getLevel() + 1);
		resetGame(gameData);
		return true;
	} else if (jamJar != nullptr && jamJar->isBroken()) {
		// GameOver
	}

	if (stateChange) {
		resetGame(gameData);
		stateChange = false;
		return true;
	}

	if (state == GameState::GAME) {
		generator.generate(gameData);
	}
	return false;
}

bool GameStateController::quit()
{
	return jamJar != nullptr && jamJar->isBroken();
}

void GameStateController::resetGame(flat2d::GameData *gameData)
{
	flat2d::EntityContainer *container = gameData->getEntityContainer();
	container->unregisterAllObjects();
	container->addLayer(BG);
	container->addLayer(FG);

	switch (state) {
		case GameState::MAIN_MENU:
			reloadMainMenu(gameData);
			break;
		case GameState::LEVEL_SCREEN:
			reloadLevelScreen(gameData);
			break;
		case GameState::GAME:
			reloadGame(gameData);
			break;
		case GameState::WIN:
			reloadWinScreen(gameData);
			break;
		case GameState::GAME_OVER:
			reloadGameOverScreen(gameData);
			break;
		default:
			break;
	}
}

void GameStateController::reloadMainMenu(flat2d::GameData *gameData)
{
	flat2d::Entity *main = new MainScreen();
	main->init(gameData);
	gameData->getEntityContainer()->registerObject(main, BG);
}

void GameStateController::reloadLevelScreen(flat2d::GameData *gameData)
{
	// implement
}

void GameStateController::reloadWinScreen(flat2d::GameData *gameData)
{
	// implement
}

void GameStateController::reloadGameOverScreen(flat2d::GameData *gameData)
{
	// implement
}

void GameStateController::reloadGame(flat2d::GameData *gameData)
{
	flat2d::EntityContainer *container = gameData->getEntityContainer();

	gameData->getRenderData()->getCamera()->setMapDimensions(64, 64);

	flat2d::Entity *bg = new Background();
	bg->init(gameData);
	container->registerObject(bg, BG);

	jamJar = new JamJar(28, 50);
	jamJar->init(gameData);
	container->registerObject(jamJar, FG);

	// Add the side walls
	container->registerObject(new Wall(-9), BG);
	container->registerObject(new Wall(65), BG);
	container->registerObject(new Floor(59), BG);
}

void GameStateController::setGameState(GameState state)
{
	this->state = state;
}
