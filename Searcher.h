#pragma once

#include "Solution.h"
#include "Searchable.h"
#include "mazeState.h"

template <class T, class U>
class Searcher			// U =cell, T = mazeState
{
public:
	virtual Solution<U>* search(Searchable<T,U>& s) = 0;		
	virtual int getNumberOfNodesEvaluated() const = 0;
};

