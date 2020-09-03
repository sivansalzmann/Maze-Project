#include "manhattanH.h"

double manhattanH::calculateH(mazeState& current, mazeState& Goal, const double StepCost) {

	cell m_goal(Goal.getCurrentState());

	int GoalRow = m_goal.getPosition().getrow();
	int GoalCOl = m_goal.getPosition().getcol();

	cell m_current(current.getCurrentState());

	int CurrentRow = m_current.getPosition().getrow();
	int CurrentCol = m_current.getPosition().getcol();

	int resultRow = (GoalRow - CurrentRow);

	if (resultRow < 0)
		resultRow = resultRow *  (-1);

	int resultCol = (GoalCOl - CurrentCol);

	if (resultCol < 0)
		resultCol = resultCol * (-1);

	double result = (double)((resultRow + resultCol) * StepCost); // h = (row + col) * stepCost
	return result;	
}