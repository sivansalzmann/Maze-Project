#include "myMaze2dGenerator.h"
#include <iostream>
#include <chrono>

myMaze2dGenerator::myMaze2dGenerator() {

	position initial(-1, -1);
	cell init(initial);
	vector<cell> t = { init };

	//_numofcells = -1;
	_cellboard.push_back(t);
	/*cells.push(init);*/
}


void myMaze2dGenerator::fromintToCell(size_t height, size_t width) {

	/*vector<int> posInt;*/
	cell mycell;

	_cellboard.resize(height, vector<cell>(width));

	for (size_t row = 0; row < height; row++) {


		for (size_t col = 0; col < width; col++) {

			position myposition(row, col);
			mycell = myposition;


			vector<cell> cellinmaze{ mycell };
			_cellboard[row][col] = mycell;


		}
	}


	for (size_t row = 0; row < _cellboard.size(); row++) {

		for (size_t col = 0; col < _cellboard[row].size(); col++) {

			// initialize up, down, roght, left

			if (row + 1 < height) {				// down

				_cellboard[row][col].setdown(row + 1, col);
			}

			if (row - 1 >= 0) {					// up

				_cellboard[row][col].setup(row - 1, col);
			}

			if (col + 1 < width) {				// right

				_cellboard[row][col].setright(row, col + 1);
			}

			if (col - 1 >= 0) {					// left

				_cellboard[row][col].setleft(row, col - 1);
			}

		}
	}

}


Maze2d& myMaze2dGenerator::generate(size_t height, size_t width, string name)
{

	_cellboard.clear();

	fromintToCell(height, width);

	// find start position
	int r = rand() % height;
	while (r % 2 == 0)
		r = rand() % height;

	int c = rand() % width;
	while (c % 2 == 0)
		c = rand() % width;

	recursion(r, c, height, width);
	_cellboard[r][c].setvalue('S');

	vector<int> startPos;
	startPos.resize(2);
	startPos[0] = r;
	startPos[1] = c;

	
	// find end position
	LOOP:r = rand() % height;
	while (r % 2 == 0)
		r = rand() % height;

	c = rand() % width;
	while (c % 2 == 0)
		c = rand() % width;

	if (_cellboard[r][c].getvalue() == '0')		
		_cellboard[r][c].setvalue('G');
	else
		goto LOOP;

	vector<int> goalPos;
	goalPos.resize(2);
	goalPos[0] = r;
	goalPos[1] = c;



	Maze2d* myMaze = new Maze2d(height, width, name, _cellboard, startPos, goalPos);
	return *myMaze;

}

void myMaze2dGenerator::recursion(int r, int c, int _height, int _width)
{
	int myHeight = _height;
	int myWidth = _width;

	vector<int> directions = generateRandomDirections();

	for (int i = 0; i < 4; i++)
	{
		switch (directions[i])
		{
		case 1: // Up
			if (r - 2 <= 0)
				continue;
			if (_cellboard[r - 2][c].getvalue() != '0')
			{
				_cellboard[r - 2][c].setvalue('0');
				_cellboard[r - 1][c].setvalue('0');
				recursion(r - 2, c, myHeight, myWidth);
			}
			break;
		case 2: // Right
			if (c + 2 >= _width - 1)
				continue;
			if (_cellboard[r][c + 2].getvalue() != '0')
			{
				_cellboard[r][c + 2].setvalue('0');
				_cellboard[r][c + 1].setvalue('0');
				recursion(r, c + 2, myHeight, myWidth);
			}
			break;
		case 3: // Down
			if (r + 2 >= _height - 1)
				continue;
			if (_cellboard[r + 2][c].getvalue() != '0')
			{
				_cellboard[r + 2][c].setvalue('0');
				_cellboard[r + 1][c].setvalue('0');
				recursion(r + 2, c, myHeight, myWidth);
			}
			break;
		case 4: // Left
			if (c - 2 <= 0)
				continue;
			if (_cellboard[r][c - 2].getvalue() != '0')
			{
				_cellboard[r][c - 2].setvalue('0');
				_cellboard[r][c - 1].setvalue('0');
				recursion(r, c - 2, myHeight, myWidth);
			}
			break;
		}
	}
}

vector<int> myMaze2dGenerator::generateRandomDirections()
{
	srand(time_t(NULL));
	vector<int> directions = { 1, 2, 3, 4 };
	std::random_device rd;
	std::mt19937 g(rd());
	

	shuffle(directions.begin(), directions.end(), g);

	return directions;
}


void myMaze2dGenerator::printBoard(int x, int y) {

	char temp;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			temp = _cellboard[i][j].getvalue();
			if (temp == '1') {
				cout << " * ";
			}
			else if (temp == '0') {
				cout << "   ";
			}
			else if (temp == 'G') {
				cout << " G ";
			}
			else if (temp == 'S') {
				cout << " S ";
			}

		}
		cout << endl;
	}
}


