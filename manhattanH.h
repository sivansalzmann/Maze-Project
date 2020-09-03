#pragma once

#include "Heuristic.h"
#include "mazeState.h"

class manhattanH : public Heuristic<mazeState> {
public:
	virtual double calculateH(mazeState& current, mazeState& Goal, const double StepCost);
};
