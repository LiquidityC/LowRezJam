#include "ResourceLoader.h"
#include "AudioMappings.h"

void ResourceLoader::loadSounds(const flat2d::GameData *gameData) const
{
	flat2d::Mixer *mixer = gameData->getMixer();

	mixer->loadEffect(Effect::SPOON_ON_GROUND, "sounds/SpoonOnGround.wav");
	mixer->loadEffect(Effect::SPOON_ON_JAR, "sounds/SpoonOnJar.wav");
	mixer->loadEffect(Effect::SPLAT, "sounds/Splat.wav");
	mixer->loadEffect(Effect::SHATTER, "sounds/Shatter.wav");
}
