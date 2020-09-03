#pragma once

#include "command.h"
#include "MazeSearchable.h"
#include "AStar.h"
#include "Heuristic.h"
#include "BFS.h"
#include "pitagorasH.h"
#include "manhattanH.h"

class solveMazeCommand : public command {
public:
	solveMazeCommand(string name, mapNames* maps, MyModel* solutions, int alg) : command(), _mazename(name), _maps(maps), _mysolutions(solutions), _alg(alg) {}

	void execute() {		

		// check if there is a maze with name X
		// get maze with name X
		// make maze searchable
		// see which algorithm was choosen
		// create algorithm
		// solve maze withchossen algorithm
		// save maze and solution to map

		if (_maps->findIfmapNameExist(_mazename)) {					// maze exist

			Maze2d* maze = _maps->getMap(_mazename);				// get map with name X
			MazeSearchable searchable(*maze);						// making maze searchable

			if (_alg == 1) {

				pitagorasH* heuristi = new pitagorasH();			// free dynamic at A*
				AStar<cell> algor(heuristi);
				Solution<cell>* temp = algor.search(searchable);
				Solution<cell> result(*temp);

				_mysolutions->insertToMap(*maze, result);			// save maze, solution
			}
			else if (_alg == 2) {

				manhattanH* heuristiM = new manhattanH();			// free dynamic at A*		
				AStar<cell> algM(heuristiM);
				Solution<cell>* tempM = algM.search(searchable);
				Solution<cell> resultM(*tempM);

				_mysolutions->insertToMap(*maze, resultM);			// save maze, solution
			}
			else if (_alg == 3) {

				BFS<cell> BFSalg;
				Solution<cell>* bfstemp = BFSalg.search(searchable);
				Solution<cell> bfsresult(*bfstemp);

				_mysolutions->insertToMap(*maze, bfsresult);		// save maze, solution
			}

		}
		else
			throw "maze dosen't exist";

	}

private:
	string _mazename;
	mapNames* _maps;
	MyModel* _mysolutions;
	int _alg;
};
