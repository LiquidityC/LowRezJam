#ifndef SPOON_H_
#define	SPOON_H_

#include <flat/flat.h>
#include "EntityTypes.h"

class Spoon : public flat2d::Entity
{
	private:
		int clipIndex = 0;
		flat2d::Timer clipTimer;

	public:
		Spoon(int x, int yv) : Entity(x, 0, 5, 10) {
			entityProperties.setCollidable(true);
			entityProperties.setYvel(yv);
			clipTimer.start();
		}

		~Spoon() {
			if(texture) {
				SDL_DestroyTexture(texture);
				texture = nullptr;
			}
		}

		int getType() const {
			return EntityType::SPOON;
		}


		void init(const flat2d::GameData*);
		void preMove(const flat2d::GameData*);

		bool onVerticalCollision(flat2d::Entity *collider, const flat2d::GameData *gameData);
};

#endif // SPOON_H_
