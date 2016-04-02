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

	public:
		JamJar(int x, int y) : Entity(x, y, 8, 8) { }

		~JamJar() {
			if (texture) {
				SDL_DestroyTexture(texture);
				texture = nullptr;
			}
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
};

#endif // JAMJAR_H_
