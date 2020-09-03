#include "Demo.h"

void Demo::run()
{
	myMaze2dGenerator myM;				
	Maze2d maze(myM.generate(10, 10, "myMaze"));		//algorithm maze
	cout << maze << endl;
	MazeSearchable searchable(maze);					// making maze searchable

	// BFS
	cout << "solution with BFS" << endl;
	BFS<cell> BFSalg;
	Solution<cell>* bfstemp = BFSalg.search(searchable);
	Solution<cell> bfsresult(*bfstemp);

	cout << BFSalg.getNumberOfNodesEvaluated() << endl;
	for (auto start = bfsresult.getSolution().begin(); start != bfsresult.getSolution().end(); start++) {

		cout << "{" << start._Ptr->getPosition().getrow() << "," << start._Ptr->getPosition().getcol() << "}" << endl;
	}

	delete bfstemp;


	// A*
	cout << "solution with A *" << endl;
	// pitagoras huristic
	cout << "solution with pitagoras huristic" << endl;
	pitagorasH* heuristi = new pitagorasH();			// free dynamic at A*
	AStar<cell> alg(heuristi);
	Solution<cell>* temp = alg.search(searchable);		
	Solution<cell> result(*temp);

	cout << alg.getNumberOfNodesEvaluated() << endl;
	for (auto start = result.getSolution().begin(); start != result.getSolution().end(); start++) {

		cout << "{" << start._Ptr->getPosition().getrow() << "," << start._Ptr->getPosition().getcol() << "}" << endl;
	}

	delete temp;

	// manhattan huristic
	cout << "solution with manhattan huristic" << endl;
	manhattanH* heuristiM = new manhattanH();			// free dynamic at A*		
	AStar<cell> algM(heuristiM);
	Solution<cell>* tempM = algM.search(searchable);	
	Solution<cell> resultM(*tempM);

	cout << algM.getNumberOfNodesEvaluated() << endl;
	for (auto start = resultM.getSolution().begin(); start != resultM.getSolution().end(); start++) {

		cout << "{" << start._Ptr->getPosition().getrow() << "," << start._Ptr->getPosition().getcol() << "}" << endl;
	}

	delete tempM;
}

void Demo::playTestMazeGenerator() {
	TestMazeGenerator t;			// simple maze
	TestMazeGenerator t2;			// algorithm maze
	t.testMazeGenerator(*new simpleMaze2dGenerator());
	t2.testMazeGenerator(*new  myMaze2dGenerator());
}