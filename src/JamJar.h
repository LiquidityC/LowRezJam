#ifndef JAMJAR_H_
#define	JAMJAR_H_

#include <flat/flat.h>

class JamJar : public flat2d::Entity
{
	private:
		

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
};

#endif // JAMJAR_H_
