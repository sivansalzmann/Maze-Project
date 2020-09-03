#pragma once

#include "CLIview.h"
#include "MyView.h"

class View {

public:
	View() : _myview(nullptr), _printView(nullptr){}

	void Vinitialize(ostream& out, istream& in, myController* control) {

		_myview = new CLIview(out, in, *control);
	}
	void Line() { _myview->startLine(); }
	int start() {
		int temp = 0;
		temp = _myview->start();
		return temp;
	}

	CLIview* getCLIview() { return _myview; }
	MyView* getprintView() { return _printView; }

	

private:
	CLIview* _myview;
	MyView* _printView;

};