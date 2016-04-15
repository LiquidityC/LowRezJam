#ifndef ENTITYGENERATOR_H_
#define	ENTITYGENERATOR_H_

#include <flat/flat.h>

class EntityGenerator
{
	private:
		flat2d::Timer timer;
		flat2d::Timer dontGetBoringTimer;

		void generateSpoon(const flat2d::GameData*);
		void generateJam(const flat2d::GameData*);
		int getRandomNumber(int min, int max) const;

		int level = 1;

	public:
		EntityGenerator() {
			timer.start();
			dontGetBoringTimer.start();
		}

		void generate(const flat2d::GameData*);

		void setLevel(int);
		int getLevel() const;
};

#endif // ENTITYGENERATOR_H_
