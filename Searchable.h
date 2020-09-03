#pragma once

#include <vector>
#include "State.h"


template <class T, class U>			// T = mazeState, U = cell
class Searchable
{
public:
	virtual T& getStartState() const = 0;
	virtual T& getGoalState() const = 0;
	virtual vector<T> getAllPossibleStates(const U& myCurrentPos) = 0;
	virtual double getcost() const = 0;	// step cost

	virtual void setSolution(Solution<U>* solution) = 0;
};