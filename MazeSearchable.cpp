#include "MazeSearchable.h"

vector<mazeState> MazeSearchable::getAllPossibleStates(const cell& myCurrentPos) {

	cell myCell(myCurrentPos);					// current Cell
	int row = myCell.getPosition().getrow();
	int col = myCell.getPosition().getcol();

	
	vector<mazeState> result;					//function return
	
	// downMove
	if (m_maze->getBoard()[row][col].getdown().getrow() != -1 && m_maze->getBoard()[row][col].getdown().getcol() != -1 && m_maze->getBoard()[m_maze->getBoard()[row][col].getdown().getrow()][m_maze->getBoard()[row][col].getdown().getcol()].getvalue() != '1') {

		cell possibleMoveCell = cell(m_maze->getBoard()[m_maze->getBoard()[row][col].getdown().getrow()][m_maze->getBoard()[row][col].getdown().getcol()]);
		mazeState possibleMoveState(possibleMoveCell);
		result.push_back(possibleMoveState);
	}
	// upMove
	if (m_maze->getBoard()[row][col].getup().getrow() != -1 && m_maze->getBoard()[row][col].getup().getcol() != -1 && m_maze->getBoard()[m_maze->getBoard()[row][col].getup().getrow()][m_maze->getBoard()[row][col].getup().getcol()].getvalue() != '1') {

		cell possibleMoveCell = cell(m_maze->getBoard()[m_maze->getBoard()[row][col].getup().getrow()][m_maze->getBoard()[row][col].getup().getcol()]);
		mazeState possibleMoveState(possibleMoveCell);
		result.push_back(possibleMoveState);
	}
	// rightMove
	if (m_maze->getBoard()[row][col].getright().getrow() != -1 && m_maze->getBoard()[row][col].getright().getcol() != -1 && m_maze->getBoard()[m_maze->getBoard()[row][col].getright().getrow()][m_maze->getBoard()[row][col].getright().getcol()].getvalue() != '1') {

		cell possibleMoveCell = cell(m_maze->getBoard()[m_maze->getBoard()[row][col].getright().getrow()][m_maze->getBoard()[row][col].getright().getcol()]);
		mazeState possibleMoveState(possibleMoveCell);
		result.push_back(possibleMoveState);
	}
	// leftMove
	if (m_maze->getBoard()[row][col].getleft().getrow() != -1 && m_maze->getBoard()[row][col].getleft().getcol() != -1 && m_maze->getBoard()[m_maze->getBoard()[row][col].getleft().getrow()][m_maze->getBoard()[row][col].getleft().getcol()].getvalue() != '1') {

		cell possibleMoveCell = cell(m_maze->getBoard()[m_maze->getBoard()[row][col].getleft().getrow()][m_maze->getBoard()[row][col].getleft().getcol()]);
		mazeState possibleMoveState(possibleMoveCell);
		result.push_back(possibleMoveState);
	}
	return result;
}