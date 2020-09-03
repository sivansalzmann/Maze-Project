#pragma once

#include <iostream>
#include <memory>
#include <stack> 
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#include "Maze2dGeneratorAB.h"
#include "cell.h"

class simpleMaze2dGenerator : public Maze2dGeneratorAB {
public:
	simpleMaze2dGenerator();
	virtual Maze2d& generate(size_t height, size_t width, string name);
	void fromintToCell(size_t height, size_t width, position start, position goal);

	//temporary
	vector<vector<cell>> getmyvector() { return _cellboard; }
	void printBoard(size_t x, size_t y);

private:
	vector<vector<cell>> _cellboard;
};


