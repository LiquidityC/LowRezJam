#ifndef MAINSCREEN_H_
#define	MAINSCREEN_H_

#include <flat/flat.h>

class MainScreen : public flat2d::Entity
{
	public:
		MainScreen() : Entity(0, 0, 64, 64) {
			entityProperties.setCollidable(false);
		}

		~MainScreen() {
			SDL_DestroyTexture(texture);
		}

		void init(const flat2d::GameData*);
};

#endif // MAINSCREEN_H_
