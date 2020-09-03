#pragma once

#include "command.h"

class mazeSizeCommand : public command {
public:
	mazeSizeCommand(string name, mapNames* maps) : command(), _mazename(name), _maps(maps) {}

	void execute() {

		// check if maze name exist
		// get maze
		// display maze size

		if (_maps->findIfmapNameExist(_mazename)) {

			Maze2d* map = _maps->getMap(_mazename);			// get map with name X
			size_t sizeVector = map->getBoard().size();
			size_t sizeMze = sizeVector * sizeof(cell);
			cout << sizeMze << endl;
		}
		else {
			throw "maze dosen't exist";
		}
	}

private:
	string _mazename;
	mapNames* _maps;
};
