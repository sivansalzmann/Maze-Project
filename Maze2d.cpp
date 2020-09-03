#include "Maze2d.h"

Maze2d::Maze2d(size_t rows, size_t colums, string name, vector<vector<cell>> maze, vector<int> start, vector<int> goal) : Maze() {

	_maze.resize(rows, vector<cell>(colums));

	for (size_t row = 0; row < maze.size(); row++) {


		for (size_t col = 0; col < maze[row].size(); col++) {

			_maze[row][col] = maze[row][col];
		}
	}

	height = rows;
	width = colums;
	_name = name;
	_m_start.setpos(start[0], start[1]);
	_m_goal.setpos(goal[0], goal[1]);
	mysolution = nullptr;
}

Maze2d::Maze2d(const Maze2d& maze) : Maze(){

	height = maze.height;
	width = maze.width;

	_name = maze._name;
	_m_start.setposition(maze._m_start);
	_m_goal.setposition(maze._m_goal);

	_maze = maze._maze;

	if (maze.mysolution != nullptr)
		mysolution = new Solution<cell>(*maze.mysolution);
	else
		mysolution = nullptr;
}

Maze2d& Maze2d::operator=(const Maze2d& maze) {

	_maze.resize(maze.height, vector<cell>(maze.width));

	for (size_t row = 0; row < maze.height; row++) {


		for (size_t col = 0; col < maze.width; col++) {

			_maze[row][col] = maze._maze[row][col];
		}
	}

	height = maze.height;
	width = maze.width;
	_name = maze._name;
	_m_start.setposition(maze._m_start);
	_m_goal.setposition(maze._m_goal);

	if (maze.mysolution != nullptr)
		mysolution = new Solution<cell>(*maze.mysolution);
	else
		mysolution = nullptr;

	return *this;
}

vector<string> Maze2d::getPossibleMoves(position& myCurrentPos) {

	vector<string> result;
	//result.resize(4);
	
	int row = myCurrentPos.getrow();
	int col = myCurrentPos.getcol();

	if (_maze[row][col].getup().getrow() != -1 && _maze[row][col].getup().getcol() != -1) {

		int r = _maze[row][col].getup().getrow();
		int c = _maze[row][col].getup().getcol();

		if (_maze[r][c].getvalue() == '0') {
			string temp;
			temp = "up";
			result.push_back(temp);
		}
	}

	if (_maze[row][col].getdown().getrow() != -1 && _maze[row][col].getdown().getcol() != -1) {

		int r = _maze[row][col].getdown().getrow();
		int c = _maze[row][col].getdown().getcol();

		if (_maze[r][c].getvalue() == '0') {
			string temp;
			temp = "down";
			result.push_back(temp);
		}
	}

	if (_maze[row][col].getright().getrow() != -1 && _maze[row][col].getright().getcol() != -1) {

		int r = _maze[row][col].getright().getrow();
		int c = _maze[row][col].getright().getcol();

		if (_maze[r][c].getvalue() == '0') {
			string temp;
			temp = "right";
			result.push_back(temp);
		}
	}

	if (_maze[row][col].getleft().getrow() != -1 && _maze[row][col].getleft().getcol() != -1) {

		int r = _maze[row][col].getleft().getrow();
		int c = _maze[row][col].getleft().getcol();

		if (_maze[r][c].getvalue() == '0') {
			string temp;
			temp = "left";
			result.push_back(temp);
		}
	}

	return result;
}

