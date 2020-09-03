#pragma once

#include <stack>
#include <functional>
#include <algorithm> 

#include "CommonSearcher.h"
#include "Heuristic.h"
#include "Solution.h"
#include "mazeState.h"


template<class U>
class AStar : public CommonSearcher<mazeState,cell> {			// U =cell, T = mazeState
public:
	AStar(Heuristic<mazeState>* heuristic) : m_h(heuristic) {
	
		m_evaluatedNodes = 0;

	}
	~AStar() { delete m_h; }									// delete dynamic memory
	virtual Solution<U>* search(Searchable<mazeState, cell>& s) {

		mazeState m_current(s.getStartState());
		m_current.calculategCosts(s.getcost(), nullptr);									// calculate g
		m_current.sethCost(m_h->calculateH(m_current, s.getGoalState(), s.getcost()));		// calculate h
		m_current.setfCost();																//calculate f

		vector<mazeState> myList;								// all nodes with g and h calculation
		vector<cell> myResult;									// only solution nodes

		vector<mazeState> closedList;							// all nodes evaluated 

		m_openList.emplace(m_current);							// all nodes evaluated from start to solution

		myList.push_back(m_current);							// initialize myList with start state
		myList.begin()->setVisited(true);

		while (!m_openList.empty()) {

			m_current = topOpenList();

			closedList.push_back(m_current);					// save in closedList all nodes evaluated

			if (m_current == s.getGoalState())				    // if State == GoalState
				break;

			removeFromQueue();

			vector<mazeState> moves = s.getAllPossibleStates(m_current.getCurrentState());
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
				it->sethCost(m_h->calculateH(*it, s.getGoalState(), s.getcost()));	// calculate h
				it->setfCost();														// calculate f

				myList.push_back(*it);		
				lable:
				it++;
			}

				
				// between nodes evaluated choose lowest F function	
				mazeState m_check(m_current);
				for (auto begin = myList.begin(); begin != myList.end(); begin++) {			//initialize m_current to first node where visit == false
				
					if (begin->getVisited() == false) {
						m_current = *begin;
						break;
					}
						
				}

				// if m_current stays the same as befor for's initialize 
				if (m_current == m_check)													// there is no path in maze
					throw "No path from S to G";


				for (auto begin = myList.begin(); begin != myList.end(); begin++) {			// between node that there bisit == false, choose smallest f val

					if (begin->getVisited() == false && m_current.getfCost() > begin->getfCost()) {
						m_current = *begin;
					}
				}

				for (auto begin = myList.begin(); begin != myList.end(); begin++) {			// set m_current's visited in 'myList' to true

					if (*begin == m_current) {
						begin->setVisited(true);
						m_current.setVisited(true);
					}
				}

				m_openList.emplace(m_current);

			}


			// from solution to beginState all nodes evaluated that create solution
			mazeState temp;
			s.getStartState();
			s.getGoalState();
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

	virtual int getNumberOfNodesEvaluated() const { return m_evaluatedNodes; }

	virtual queue<mazeState>& getQueue() { return m_openList; }
	virtual void removeFromQueue() {
		m_openList.pop();
	}
	virtual mazeState& topOpenList() {
		m_evaluatedNodes++;
		return m_openList.front();
	}


	
private:
	Heuristic<mazeState>* m_h;
	int m_evaluatedNodes;
	queue<mazeState> m_openList;

};
