#ifndef GAMESTATECONTROLLER_H_
#define	GAMESTATECONTROLLER_H_

#include <flat/flat.h>
#include "EntityGenerator.h"
#include "JamJar.h"
#include "GameStates.h"

class GameStateController : public flat2d::VirtualGameStateController
{
	private:
		EntityGenerator generator;
		JamJar *jamJar = nullptr;
		GameState state = GameState::MAIN_MENU;
		bool stateChange = false;

		void reloadMainMenu(flat2d::GameData*);
		void reloadLevelScreen(flat2d::GameData*);
		void reloadWinScreen(flat2d::GameData*);
		void reloadGameOverScreen(flat2d::GameData*);
		void reloadGame(flat2d::GameData*);

		void setState(GameState);

	public:
		~GameStateController() {
			if (jamJar) {
				delete jamJar;
				jamJar = nullptr;
			}
		}

		void handle(const SDL_Event& event);
		bool gameStateCheck(flat2d::GameData *gameData);
		bool quit();
		
		void resetGame(flat2d::GameData*);

		void setGameState(GameState);
};


#endif // GAMESTATECONTROLLER_H_
