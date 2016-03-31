#ifndef JAMJAR_H_
#define	JAMJAR_H_

#include <flat/flat.h>
#include <map>

class JamJar : public flat2d::Entity
{
	private:
		std::map<SDL_Keycode, bool> activeKeys;

	public:
		JamJar(int x, int y) : Entity(x, y, 8, 8) { }

		~JamJar() {
			if (texture) {
				SDL_DestroyTexture(texture);
				texture = nullptr;
			}
		}

		void init(const flat2d::GameData*);
		void handle(const SDL_Event& event);
		void preMove(const flat2d::GameData*);
};

#endif // JAMJAR_H_
