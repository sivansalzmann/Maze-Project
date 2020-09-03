#pragma once
#include "Maze2dGenerator.h"

#include <sstream>
class Maze2dGeneratorAB : public Maze2dGenerator
{
public:
	Maze2dGeneratorAB() = default;
	~Maze2dGeneratorAB() = default;
	virtual string measureAlgorithmTime(size_t height, size_t width, string name);
	
};
