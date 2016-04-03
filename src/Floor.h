#ifndef FLOOR_H_
#define	FLOOR_H_

#include <flat/flat.h>
#include "EntityTypes.h"

class Floor : public flat2d::Entity
{
	public:
		Floor(int y) : Entity(0, y, 64, 8) {
			entityProperties.setCollidable(true);
		}

		int getType() const {
			return EntityType::FLOOR;
		}
};

#endif // FLOOR_H_
