#pragma once

#include <stack>
#include <functional>
#include <algorithm> 

#include "CommonSearcher.h"
#include "Solution.h"
#include "mazeState.h"

template<class U>
class BFS : public CommonSearcher<mazeState, cell> {		// U =cell, T = mazeState
public:
	BFS(): m_evaluatedNodes(0){}

	virtual int getNumberOfNodesEvaluated() const { return m_evaluatedNodes; };

	virtual queue<mazeState>& getQueue() { return m_openList; }
	virtual void removeFromQueue() {
		m_openList.pop();
	}
	virtual mazeState& topOpenList() {
		m_evaluatedNodes++;
		return m_openList.front();
	}

	virtual Solution<U>* search(Searchable<mazeState, cell>& s) {
		
		mazeState m_current(s.getStartState());
		m_current.setVisited(true);
		m_current.calculategCosts(s.getcost(), nullptr);

		vector<mazeState> closedList;				// all nodes evaluated 
		vector<cell> myResult;						// only solution nodes

		vector<mazeState> myList;					// holds all nodes that has been visited
		myList.push_back(m_current);

		m_openList.push(m_current);

		while (!m_openList.empty()) {				// while queue is not empty

			m_current = m_openList.front();
			closedList.push_back(m_current);		// save all evaluated nodes

			m_openList.pop();						
			m_evaluatedNodes++;

			if (m_current == s.getGoalState())		// if State == GoalState
				break;

			vector<mazeState> moves = s.getAllPossibleStates(m_current.getCurrentState());		// all node childs
			auto it = moves.begin();
			auto end = moves.end();

			// for each neighbor calculate f
			while (it != end) {
				auto start = myList.begin();
				while (start != myList.end()) {
					if (it->getCurrentState() == start->getCurrentState())
						goto lable;
					else
						start++;
				}

				it->setCamefrom(m_current);
				it->calculategCosts(s.getcost(), new mazeState(m_current));			// calculate g
				it->setfCost();														// calculate f
				it->setVisited(true);

				myList.push_back(*it);												// add node to visited nodes list
				m_openList.push(*it);												// add nodes to queue
			lable:
				it++;
			}
		}


		// from solution to beginState all nodes evaluated that create solution
		mazeState temp;
		
		for (auto start = closedList.begin(); start != closedList.end(); start++) {

			if (*start == s.getGoalState()) {
				temp = *start;
			}
		}

		myResult.push_back(temp.getCurrentState());

	Floop:
		for (auto start = closedList.begin(); start != closedList.end(); start++) {

			if (*start == *temp.getCameFrom()) {

				temp = *start;
				myResult.push_back(temp.getCurrentState());
				break;
			}

		}

		if (temp == s.getStartState()) {
			//reverse for answer -- myResult;
		}
		else {
			goto Floop;
		}


		std::reverse(myResult.begin(), myResult.end());
		Solution<cell> result(myResult);
		Solution<cell>* myresult = new Solution<cell>(myResult);

		s.setSolution(myresult);				// update maze2d solution 

		return myresult;
	}

private:
	int m_evaluatedNodes;
	queue<mazeState> m_openList;
};


