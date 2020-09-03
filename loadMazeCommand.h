#pragma once

#include "command.h"

class loadMazeCommand : public command {
public:

	loadMazeCommand(string name, string file, mapFiles* files, mapNames* maps) : command(), _mazename(name), _filename(file), _myfile(files), _maps(maps) {}

	void execute() {

		// find if file name exist
		// load map from file name
		// save maze to name maze map
		

		if (_myfile->findIfNameExist(_filename))
		{
			vector<int> mazedata;
			mazeCompression loadmap;
			mazedata = loadmap.readMazeFile(_filename);
			Maze2d map(mazedata);						// loaded maze

			_maps->insertToMap(_mazename, map);			// save loaded map into file with new name
		}
		else
			throw "file dosen't exist";

	}

private:
	string _mazename;
	string _filename;
	mapFiles* _myfile;
	mapNames* _maps;
};