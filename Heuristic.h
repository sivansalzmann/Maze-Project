#pragma once

#include "State.h"
#include "mazeState.h"

template<class T>
class Heuristic {		// T = mazeState
public:
	Heuristic() = default;
	~Heuristic() = default;
	virtual double calculateH(T& current, T& Goal, const double StepCost) = 0;	// h cost
};
