#ifndef ENTITYGENERATOR_H_
#define	ENTITYGENERATOR_H_

#include <flat/flat.h>

class EntityGenerator
{
	private:
		flat2d::Timer spoonTimer, jamTimer;

		void generateSpoon(const flat2d::GameData*);
		void generateJam(const flat2d::GameData*);
		int getRandomNumber(int min, int max) const;

	public:
		EntityGenerator() {
			spoonTimer.start();
			jamTimer.start();
		}

		void generate(const flat2d::GameData*);
};

#endif // ENTITYGENERATOR_H_
