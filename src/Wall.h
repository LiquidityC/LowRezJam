#ifndef WALL_H_
#define	WALL_H_

#include <flat/flat.h>

class Wall : public flat2d::Entity
{
	public:
		Wall(int x) : Entity(x, 0, 8, 64) {
			entityProperties.setCollidable(true);
		}
};

#endif // WALL_H_
