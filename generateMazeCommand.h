#pragma once

#include "command.h"
#include "Maze2dGeneratorAB.h"
#include "myMaze2dGenerator.h"
#include "simpleMaze2dGenerator.h"


class generateMazeCommand : public command {
public:

	generateMazeCommand(string name, mapNames* maps, int rows, int colums) : command(), _mazename(name), _maps(maps), height(rows), width(colums) {}

	void execute() {

		//check if this maze name exist
		//if maze name dosent exist -- generate maze (create new maze)
		// save new maze to name maze map

		if (_maps->findIfmapNameExist(_mazename)) {
			throw "this maze name is already taken";
		}
		else {
			Maze2dGeneratorAB* myM = new myMaze2dGenerator;
			Maze2d maze(myM->generate(height, width, _mazename));			//algorithm create maze

			_maps->insertToMap(_mazename, maze);							// save new maze to (name, maze) map

			delete myM;
		}
	}

private:
	string _mazename;
	mapNames* _maps;
	int height;
	int width;
};

