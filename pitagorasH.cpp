#include "pitagorasH.h"

double pitagorasH::calculateH(mazeState& current, mazeState& Goal, const double StepCost) {

	cell m_goal(Goal.getCurrentState());
	
	int GoalRow = m_goal.getPosition().getrow();
	int GoalCOl = m_goal.getPosition().getcol();

	cell m_current(current.getCurrentState());
	
	int CurrentRow = m_current.getPosition().getrow();
	int CurrentCol = m_current.getPosition().getcol();

	double resultRow = pow(GoalRow - CurrentRow, 2);
	double resultCol = pow(GoalCOl - CurrentCol, 2);


	double result = sqrt(resultRow + resultCol) * StepCost; // h 

	return result;
}