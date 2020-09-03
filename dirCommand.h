#pragma once
#include "command.h"
#include "dirent.h"
#include <stdio.h>
#include <string.h>

class dirCommand : public command {
public:
	dirCommand(vector<string> _vec) : vec(_vec) {}
private:
	void execute() {
		string _dirName = vec[0];

		DIR* _dir;
		struct dirent* dire;
		struct stat sta;
		_dir = opendir(_dirName.c_str());
		if (!_dir) {
			cout << "invalid path, try again.";
			return;
		}
		while ((dire = readdir(_dir)) != NULL)
		{
			if (dire->d_name[0] != '.') {
				string path = string(_dirName) + "/" + string(dire->d_name);
				cout << path << endl;
			}
		}
		closedir(_dir);
		(void)sta;
	}
private:
	vector<string> vec;
};
