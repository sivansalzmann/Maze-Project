#pragma once

#include <string>
#include <memory>

using namespace std;

template<class U>	// U = cell
class State
{
public:
	
	State<U>() : m_cameFrom(nullptr) {}
	State<U>(U mystate) : m_state(mystate), m_cameFrom(nullptr) {}
	State<U>(const State<U>& state) {
		m_cameFrom = nullptr;
		m_state = state.m_state;
	}
	~State() {
		// free dynamic memory
		delete m_cameFrom;
	};

	
	virtual void setCamefrom(State<U>& cameFrom) = 0;
	void setCurrentState(const U& state) { m_state = state; }

	virtual U& getCurrentState() { return m_state; }
	State<U>* getCameFrom() const{ return m_cameFrom; }
	virtual double getgCost() const = 0;
	virtual double getfCost() const = 0;
	
	bool operator==(State<U>& s) { return m_state == s.m_state; }		// U has operator ==
	virtual State<U>& operator=(State<U>& s) = 0;						// U has operator =
	virtual bool operator>(State<U>& s) = 0;
	bool operator()(State<U>& first, State<U>& second)
	{
		return first.getfCost() > second.getfCost();
	}

protected:
	U m_state;
	State<U>* m_cameFrom;
};

