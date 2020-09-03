
#include "simpleMaze2dGenerator.h"

simpleMaze2dGenerator::simpleMaze2dGenerator() {

	position initial(-1, -1);
	cell init(initial);
	vector<cell> t = { init };

	_cellboard.push_back(t);
}

void simpleMaze2dGenerator::fromintToCell(size_t height, size_t width, position start, position goal) {

	cell mycell;

	_cellboard.resize(height, vector<cell>(width));

	for (size_t row = 0; row < height; row++) {


		for (size_t col = 0; col < width; col++) {

			position myposition(row, col);
			mycell = myposition;

			if (myposition.getrow() == start.getrow() && myposition.getcol() == start.getcol())
			{
				mycell.setvalue('S');
				mycell.setVisited(true);
			}

			if (myposition.getrow() == goal.getrow() && myposition.getcol() == goal.getcol())
			{
				mycell.setvalue('G');
			}

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



Maze2d& simpleMaze2dGenerator::generate(size_t height, size_t width, string name) {


	_cellboard.clear();


	srand(time_t(NULL));
	int randomstart = rand() % 4;
	int randomgoal = rand() % 2;

	position pos1(0,0);
	position pos2( height - 1, width - 1 );
	position pos3( height - 1, 0 );
	position pos4( 0, width - 1 );

	vector<position> chooserandStart;
	vector<position> chooserandGoal;
	chooserandStart.push_back(pos1);
	chooserandStart.push_back(pos2);
	chooserandStart.push_back(pos3);
	chooserandStart.push_back(pos4);

	position start(chooserandStart[randomstart]);

	if (start == pos1) {
		chooserandGoal.push_back(pos3);
		chooserandGoal.push_back(pos4);
	}
	else if (start == pos2) {
		chooserandGoal.push_back(pos3);
		chooserandGoal.push_back(pos4);
	}
	else if (start == pos3) {
		chooserandGoal.push_back(pos1);
		chooserandGoal.push_back(pos2);
	}
	else if (start == pos4) {
		chooserandGoal.push_back(pos1);
		chooserandGoal.push_back(pos2);
	}

	position goal(chooserandGoal[randomgoal]);



	fromintToCell(height, width, start, goal);


	vector<int> mystart;
	mystart.resize(2);
	vector<int>  myend;
	myend.resize(2);
	for (size_t row = 0; row < height; row++) {

		for (size_t col = 0; col < width; col++) {			// find start cell

			if (_cellboard[row][col].getvalue() == 'S') {
				mystart[0] = row;
				mystart[1] = col;
			}
				
		}
	}

	for (size_t row = 0; row < height; row++) {

		for (size_t col = 0; col < width; col++) {		//find goal cell

			if (_cellboard[row][col].getvalue() == 'G') {

				myend[0] = row;
				myend[1] = col;
			}
				
		}
	}


	/////////////////////////// make path between S to G ///////////////////////////// 

	size_t row = mystart[0];
	size_t col = mystart[1];
	while (_cellboard[row][col].getvalue() != 'G') {

				int rowDown = _cellboard[row][col].getdown().getrow();
				int colDown = _cellboard[row][col].getdown().getcol();

				int rowUp = _cellboard[row][col].getup().getrow();
				int colUp = _cellboard[row][col].getup().getcol();

				int rowRight = _cellboard[row][col].getright().getrow();
				int colRight = _cellboard[row][col].getright().getcol();

				int rowLeft = _cellboard[row][col].getleft().getrow();
				int colLeft = _cellboard[row][col].getleft().getcol();


				if (row < height && rowDown != -1 && colDown != -1 && _cellboard[rowDown][colDown].getvisited() == false && myend[0] >= rowDown) {

					if ( _cellboard[rowDown][colDown].getvalue() != 'G') {
						_cellboard[rowDown][colDown].setvalue('0');
						_cellboard[rowDown][colDown].setVisited(true);
						row++;
					}
					else if (_cellboard[rowDown][colDown].getvalue() == 'G') {
						_cellboard[rowDown][colDown].setVisited(true);
						row++;
					}
				}

				else if (row > 0 && rowUp != -1 && colUp != -1 && _cellboard[rowUp][colUp].getvisited() == false && myend[0] <= rowUp) {

					if (_cellboard[rowUp][colUp].getvalue() != 'G') {
						_cellboard[rowUp][colUp].setvalue('0');
						_cellboard[rowUp][colUp].setVisited(true);
						row--;
					}
					else if (_cellboard[rowUp][colUp].getvalue() == 'G') {
						_cellboard[rowUp][colUp].setVisited(true);
						row--;
					}
				}

				if (col < width &&  rowRight != -1 && colRight != -1 && _cellboard[rowRight][colRight].getvisited() == false && myend[1] >= colRight) {

					if (_cellboard[rowRight][colRight].getvalue() != 'G') {
						_cellboard[rowRight][colRight].setvalue('0');
						_cellboard[rowRight][colRight].setVisited(true);
						col++;
					}
					else if (_cellboard[rowRight][colRight].getvalue() == 'G') {
						_cellboard[rowRight][colRight].setVisited(true);
						col++;
					}
				}

				else if (col > 0 && rowLeft != -1 && colLeft != -1 && _cellboard[rowLeft][colLeft].getvisited() == false && myend[1] <= colLeft) {

					if ( _cellboard[rowLeft][colLeft].getvalue() != 'G') {
						_cellboard[rowLeft][colLeft].setvalue('0');
						_cellboard[rowLeft][colLeft].setVisited(true);
						col--;
					}
					else if (_cellboard[rowLeft][colLeft].getvalue() == 'G') {
						_cellboard[rowLeft][colLeft].setVisited(true);
						col--;
					}
				}
	}


	Maze2d* myMaze = new Maze2d(height, width, name, _cellboard, mystart, myend);
	return *myMaze;

}



void simpleMaze2dGenerator::printBoard(size_t x, size_t y) {

	char temp;
	for (size_t i = 0; i < x; i++) {
		for (size_t j = 0; j < y; j++) {
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