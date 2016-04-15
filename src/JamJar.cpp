#include "JamJar.h"
#include "AudioMappings.h"

void JamJar::init(const flat2d::GameData *gameData)
{
	SDL_Renderer *renderer = gameData->getRenderData()->getRenderer();
	setTexture(flat2d::MediaUtil::loadTexture("textures/JamJar.png", renderer));
	setInputHandler(true);
	entityProperties.setCollidable(true);
}

void JamJar::handle(const SDL_Event& event)
{
	if (event.type != SDL_KEYUP && event.type != SDL_KEYDOWN) {
		return;
	}

	activeKeys[event.key.keysym.sym] = event.type == SDL_KEYDOWN;
}

void JamJar::preMove(const flat2d::GameData *gameData)
{
	entityProperties.setXvel(0);
	if (activeKeys[SDLK_LEFT] ^ activeKeys[SDLK_RIGHT]) {
		entityProperties.setXvel(activeKeys[SDLK_LEFT] ? -maxSpeed : maxSpeed);
	}

	if (static_cast<size_t>(jamContent) > jam.size()) {
		increaseJamLevel(jamContent - jam.size(), gameData->getRenderData()->getRenderer());
	} else if (static_cast<size_t>(jamContent) < jam.size()) {
		reduceJamLevel(jam.size() - jamContent);
	}
}

void JamJar::increaseJamLevel(int increase, SDL_Renderer *renderer)
{
	int xpos = entityProperties.getXpos() + 1;
	int ypos = entityProperties.getYpos() + (7 - jamContent);

	for (int i = 0; i < increase; i++) {
		flat2d::Texture *texture = new flat2d::Texture(xpos, ypos);
		texture->loadFromFile("textures/JarJam.png", renderer);
		jam.push_back(texture);
	}
}

void JamJar::reduceJamLevel(int decrease)
{
	for (int i = 0; i < decrease; i++) {
		delete jam.back();
		jam.pop_back();
	}
}

void JamJar::postMove(const flat2d::GameData *gameData)
{
	int xpos = entityProperties.getXpos() + 1;
	for (auto it = jam.begin(); it != jam.end(); it++) {
		(*it)->setXpos(xpos);
	}

	// Reset maxSpeed after collision
	maxSpeed = 100;
}

void JamJar::render(const flat2d::RenderData *renderData) const
{
	for (auto it = jam.begin(); it != jam.end(); it++) {
		(*it)->render(renderData->getRenderer());
	}
	Entity::render(renderData);
}

bool JamJar::onHorizontalCollision(flat2d::Entity *collider, const flat2d::GameData *gameData)
{
	bool speedChange = false;

	switch (collider->getType()) {
		case EntityType::SPOON:
			return true;
		case EntityType::JAM:
			return true;
		case EntityType::JAM_SPOT:
			maxSpeed = 30;
			speedChange = true;
			break;
		default:
			return false;
	}

	if (speedChange) {
		if (activeKeys[SDLK_LEFT] ^ activeKeys[SDLK_RIGHT]) {
			entityProperties.setXvel(activeKeys[SDLK_LEFT] ? -maxSpeed : maxSpeed);
		}
		return true;
	}

	return false;
}

bool JamJar::onVerticalCollision(flat2d::Entity *collider, const flat2d::GameData *gameData)
{
	switch (collider->getType()) {
		case EntityType::SPOON:
			jamContent--;
			break;
		case EntityType::JAM:
			jamContent++;
			break;
		default:
			break;
	}

	if (jamContent < 0) {
		gameData->getMixer()->playEffect(Effect::SHATTER);
	}


	return false;
}
