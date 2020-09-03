#include "MyView.h"

void MyView::printBoard(ostream& out, Maze2d& _maze)
{
	char temp;
	for (size_t i = 0; i < _maze.getHeight(); i++) {
		for (size_t j = 0; j < _maze.getWidth(); j++) {
			temp = _maze.getBoard()[i][j].getvalue();
			if (temp == '1') {
				out << " * ";
			}
			else if (temp == '0') {
				out << "   ";
			}
			else if (temp == 'G') {
				out << " G ";
			}
			else if (temp == 'S') {
				out << " S ";
			}

		}
		out << endl;
	}
}

void MyView::printNotifications(ostream& out, string str)
{
	out << endl << str << endl;
}

void MyView::printSoultions(ostream& out, Solution<cell>& s)
{
	for (auto start = s.getSolution().begin(); start != s.getSolution().end(); start++) {

		out << "{" << start._Ptr->getPosition().getrow() << "," << start._Ptr->getPosition().getcol() << "}" << endl;
	}
}

void MyView::printWarnings(ostream& out, const char* str)
{
	out << endl << str << endl;
}