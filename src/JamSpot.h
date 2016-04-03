#ifndef JAMSPOT_H_
#define	JAMSPOT_H_

#include <flat/flat.h>
#include "EntityTypes.h"

class JamSpot : public flat2d::Entity
{
	public:
		JamSpot(int x, int y) : Entity(x, y, 5, 4) {
			entityProperties.setCollidable(true);
		}

		~JamSpot() {
			SDL_DestroyTexture(texture);
		}

		int getType() const {
			return EntityType::JAM_SPOT;
		}

		void init(const flat2d::GameData*);
};

#endif // JAMSPOT_H_
