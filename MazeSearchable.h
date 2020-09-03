#pragma once
#define STEP 1

#include <memory>

#include "mazeState.h"
#include "Maze2d.h"
#include "State.h"
#include "mazeState.h"
#include "Searchable.h"

class MazeSearchable : public Searchable<mazeState,cell>{
public:
	MazeSearchable(Maze2d& maze) : m_maze(&maze), cost(STEP) {
		_start = new mazeState(m_maze->getStartCell());
		_end = new mazeState(m_maze->getGoalCell());
	}
	~MazeSearchable() {
		// free dynamic memory
		delete _start;
		delete _end;
	}

	virtual mazeState& getStartState() const { return *_start; }
	virtual mazeState& getGoalState() const { return *_end; }
	virtual vector<mazeState> getAllPossibleStates(const cell& myCurrentPos);
	virtual double getcost() const { return cost; }	// step cost
	virtual Maze2d getMaze() const { return *m_maze; }

	virtual void setSolution(Solution<cell>* solution) {
		m_maze->setMazeSolution(solution);
	}
	

private:
	mazeState* _start;
	mazeState* _end;
	Maze2d* m_maze;
	double cost;	// step cost
};