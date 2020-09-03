#pragma once
#include <string>
#include <vector>
#include <chrono>
#include <iostream>
#include <string>
#include "Maze2d.h"

using namespace std;

class Maze2dGenerator
{
public:
	Maze2dGenerator() = default;
	~Maze2dGenerator() = default;
	virtual Maze2d& generate(size_t height, size_t width, string name) = 0;
	virtual string  measureAlgorithmTime(size_t height, size_t width, string name) = 0;
};

