#pragma once

#pragma once

#include <string>
#include <unordered_map>
#include <string.h>
#include <iostream>

#include "command.h"
#include "mapFiles.h"
#include "mapNames.h"
#include "Maze2d.h"
#include "MyModel.h"

// commands
#include "generateMazeCommand.h"
#include "saveMazeCommand.h"
#include "displayMazeCommand.h"
#include "loadMazeCommand.h"
#include "solveMazeCommand.h"
#include "displaySolutionCommand.h"
#include "exitCommand.h"
#include "dirCommand.h"
#include "fileSizeCommand.h"
#include "mazeSizeCommand.h"

using namespace std;

class myController {
public:

	myController() {

		_allMazeSolutions = nullptr;
		_allmapFiles = nullptr;
		_allmapNames = nullptr;

	
	}
	~myController() {
	
	}
	void initialize(MyModel* model, mapFiles* files, mapNames* names) {
		_allMazeSolutions = model;
		_allmapFiles = files;
		_allmapNames = names;
	}

	void initializeCommands(string mazeName, string fileName, int rows, int colums, int alg, int num, vector<string> _path) {

		if (num == 1)
			myCommands["dir path"] = new dirCommand(_path);															//1 
		else if (num == 2)
			myCommands["generate maze"] = new generateMazeCommand(mazeName, _allmapNames, rows, colums);			//2
		else if (num == 3)
			myCommands["display maze"] = new displayMazeCommand(mazeName, _allmapNames);							//3
		else if (num == 4)
			myCommands["save maze"] = new saveMazeCommand(mazeName, fileName, _allmapFiles, _allmapNames);			//4
		else if (num == 5)
			myCommands["load maze"] = new loadMazeCommand(mazeName, fileName, _allmapFiles, _allmapNames);			//5
		else if (num == 6)
			myCommands["maze size"] = new mazeSizeCommand(mazeName, _allmapNames);									//6	
		else if (num == 7)
			myCommands["file size"] = new fileSizeCommand(mazeName, _allmapNames, _allmapFiles);					//7	
		else if (num == 8)
			myCommands["solve maze"] = new solveMazeCommand(mazeName, _allmapNames, _allMazeSolutions, alg);		//8
		else if (num == 9)
			myCommands["display solution"] = new displaySolutionCommand(mazeName, _allmapNames, _allMazeSolutions);	//9
		else if (num == 10)
			myCommands["exit"] = new exitCommand();																	//10

		try {
			chooseCommand(num);
		}
		catch (const char* Error) {
			throw Error;
			(void)Error;
		}
	}
	void chooseCommand(int num) {

		try {
			if (num == 1) {

				auto got = myCommands.find("dir path");			// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'show all files and folders in path'
			}
		}
		catch (const char* Error) {
			throw "wrong path, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try {
			if (num == 2) { //2

				auto got = myCommands.find("generate maze");	// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'create new maze'
			}
		}
		catch (const char* Error) {
			throw "wrong maze / file name, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try {
			if (num == 3) { //3

				auto got = myCommands.find("display maze");		// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'display maze'
			}
		}
		catch (const char* Error) {
			throw "wrong maze name, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try {
			if (num == 4) { //4

				auto got = myCommands.find("save maze");		// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'save maze to filename'
			}
		}
		catch (const char* Error) {
			throw "wrong maze / file name, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try {
			if (num == 5) { //5

				auto got = myCommands.find("load maze");		// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'load maze to name and save name'
			}
		}
		catch (const char* Error) {
			throw "wrong maze / file name, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try {
			if (num == 6) { //6

				auto got = myCommands.find("maze size");		// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'display maze size in memory'
			}
		}
		catch (const char* Error) {
			throw "wrong maze name, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try {
			if (num == 7) { //7

				auto got = myCommands.find("file size");		// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'display file size in memory'
			}
		}
		catch (const char* Error) {
			throw "wrong maze name, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try {
			if (num == 8) { //8

				auto got = myCommands.find("solve maze");		// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'solve maze to name and save maze, solution'
			}
		}
		catch (const char* Error) {
			throw "wrong maze name/ algorithm choice, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////
		try {
			if (num == 9) { //9

				auto got = myCommands.find("display solution");	// find command

				if (got == myCommands.end())
					throw "command not found";
				else
					got->second->execute();						// execute	:  'display maze solution'
			}
		}
		catch (const char* Error) {
			throw "wrong maze name, please try again";
			(void)Error;

		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		if (num == 10) { //10

			auto got = myCommands.find("exit");				// find command

			if (got == myCommands.end())
				throw "command not found";
			else
				got->second->execute();						// execute	:  'exit' free dynamic memory
		}
	}

private:
	std::unordered_map<string, command*> myCommands;
	mapNames* _allmapNames;
	mapFiles* _allmapFiles;
	MyModel* _allMazeSolutions;
};