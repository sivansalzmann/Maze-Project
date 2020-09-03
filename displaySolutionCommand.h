#pragma once

#include "command.h"

class displaySolutionCommand : public command {
public:
	displaySolutionCommand(string name, mapNames* maps, MyModel* solutions) : command(), _mazename(name), _maps(maps), _mysolutions(solutions) {}

	void execute() {

		// check if there is a maze with name X
		// get maze
		// check if there is a solution in maze map
		// get solution
		// display the solution

		if (_maps->findIfmapNameExist(_mazename)) {					// maze exist

			Maze2d* maze = _maps->getMap(_mazename);				// get map with name X
			if (_mysolutions->findIfSolutionExist(maze)) {

				Solution<cell> mysolution(*_mysolutions->getSolution(maze));
				cout << mysolution << endl;
			}

		}
		else
			throw "solution dosen't exist";

	}

private:
	string _mazename;
	mapNames* _maps;
	MyModel* _mysolutions;
};