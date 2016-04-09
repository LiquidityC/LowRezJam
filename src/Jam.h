#ifndef JAM_H_
#define	JAM_H_

#include <flat/flat.h>
#include "EntityTypes.h"

class Jam : public flat2d::Entity
{
	private:
		int clipIndex = 0;
		flat2d::Timer clipTimer;

	public:
		Jam(int x, int vel) : Entity(x, 0, 5, 5) {
			entityProperties.setCollidable(true);
			entityProperties.setYvel(vel);
			clipTimer.start();
		}

		~Jam() {
			if(texture) {
				SDL_DestroyTexture(texture);
				texture = nullptr;
			}
		}

		int getType() const {
			return EntityType::JAM;
		}

		void init(const flat2d::GameData*);
		void preMove(const flat2d::GameData*);

		bool onVerticalCollision(flat2d::Entity *collider, const flat2d::GameData *gameData);
};

#endif // JAM_H_
