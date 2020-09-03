#pragma once

#include "command.h"
#include <fstream>

class fileSizeCommand : public command {
public:
	fileSizeCommand(string name, mapNames* maps, mapFiles* mapFiles) : command(), _mazename(name), _maps(maps), _files(mapFiles) {}

	void execute() {

		// check if maze name exist
		// get maze
		// display file size

		if (_maps->findIfmapNameExist(_mazename)) {

			string fileName = _files->findFileNameByMaze(_mazename);
			std::ifstream in(fileName, std::ifstream::ate | std::ifstream::binary);
			streamoff size = in.tellg();
			cout << size << endl;
		}
		else {
			throw "maze dosen't exist";
		}

	}

private:
	string _mazename;
	mapNames* _maps;
	mapFiles* _files;
};