Maze2d::Maze2d(vector<int> _data) : Maze() {
	mysolution = nullptr;

	_m_start.setpos(_data[0], _data[1]);
	_m_goal.setpos(_data[2], _data[3]);
	height = _data[4];
	width = _data[5];

	size_t len = 0;
	size_t i = 0, j = 0, k = 6;				// from k the maze board begin
	size_t one = 0, zero = 0;
	size_t makeSolution = 0;
	
	_maze.resize(height);
	for (i = 0; i < height; i++) {
		_maze[i].resize(width);
		for (j = 0; j < width; j++) {
			_maze[i][j].setvalue('1');
		}
	}

	
	vector<int> toBoard;
	
	for (k; k < _data.size(); k++) {
		if (_data[k] == -1) {					// value of 'S' or 'G'
			toBoard.push_back(-1);
		}

		else if (_data[k] == 1) {
			k++;
			if (k < _data.size())
				one = _data[k];					// how many times 1 shows
			else
				throw "wrong way of saving data";
			while (k < _data.size() && one > 0) {
				toBoard.push_back(1);
				one--;							// until one = 0;
			}
		}

		else if (_data[k] == 0) {
			k++;
			if (k < _data.size())
				zero = _data[k];				// how many times 0 shows
			else
				throw "wrong way of saving data";
			while (k < _data.size() && zero > 0) {
				toBoard.push_back(0);
				zero--;							// until zero = 0;
			}
		}


		else if (_data[k] == -7) {}				// maze doest have solution -- // do nothing		
		else if (_data[k] == -2) {
			toBoard.push_back(-2);				// a sign to know -- from here the solution starts
			k++;
			while (k < _data.size()) {
				toBoard.push_back(_data[k]);	// copy solution
				k++;
			}
		}

	}


	for (i = 0; i < height; i++) {				// initialize maze
		for (j = 0; j < width ; j++) {

			if (len < toBoard.size())
			{
				if (toBoard[len] == -1){}		// vale = S or value = G -- do nothing
												

				else if (toBoard[len] == 1)
					_maze[i][j].setvalue('1');

				else if(toBoard[len] == 0)
					_maze[i][j].setvalue('0');

					len++;
				
			}
			makeSolution = len;					// for solution update
		}
	}

	_maze[_data[0]][_data[1]].setvalue('S');
	_maze[_data[2]][_data[3]].setvalue('G');


	// copy solution from file
	vector<cell> mynewVec;
	while (makeSolution < toBoard.size()) {

		if (toBoard[makeSolution] == -2) {
			makeSolution += 1;
			while (makeSolution < toBoard.size()) {
			
				// x					// y
				position mynewPos(toBoard[makeSolution], toBoard[makeSolution + 1]);
				cell mymewCell(mynewPos);

				mynewVec.push_back(mymewCell);
				makeSolution += 2;
			}
		}
		else
			makeSolution++;
	}

	if (mynewVec.size() != 0) {
		Solution<cell> mynewsolution(mynewVec);
		mysolution = new Solution<cell>(mynewsolution);
	}

}

vector<int> Maze2d::getData() {
	vector<int> data;

	data.push_back(_m_start.getrow());			// [1] -- start position row
	data.push_back(_m_start.getcol());			// [2] -- start position col
	data.push_back(_m_goal.getrow());			// [3] -- goal position row
	data.push_back(_m_goal.getcol());			// [4] -- goal position col
	data.push_back(height);						// [5] -- maze rows
	data.push_back(width);						// [6] -- maze colums


	int countzero = 0, countone = 0;

	vector <char> Vector1d;

	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			Vector1d.push_back(_maze[i][j].getvalue());
		}
	}

	// maze solution
	vector<int> theSolution;				// holds solution , if maze has solution
	if (mysolution == nullptr)
		Vector1d.push_back('N');			// there is no solution to this maze yet!!
	else {
		Vector1d.push_back('Y');			// there is a solution for this maze!!

		
		Solution<cell> mazeSolution(*mysolution);
		for (auto begin = mazeSolution.getSolution().begin(); begin != mazeSolution.getSolution().end(); begin ++) {

			theSolution.push_back(begin._Ptr->getPosition().getrow());		// row
			theSolution.push_back(begin._Ptr->getPosition().getcol());		// col
		}
	}
		

	for (size_t i = 0; i < Vector1d.size();) {
		if (Vector1d[i] == 'S') {
		data.push_back(-1);
		i++;
		}
		else if (Vector1d[i] == 'G') {
			data.push_back(-1);
			i++;
		}
		else if (Vector1d[i] == '0') {
			data.push_back(0);
			while (i < Vector1d.size() && Vector1d[i] == '0') {
				countzero++;
				i++;
			}
			data.push_back(countzero);
			countzero = 0;
		}
		else if (Vector1d[i] == '1') {
			data.push_back(1);
			while (i < Vector1d.size() && Vector1d[i] == '1') {
				countone++;
				i++;
			}
			data.push_back(countone);
			countone = 0;
		}
		else if (Vector1d[i] == 'N') {					// there is no solution to this maze yet!! -- do nothing
			data.push_back(-7);							// -7 = sign to know there is no solution
			i++;
		}		
		else if (Vector1d[i] == 'Y') {					// there is a solution for this maze!!
			size_t now = 0 ;
			data.push_back(-2);							// -2 = sign to know there is a solution
			while (now < theSolution.size()) {
				data.push_back(theSolution[now]);		// put solution
				now++;
			}
			i++;
		}

	}// end for

	return data;
}

bool Maze2d::operator==(Maze2d& maze) {

		// name					// height				// width				// goal position			// start position
	if (_name == maze._name && height == maze.height && width == maze.width && _m_goal == maze._m_goal && _m_start == maze._m_start) {
			// solution
		if (*mysolution == *maze.getmySolution()) {
				// boards
			if (boardEqual(maze.getBoard()))
				return true;
		}
	}

	return false;
}

bool Maze2d::boardEqual(vector<vector<cell>>& board) {		

	int count = 0;
	int size = height * width;

	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {

			if (_maze[i][j] == board[i][j])
				count++;
		}
	}

	if (count == size)
		return true;
	else
		return false;
}