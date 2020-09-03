#pragma once

#include "command.h"


class saveMazeCommand : public command {
public:

	saveMazeCommand(string name, string file, mapFiles* files, mapNames* maps) : command(), _mazename(name), _filename(file), _myfile(files), _maps(maps) {}

	void execute() {

		// find if file name exist
		// find if maze with name X exist
		// save maze to file name Y
		// add filename to file names list

		if (_myfile->findIfNameExist(_filename))
			throw "file name already exist";

		if (_maps->findIfmapNameExist(_mazename)) {			// name exist

			Maze2d* map = _maps->getMap(_mazename);			// get map with name X
			mazeCompression savemap(map);
			savemap.writeMazeFile(_filename);

			_myfile->insert(_mazename, _filename);			// add filename to file names map
		}
		else
			throw "file name doesnt exist! can't save maze";

	}

private:
	string _mazename;
	string _filename;
	mapFiles* _myfile;
	mapNames* _maps;
};
