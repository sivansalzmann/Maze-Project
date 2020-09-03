#include "MyModel.h"



void MyModel::writeMazeMapFile() {

	int numOfmaze = 0;

	for (auto it = myMazeSolution.begin(); it != myMazeSolution.end(); ++it) {
		numOfmaze++;
	}

	

		std::ofstream mazeFile;
		mazeFile.open(FileNAme, ios::out | std::ios::binary);							// open file
		if (!mazeFile)
			throw "cannot open file";

		mazeFile.write((char*)(&numOfmaze), sizeof(int));								// write num of maze in map


		for (auto it = myMazeSolution.begin(); it != myMazeSolution.end(); ++it) {
			
			vector<int> DataMaze = it->first->getData();
			
			int size = DataMaze.size();
			mazeFile.write((char*)(&size), sizeof(int));

			for (auto begin = DataMaze.begin(); begin != DataMaze.end(); begin++)		// save to binary file every maze in map (include solution)
				mazeFile.write((char*)(&(*begin)), sizeof(int));
		}



		mazeFile.close();																// close file

		if (!mazeFile.good())		// good = 1
			throw "Error occurred at writing time";
	
}

void MyModel::readMazeMapFile() {		

	int numOfmaze = 0;

	std::ifstream readMazeFile;
	readMazeFile.open(FileNAme, ios::in | std::ios::binary);							// open file
	if (!readMazeFile)
		throw "cannot open file";

	readMazeFile.read((char*)(&numOfmaze), sizeof(int));



	if (numOfmaze != 0) {
		for (numOfmaze; numOfmaze > 0; numOfmaze--) {

			vector<int> rawfilebuffer;
			int len = 0;

			readMazeFile.read((char*)(&len), sizeof(int));

			rawfilebuffer.resize(len);
			for (auto begin = rawfilebuffer.begin(); begin != rawfilebuffer.end(); begin++)		// read from file to rawfilebuffer
				readMazeFile.read((char*)(&(*begin)), sizeof(int));

			Maze2d newmazefromFile(rawfilebuffer);
			Solution<cell> Newsolution(*newmazefromFile.getmySolution());						// create new solution for this maze

			insertToMap(newmazefromFile, Newsolution);											// insert information to map
		}
	}

	readMazeFile.close();																		// close file

	if (!readMazeFile.good())
		throw "Error occurred at reading time";

}