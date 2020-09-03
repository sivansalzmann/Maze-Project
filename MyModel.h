#pragma once

#include <string>
#include <unordered_map>

#include "Maze2d.h"
#include "mazeCompression.h"
#include "Solution.h"
#include "cell.h"

#define FileNAme "mazeSolutions"

class MyModel {
public:
	MyModel() {}
	MyModel(MyModel& Model) {					// copy constractor

		for (auto it = Model.getMap().begin(); it != Model.getMap().end(); ++it) {
			
			myMazeSolution.insert(pair<Maze2d*, Solution<cell>*>(it->first, it->second));
		}
	}
	~MyModel() { writeMazeMapFile(); }
	void insertToMap(Maze2d& myMaze, Solution<cell>& mySolution) {
		myMazeSolution.insert(pair<Maze2d*,Solution<cell>*>(new Maze2d(myMaze), new  Solution<cell>(mySolution)));
	}
	std::unordered_map<Maze2d*, Solution<cell>*>& getMap() { return myMazeSolution; }
	void writeMazeMapFile();					// save my map to file when program stop runing
	void readMazeMapFile();						// load my map from file when program starts runing

	bool findIfSolutionExist(Maze2d* maze) {
		for (auto start = myMazeSolution.begin(); start != myMazeSolution.end(); start++) {

			if (*(*start).first == *maze) {		// this maze solution already exist		
				return true;
			}
		}
		return false;
	}

	Solution<cell>* getSolution(Maze2d* maze) {

		if (findIfSolutionExist(maze)) {

			for (auto start = myMazeSolution.begin(); start != myMazeSolution.end(); start++) {

				if (*(*start).first == *maze) {		// this maze solution already exist		
					return (*start).second;			// return solution
				}
			}
		}
		else
			cout << "solution dosen't exist" << endl;
		
		Solution<cell>* tmp = nullptr;
		return tmp;
	}

private:
	std::unordered_map<Maze2d*, Solution<cell>*> myMazeSolution;
};
