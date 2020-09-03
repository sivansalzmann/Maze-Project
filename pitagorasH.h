#pragma once
#include <math.h>  

#include "Heuristic.h"
#include "mazeState.h"

class pitagorasH : public Heuristic<mazeState> {
public:
	virtual double calculateH(mazeState& current, mazeState& Goal, const double StepCost);
};
