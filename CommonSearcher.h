#pragma once
#include "Searcher.h"
#include <queue>
#include "State.h"

template <class T, class U>
class CommonSearcher : public Searcher<T,U>		// U =cell, T = mazeState
{
public:
	CommonSearcher() = default;

	virtual Solution<U>* search(Searchable<T,U>& s) = 0;
	virtual int getNumberOfNodesEvaluated() const = 0;

	virtual queue<T>& getQueue() = 0;
	virtual void removeFromQueue() = 0;
	virtual T& topOpenList() = 0;

};

