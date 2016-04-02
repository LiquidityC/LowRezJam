#ifndef GAMESTATECONTROLLER_H_
#define	GAMESTATECONTROLLER_H_

#include <flat/flat.h>
#include "EntityGenerator.h"

class GameStateController : public flat2d::VirtualGameStateController
{
	private:
		EntityGenerator generator;

	public:
		void handle(const SDL_Event& event);
		bool gameStateCheck(flat2d::GameData *gameData);
		
		void resetGame(flat2d::GameData*);
};


#endif // GAMESTATECONTROLLER_H_
