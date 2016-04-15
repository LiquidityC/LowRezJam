cmake_minimum_required (VERSION 3.2.0)

SET(CMAKE_COLOR_MAKEFILE ON)
#SET(CMAKE_VERBOSE_MAKEFILE ON)

project (LowRezJam CXX)

# Look for deps
INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
PKG_SEARCH_MODULE(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)
PKG_SEARCH_MODULE(SDL2MIXER REQUIRED SDL2_mixer>=2.0.0)

add_definitions("-std=c++11 -Wall")

add_subdirectory(flat)

include_directories(${PROJECT_BINARY_DIR} ${PROJECT_BINARY_DIR}/flat/include include)
link_directories(${PROJECT_BINARY_DIR}/flat/lib)

add_executable(lowrezjam src/game.cpp src/GameStateController.cpp src/JamJar.cpp
	src/Jam.cpp src/Spoon.cpp src/EntityGenerator.cpp src/JamSpot.cpp src/Background.cpp
	src/Number.cpp src/ResourceLoader.cpp)

if (MINGW)
	target_link_libraries(lowrezjam flat -lmingw32 -lSDL2main -lSDL2 -mwindows -lSDL2_image -lSDL2_mixer -lSDL2_ttf)
else (MINGW)
	target_link_libraries(lowrezjam flat -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf)
endif (MINGW)
