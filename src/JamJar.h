#ifndef JAMJAR_H_
#define	JAMJAR_H_

#include <flat/flat.h>
#include <map>
#include <vector>
#include "EntityTypes.h"

class JamJar : public flat2d::Entity
{
	private:
		std::map<SDL_Keycode, bool> activeKeys;
		std::vector<flat2d::Texture*> jam;
		int jamContent = 0;
		int maxSpeed = 100;

		void reduceJamLevel(int increase);
		void increaseJamLevel(int decrease, SDL_Renderer*);

	public:
		JamJar(int x, int y) : Entity(x, y, 8, 8) { }

		~JamJar() {
			if (texture) {
				SDL_DestroyTexture(texture);
				texture = nullptr;
			}
			for (auto it = jam.begin(); it != jam.end(); it++) {
				delete *it;
			}
			jam.clear();
		}

		int getType() const {
			return EntityType::JAM_JAR;
		}

		void init(const flat2d::GameData*);
		void handle(const SDL_Event& event);
		void preMove(const flat2d::GameData*);
		void postMove(const flat2d::GameData*);
		void render(const flat2d::RenderData*) const;
		bool onVerticalCollision(flat2d::Entity *collider, const flat2d::GameData*);
		bool onHorizontalCollision(flat2d::Entity *collider, const flat2d::GameData*);

		bool isBroken() const {
			return jamContent < 0;
		}

		bool isFull() const {
			return jamContent > 5;
		}
};

#endif // JAMJAR_H_
