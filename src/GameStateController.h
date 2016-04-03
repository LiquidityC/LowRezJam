#ifndef GAMESTATECONTROLLER_H_
#define	GAMESTATECONTROLLER_H_

#include <flat/flat.h>
#include "EntityGenerator.h"
#include "JamJar.h"

class GameStateController : public flat2d::VirtualGameStateController
{
	private:
		EntityGenerator generator;
		JamJar *jamJar = nullptr;

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
};


#endif // GAMESTATECONTROLLER_H_
