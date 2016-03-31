cmake_minimum_required (VERSION 3.2.0)

SET(CMAKE_COLOR_MAKEFILE ON)

project (LowRezJam CXX)

add_definitions("-Wall")


add_subdirectory(flat)
include_directories(${PROJECT_BINARY_DIR} ${PROJECT_BINARY_DIR}/flat/include include)
link_directories(${PROJECT_BINARY_DIR}/flat/lib)

add_executable(lowrezjam src/game.cpp src/GameStateController.cpp src/JamJar.cpp
	src/Jam.cpp src/Spoon.cpp)
target_link_libraries(lowrezjam flat)
target_compile_options(lowrezjam PRIVATE -std=c++11)
