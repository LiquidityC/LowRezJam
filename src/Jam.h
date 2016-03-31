#ifndef JAM_H_
#define	JAM_H_

#include <flat/flat.h>

class Jam : public flat2d::Entity
{
	private:
		int clipIndex = 0;
		flat2d::Timer clipTimer;

	public:
		Jam(int x) : Entity(x, 0, 5, 5) {
			entityProperties.setCollidable(true);
			clipTimer.start();
		}

		~Jam() {
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

#endif // JAM_H_
