#include "mazeCompression.h"

void mazeCompression::writeMazeFile(string fileName)
{
	vector<int> DataMaze = _myMaze->getData();

	std::ofstream mazeFile;
	mazeFile.open(fileName, ios::out | std::ios::binary);								// open file
	if (!mazeFile)
		throw "cannot open file";

	int size = DataMaze.size();
	mazeFile.write((char*)(&size), sizeof(int));

	for(auto begin = DataMaze.begin(); begin != DataMaze.end(); begin++)				// write to file
		mazeFile.write((char*)(&(*begin)), sizeof(int));
		

	mazeFile.close();																	// close file

	if (!mazeFile.good())		// good = 1
		throw "Error occurred at writing time";

	
}

vector<int> mazeCompression::readMazeFile(string fileName)
{
	
	vector<int> rawfilebuffer;
	int len = 0;												// same size for all mazes
	

	std::ifstream readMazeFile;
	readMazeFile.open(fileName, ios::in | std::ios::binary);							// open file
	if (!readMazeFile)
		throw "cannot open file";


	
	readMazeFile.read((char*)(&len), sizeof(int));
	
	rawfilebuffer.resize(len);
	for (auto begin = rawfilebuffer.begin(); begin != rawfilebuffer.end(); begin++)		// read from file to rawfilebuffer
			readMazeFile.read((char*)(&(*begin)), sizeof(int));

	readMazeFile.close();																// close file

	if (!readMazeFile.good())
		throw "Error occurred at reading time";

	return rawfilebuffer;
}