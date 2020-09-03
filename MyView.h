#pragma once
#include <stdio.h>
#include <iostream>
#include "Maze2d.h"

using namespace std;
class MyView {
public:
	void printBoard(ostream& out, Maze2d& _maze);
	void printNotifications(ostream& out, string str);
	void printSoultions(ostream& out, Solution<cell>& s);
	void printWarnings(ostream& out, const char* str);
};