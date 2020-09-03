#include "mazeState.h"


void mazeState::calculategCosts(const double stepCost, const mazeState* fromState) {

	if (fromState == nullptr)
		g_cost = 0;
	else
		g_cost = fromState->getgCost() + stepCost;

}