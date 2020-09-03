#pragma once

#include "MyModel.h"
#include "mapFiles.h"
#include "mapNames.h"

class Model {
public:

	Model() {
		_MyModel = new MyModel();
		_MapFiles = new mapFiles();
		_MapNames = new mapNames();
	}
	~Model() {
		delete _MyModel;
		delete _MapFiles;
		delete _MapNames;
	}

	MyModel* getMyModel() { return _MyModel; }
	mapFiles* getmapFiles() { return _MapFiles; }
	mapNames* getmapNames() { return _MapNames; }
	


private:
private:
	MyModel* _MyModel;
	mapFiles* _MapFiles;
	mapNames* _MapNames;
};
