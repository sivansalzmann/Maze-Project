#pragma once

#include <stdio.h>      
#include <iostream>     

#include "myController.h"
#include "MyModel.h"
#include "Demo.h"

class CLIview {
public:
	CLIview(ostream& out, istream& in, myController& control) : /*mycontrol(new myController),*/ _out(out), _in(in) {}
	//~CLIview() { delete mycontrol; }

	ostream& getOut() { return _out; }
	istream& getin() { return _in; }

	void startLine(){ _out << "welcome to our MAZE GAME" << endl; }
	int start() {
	
		_out << "please choose one of the options in our menu : " << endl;
		_out << endl;
		menu();

		int choosen;
		_in >> choosen;

		return choosen;

	}

	string mypath() {
		string tmp;
		_in >> tmp;
		return tmp;
	}

	string name() {
		string MazeName;
		_in >> MazeName;
		return MazeName;
	}

	int Myrow() {
		int myrow;
		_in >> myrow;
		return myrow;
	}

	int Mycol() {
		int mycol;
		_in >> mycol;
		return mycol;
	}

	int myAlgor() {
		int myAl;
		_in >> myAl;
		return myAl;
	}

	string Filename() {
		string FName;
		_in >> FName;
		return FName;
	}

	void menu() {
		_out << "1  : " << "Show all files that are located in a specipic path" << endl;
		_out << "2  : " << "Create maze " << endl;
		_out << "3  : " << "Display maze " << endl;
		_out << "4  : " << "Save maze" << endl;
		_out << "5  : " << "Load maze " << endl;
		_out << "6  : " << "Display maze size in memory" << endl;
		_out << "7  : " << "Display file size" << endl;
		_out << "8  : " << "Solve maze" << endl;
		_out << "9  : " << "Display maze solution " << endl;
		_out << "10 : " << "Exit" << endl;
		_out << "11 : " << "Run Demo check" << endl;
		_out << "12 : " << "Run TestMazeGenerator" << endl;
	}

private:
	istream& _in;
	ostream& _out;

	//myController* mycontrol;
};