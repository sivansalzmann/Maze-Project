#pragma once 
#include "State.h"
#include "cell.h"



class mazeState : public State<cell>
{	public:
	mazeState() : State<cell>(), g_cost(0), h_cost(0), f_cost(0), visited(false) {}
	mazeState(cell mystate) : State<cell>(mystate) {
		g_cost = 0;
		h_cost = 0;
		f_cost = 0;
		visited = false;
	}

	mazeState(const mazeState& state) {
		m_state = state.m_state;
		if (state.getCameFrom() != nullptr)
			m_cameFrom = new mazeState(state.getCameFrom()->getCurrentState());
		else
			m_cameFrom = nullptr;
		g_cost = state.g_cost;
		h_cost = state.h_cost;
		f_cost = state.f_cost;
		visited = state.visited;
	}

	mazeState& operator=(mazeState& state) {

		m_state = state.getCurrentState();
		if (state.getCameFrom() != nullptr)
			m_cameFrom = new mazeState(state.getCameFrom()->getCurrentState());
		else
			m_cameFrom = nullptr;
		g_cost = state.g_cost;
		h_cost = state.h_cost;
		f_cost = state.f_cost;
		visited = state.visited;
		return *this;
	}

	void calculategCosts(const double stepCost, const mazeState* fromState); // calculate g cost

	virtual double getgCost() const { return g_cost; }	
	double gethCost() const { return h_cost; }
	bool getVisited() const { return visited; }
	virtual double getfCost() const { return f_cost; }

	void sethCost(const double cost) { h_cost = cost; }
	void setVisited(const bool V) { visited = V; }
	void setfCost() { f_cost = g_cost + h_cost; }


	virtual State<cell>& operator=(State<cell>& s) {

		m_state = s.getCurrentState();
		if (s.getCameFrom() != nullptr)
			m_cameFrom = s.getCameFrom();		// Camefrom's current State
		else
			m_cameFrom = nullptr;
		return *this;
	}

	virtual bool operator>(State<cell>& s) {
		if (f_cost > s.getfCost())
			return true;
		else
			return false;
	}

	virtual void setCamefrom(State<cell>& cameFrom) { m_cameFrom = new mazeState(cameFrom.getCurrentState());
	}
	
private:
	double g_cost;	
	double h_cost;
	double f_cost;
	bool visited;
};

