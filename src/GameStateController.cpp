#include "GameStateController.h"
#include "Wall.h"
#include "Floor.h"
#include "Jam.h"
#include "Spoon.h"
#include "Background.h"
#include "Layers.h"
#include "Number.h"

void GameStateController::handle(const SDL_Event& event)
{
	switch (state) {
		case GameState::MAIN_MENU:
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
				setState(GameState::LEVEL_SCREEN);
			}
			break;
		case GameState::LEVEL_SCREEN:
			if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
				setState(GameState::GAME);
			}
			break;
		case GameState::GAME_OVER:
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_r) {
					generator.setLevel(1);
					setState(GameState::LEVEL_SCREEN);
				} else if (event.key.keysym.sym == SDLK_q) {
					quitGame = true;
				}
			}
		default:
			break;
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
		setState(GameState::LEVEL_SCREEN);
	} else if (jamJar != nullptr && jamJar->isBroken()) {
		setState(GameState::GAME_OVER);
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
	return quitGame;
}

void GameStateController::resetGame(flat2d::GameData *gameData)
{
	flat2d::EntityContainer *container = gameData->getEntityContainer();
	jamJar = nullptr;
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
	flat2d::Entity *main = new Background("textures/MainMenu.png");
	main->init(gameData);
	gameData->getEntityContainer()->registerObject(main, BG);
}

void GameStateController::reloadLevelScreen(flat2d::GameData *gameData)
{
	flat2d::Entity *bg = new Background("textures/LevelScreen.png");
	bg->init(gameData);
	Number *number = new Number(20, 30);
	number->init(gameData);
	number->setValue(generator.getLevel());

	flat2d::EntityContainer * container = gameData->getEntityContainer();
	container->registerObject(bg, BG);
	container->registerObject(number, FG);
}

void GameStateController::reloadWinScreen(flat2d::GameData *gameData)
{
	// implement
}

void GameStateController::reloadGameOverScreen(flat2d::GameData *gameData)
{
	flat2d::Entity *main = new Background("textures/GameOver.png");
	main->init(gameData);
	gameData->getEntityContainer()->registerObject(main, BG);
}

void GameStateController::reloadGame(flat2d::GameData *gameData)
{
	flat2d::EntityContainer *container = gameData->getEntityContainer();

	gameData->getRenderData()->getCamera()->setMapDimensions(64, 64);

	flat2d::Entity *bg = new Background("textures/Background.png");
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
