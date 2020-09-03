#pragma once

#include <vector>
#include "cell.h"
#include "position.h"

class Maze {
public:
	Maze() = default;
	virtual  vector<string> getPossibleMoves(position& myCurrentPos) = 0;
	virtual position getGoalPosition() = 0;
	virtual position getStartPosition() = 0;
	virtual vector<vector<cell>>& getBoard() = 0;
};
