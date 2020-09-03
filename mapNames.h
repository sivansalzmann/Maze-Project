#pragma once

#include <string>
#include <unordered_map>

#include "Maze2d.h"
#include "mazeCompression.h"
#include "Solution.h"
#include "cell.h"

class mapNames {
public:
	mapNames() {}
	void insertToMap(string name, Maze2d& myMaze) {
		_myMazeNames.insert(pair<string, Maze2d*>(name, new Maze2d(myMaze)));
	}

	std::unordered_map<string, Maze2d*>& getMap() { return _myMazeNames; }

	bool findIfmapNameExist(string name) {
		for (auto start = _myMazeNames.begin(); start != _myMazeNames.end(); start++) {

			if ((*start).first == name) {				// this maze name already exist
				return true;
			}
		}
		return false;
	}

	Maze2d* getMap(string name) {

		for (auto start = _myMazeNames.begin(); start != _myMazeNames.end(); start++) {

			if ((*start).first == name) {				// this maze name already exist
				
				return (*start).second;
			}
		}

		throw "map dosen't exist";
	}

private:
	std::unordered_map<string, Maze2d*> _myMazeNames;
};


