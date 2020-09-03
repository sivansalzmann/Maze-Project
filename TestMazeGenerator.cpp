#include "TestMazeGenerator.h"

#define height 10
#define width  10
#define name "myMaze"

void TestMazeGenerator::testMazeGenerator(Maze2dGenerator& mg) {

	cout << mg.measureAlgorithmTime(height, width, name) << endl;
	Maze2d maze = mg.generate(height, width, name);
	position P = maze.getStartPosition();
	cout << P << endl;
	vector<string> moves = maze.getPossibleMoves(P);				// from start position
	for (string move : moves)
		cout << move << endl;
	cout << maze.getGoalPosition() << endl;
	cout << maze << endl;

	delete& mg;
}