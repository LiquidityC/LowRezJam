#ifndef SPOON_H_
#define	SPOON_H_

#include <flat/flat.h>

class Spoon : public flat2d::Entity
{
	private:
		int clipIndex = 0;
		flat2d::Timer clipTimer;

	public:
		Spoon(int x) : Entity(x, 0, 5, 10) {
			entityProperties.setCollidable(true);
			clipTimer.start();
		}

		~Spoon() {
			if(texture) {
				SDL_DestroyTexture(texture);
				texture = nullptr;
			}
		}

		void init(const flat2d::GameData*);
		void preMove(const flat2d::GameData*);

		bool onVerticalCollision(flat2d::Entity *collider, const flat2d::GameData *gameData) {
			setDead(true);
			return true;
		}
};

#endif // SPOON_H_
