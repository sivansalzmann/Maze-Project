#pragma once

#include <string>
#include <iostream>

//#include "Maze.h"
#include "cell.h"
#include "Maze.h"
#include "Solution.h"

class Maze2d : public Maze{
public:
	Maze2d(size_t rows, size_t colums, string name, vector<vector<cell>> maze, vector<int> start, vector<int> goal);
	Maze2d(const Maze2d& maze);
	Maze2d(vector<int> _data);
	Maze2d() : height(0), width(0), mysolution(nullptr) {}
	
	 virtual vector<string> getPossibleMoves(position& myCurrentPos);
	 virtual position getGoalPosition() { return _m_goal; }
	 virtual position getStartPosition() { return _m_start; }
	 cell getStartCell() { return _maze[_m_start.getrow()][_m_start.getcol()]; }
	 cell getGoalCell() { return _maze[_m_goal.getrow()][_m_goal.getcol()]; }
	 virtual vector<vector<cell>>& getBoard() { return _maze; }
	 vector<int> getData();
	 Solution<cell>* getmySolution() { return mysolution; }
	 size_t getHeight() const { return height; }
	 size_t getWidth() const { return width; }

	 void setMazeSolution(Solution<cell>* solution) {					// set maze solution
		 mysolution = new Solution<cell>(*solution);
	 }	

	 void printSolution() {
		 if (mysolution != nullptr) { cout << *mysolution; }
	 }

	 bool boardEqual(vector<vector<cell>>& board);						// check if boards are equal
	 bool operator==(Maze2d& maze);										// checl if two mazes are the same
	 Maze2d& operator=(const Maze2d& maze);
	friend ostream& operator<<(ostream& out, Maze2d& maze) {

		char temp;
		for (size_t i = 0; i < maze.height; i++) {
			for (size_t j = 0; j < maze.width; j++) {
				temp = maze._maze[i][j].getvalue();
				if (temp == '1') {
					out << " * ";
				}
				else if (temp == '0') {
					out << "   ";
				}
				else if (temp == 'G') {
					out << " G ";
				}
				else if (temp == 'S') {
					out << " S ";
				}

			}
			out << endl;
		}

		if (maze.getmySolution() != nullptr) {
			out << "maze solution :" << endl;
			out << *maze.getmySolution();
		}


		return out;
	}

private:
	vector<vector<cell>> _maze;
	size_t height;						//	rows
	size_t width;						// colums
	position _m_goal;
	position _m_start;
	string _name;
	Solution<cell>* mysolution;
};