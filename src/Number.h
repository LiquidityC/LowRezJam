#ifndef NUMBER_H_
#define	NUMBER_H_

#include <flat/flat.h>

class Number : public flat2d::Entity
{
	private:
		int value;

		

	public:
		Number(int x, int y) : Entity(x, y, 10, 10) {
			entityProperties.setCollidable(false);
			setInputHandler(false);
		}

		~Number() {
			SDL_DestroyTexture(texture);
		}

		void init(const flat2d::GameData*);

		void setValue(int value);

		void render(const flat2d::RenderData*) const;
};

#endif // NUMBER_H_
