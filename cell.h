#pragma once

#include "position.h"

class cell {
public:

	cell() {
		_visited = false;
		_value = '1';
		_current.setpos(-1, -1);
		up.setpos(-1, -1);
		down.setpos(-1, -1);
		left.setpos(-1, -1);
		right.setpos(-1, -1);

	};

	cell(const position& pos) : _current(pos) {

		_visited = false;
		_value = '1';
		up.setpos(-1, -1);
		down.setpos(-1, -1);
		left.setpos(-1, -1);
		right.setpos(-1, -1);
	}

	cell(const cell& _cell) {

		_current = _cell._current;
		_visited = _cell._visited;
		_value = _cell._value;
		up = _cell.up;
		down = _cell.down;
		right = _cell.right;
		left = _cell.left;

	}

	cell& operator=(const cell& _cell) {
		_current = _cell._current;
		_visited = _cell._visited;
		_value = _cell._value;
		up = _cell.up;
		down = _cell.down;
		right = _cell.right;
		left = _cell.left;

		return *this;
	}

	cell& operator=(const position& pos) {
		_current = pos;
		_visited = false;
		_value = '1';
		up.setpos(-1, -1);
		down.setpos(-1, -1);
		left.setpos(-1, -1);
		right.setpos(-1, -1);

		return *this;
	}

	bool operator==(cell& _cell) {

		if (_current.getrow() == _cell._current.getrow() && _current.getcol() == _cell._current.getcol())
			return true;
		else
			return false;
	}

	position& getPosition() { return _current; }
	char getvalue() { return _value; }
	bool getvisited() { return _visited; }
	position getup() { return up.getPos(); }
	position getdown() { return down.getPos(); }
	position getright() { return right.getPos(); }
	position getleft() { return left.getPos(); }

	void setVisited(bool visit) { _visited = visit; }
	void setvalue(const char v) { _value = v; }

	void setup(int row, int col) { up.setpos(row, col) ; }
	void setdown(int row, int col) { down.setpos(row, col); }
	void setright(int row, int col) { right.setpos(row, col); }
	void setleft(int row, int col) { left.setpos(row, col); }

private:
	position _current;
	bool _visited;			// cell visited
	char _value;			// cell content
	position up;
	position down;
	position right;
	position left;

};
