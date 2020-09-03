#pragma once

#include "Maze2dGeneratorAB.h"
#include "cell.h"

#include <time.h>
#include <random>
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include<string>


class myMaze2dGenerator : public Maze2dGeneratorAB
{
public:
	myMaze2dGenerator();

	vector<int> generateRandomDirections();
	void recursion(int r, int c, int _height, int _width);

	virtual Maze2d& generate(size_t height, size_t width, string name);
	void fromintToCell(size_t height, size_t width);

	vector<vector<cell>> getmyvector() { return _cellboard; }
	void printBoard(int x, int y);

private:
	vector<vector<cell>> _cellboard;
};