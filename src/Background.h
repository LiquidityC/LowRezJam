#ifndef BACKGROUND_H_
#define	BACKGROUND_H_

#include <flat/flat.h>

class Background : public flat2d::Entity
{
	public:
		Background() : Entity(0, 0, 64, 64) {
			entityProperties.setCollidable(false);
		}

		~Background() {
			SDL_DestroyTexture(texture);
		}

		void init(const flat2d::GameData*);
};

#endif // BACKGROUND_H_
