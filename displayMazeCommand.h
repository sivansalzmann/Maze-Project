#pragma once

#include "command.h"

class displayMazeCommand : public command {
public:
	displayMazeCommand(string name, mapNames* maps) : command(), _mazename(name), _maps(maps) {}

	void execute() {

		// check if maze name exist
		// get maze
		// display maze board

		if (_maps->findIfmapNameExist(_mazename)) {			
			
			Maze2d* map = _maps->getMap(_mazename);			// get map with name X
			cout << "you'r maze : " << endl;
			cout << endl;
			cout << *map << endl;
		}
		else {
			throw "maze dosen't exist";
		}
	}

private:
	string _mazename;
	mapNames* _maps;
};
