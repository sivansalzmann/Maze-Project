#pragma once

#include <stdio.h>      /* printf, scanf, puts, NULL */

#include "simpleMaze2dGenerator.h"
#include "myMaze2dGenerator.h"
#include "TestMazeGenerator.h"

#include "AStar.h"
#include "BFS.h"
#include "Heuristic.h"
#include "manhattanH.h"
#include "pitagorasH.h"
#include "MazeSearchable.h"

class Demo
{
public:
	void run();
	void playTestMazeGenerator();

};