#include "position.h"


position::position(const position& pos) {

	_row = pos._row;
	_col = pos._col;
}

position& position::getPos() {

	return *this;
}