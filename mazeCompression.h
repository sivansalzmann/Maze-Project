#pragma once

#include <fstream>
#include <string>

#include "Maze2d.h"

class mazeCompression {
public:
	mazeCompression() : _myMaze(nullptr) {}
	mazeCompression(Maze2d* maze) : _myMaze(maze) {}
	~mazeCompression() { delete _myMaze; }
	void writeMazeFile(string fileName);
	vector<int> readMazeFile(string fileName);

private:
	Maze2d* _myMaze;
};
