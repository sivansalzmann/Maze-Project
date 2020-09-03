#pragma once

#include <vector>
#include <iostream>


using namespace std;

class position {
public:
	position() { _row = _col = -1; }
	position(const position& pos);
	position(int row, int col) {

		_row = row;
		_col = col;

	}
	bool operator==(position& pos) {

		if (_row == pos._row && _col == pos._col)
			return true;
		else
			return false;
	}
	friend ostream& operator<<(ostream& os, const position& pos) {
		os << "{" << pos._row << "," << pos._col << "}" << endl;
		return os;
	}
	position& getPos();
	int getrow() { return _row; }
	int getcol() { return _col; }
	void setposition(const position& pos) {

		_row = pos._row;
		_col = pos._col;
	}
	void setpos(int row, int col) {

		_row = row;
		_col = col;
	}

private:
	int _row;
	int _col;
};
