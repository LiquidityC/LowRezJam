#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <flat/flat.h>
#include <iostream>
#include <string>
#include <sstream>

#include "GameStateController.h"
#include "Layers.h"
#include "ResourceLoader.h"

#define SCREEN_DIMENSION 512
#define SCREEN_SCALE_DIMENSION 64


int main( int argc, char* args[] )
{
	flat2d::FlatBuilder *flat = new flat2d::FlatBuilder;

	std::stringstream ss;
	ss << "LowRezRunner" << "0" << "." << "1a";
#ifdef DEBUG
	ss << " [DEBUG]";
#endif // DEBUG

	if (!flat->initSDL(ss.str(), SCREEN_DIMENSION, SCREEN_DIMENSION)) {
		return -1;
	}
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
	if (!flat->initContainers()) {
		return -1;
	}

	GameStateController *gameStateController = new GameStateController();
	gameStateController->resetGame(flat->getGameData());

	flat2d::GameEngine *engine = flat->getGameEngine();
	engine->init(24);

	SDL_RenderSetLogicalSize(flat->getGameData()->getRenderData()->getRenderer(), SCREEN_SCALE_DIMENSION, SCREEN_SCALE_DIMENSION);

	ResourceLoader loader;
	loader.loadSounds(flat->getGameData());

	auto gameStateCallback = [gameStateController](flat2d::GameData* gameData) -> flat2d::GameStateAction
	{
		if (gameStateController->quit()) {
			return flat2d::GameStateAction::QUIT;
		} else if (gameStateController->gameStateCheck(gameData)) {
			return flat2d::GameStateAction::RESET;
		} else {
			return flat2d::GameStateAction::NOOP;
		}
	};

	auto handleCallback = [gameStateController](const SDL_Event& event)
	{
		gameStateController->handle(event);
	};

	// Start the game loop
	engine->run(gameStateCallback, handleCallback);

	delete flat;

	return 0;
}
