#pragma once
#include <iostream>
#include <vector>
#include <memory>

#include "State.h"
#include "cell.h"


template <class U>
class Solution			// U = cell -- must have operand ==
{
public:
	Solution<U>() = default;
	Solution<U>(const Solution<U>& s) {

		m_solution = s.m_solution;
	}
	Solution<U>(vector<U> result) : m_solution(result) {}
	~Solution() {};
	vector<U>& getSolution(){ return m_solution; }

	friend ostream& operator<<(ostream& out, Solution<cell>& s) {

		for (auto start = s.getSolution().begin(); start != s.getSolution().end(); start++) {

			out << "{" << start._Ptr->getPosition().getrow() << "," << start._Ptr->getPosition().getcol() << "}" << endl;
		}

		return out;
	}

	bool operator==(Solution& solut) {
		if (m_solution.size() != solut.getSolution().size())
			return false;

		// equal size
		int count = 0;
		auto start = solut.getSolution().begin();
		while (start != solut.getSolution().end()) {
			for (auto it = m_solution.begin(); it != m_solution.end(); it++) {

				if (*it == *start) {				// if cells are equal
					count++;
				}
				
				else {
					return false;
				}

				start++;
			}
		}

		return true;								// all members are equal
	}


private:
	vector<U> m_solution;
};

