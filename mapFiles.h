#pragma once

#include <string>
#include <unordered_map>

#include "Maze2d.h"
#include "mazeCompression.h"
#include "Solution.h"
#include "cell.h"

#define FileNAme "mazeSolutions"			// MyModel file name
#define mymazeName "AllMyModelsMazes"

class mapFiles {
public:
	mapFiles() { _myFiles.insert(pair<string, string>(mymazeName, "FileNAme")); }
	
	void insert(string mazeName, string fileName) {
		_myFiles.insert(pair<string, string>(mazeName, fileName));
	}

	unordered_map<string, string>& getVec() { return _myFiles; }

	bool findIfNameExist(string name) {					// is file name exist
		for (auto start = _myFiles.begin(); start != _myFiles.end(); start++) {

			if ((*start).second == name) {				// this file name already exist
				return true;
			}
		}
		return false;
	}

	string findFileNameByMaze(string mazeName) {		//get file name that attached to maze name
		string fileName;
		unordered_map<string, string>::iterator it = _myFiles.find(mazeName);
		if (it != _myFiles.end())
			fileName = it->second;
		return fileName;
	}

private:
	unordered_map<string, string> _myFiles; // string = name of maze, string = file maze
};
