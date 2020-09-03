#pragma once

#include "myController.h"
#include "View.h"
#include "Model.h"

class controller {
public:
	controller(ostream& out, istream& in, Model& model, View& view, myController& control) : _out(out), _in(in) {
		_model = new Model(model);
		_view = new View(view);
		mycontrol = new myController(control);
	}
	~controller() {
		delete _model;
		delete _view;
		delete mycontrol;
	}

	void start() {							// start runing program
		_view->Vinitialize(_out, _in, mycontrol);
		mycontrol->initialize(_model->getMyModel(), _model->getmapFiles(), _model->getmapNames());
		_view->Line();
		int choose = 0;

		while (choose != 10) {
			choose = _view->start();
			commands(choose);
		}
	}

	void commands(int choosen) {

			//initialize command paramaters
			string fileName;
			string mazeName;
		
			vector<string> path;
			int _rows = 0;
			int _colums = 0;
			int alg = 0;

			// options

			if (choosen == 1) {
			loop1:
				string tmp = "please enter a path";
				_view->getprintView()->printNotifications(_out, tmp);

				string P = _view->getCLIview()->mypath();
				path.insert(path.begin(), P);

				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 1, path);
				}
				catch (const char* error) {
					_view->getprintView()->printWarnings(_out, error);
					goto loop1;
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 2) {
			loop2:
				string tmp = "please enter maze name";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "maze name :";
				_view->getprintView()->printNotifications(_out, tmp);

				mazeName = _view->getCLIview()->name();

				tmp = "please enter maze height and width";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "maze height :";
				_view->getprintView()->printNotifications(_out, tmp);
		
				_rows = _view->getCLIview()->Myrow();

				tmp = "maze width :";
				_view->getprintView()->printNotifications(_out, tmp);
		
				_colums = _view->getCLIview()->Mycol();

				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 2, path);
				}
				catch (const char* error) {

					_view->getprintView()->printWarnings(_out, error);
					goto loop2;
				}

				tmp = "your maze was succsesfuly ceated";
				_view->getprintView()->printNotifications(_out, tmp);

			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 3) {
			loop3:
				string tmp = "please enter maze name";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "maze name :";
				_view->getprintView()->printNotifications(_out, tmp);
		
				mazeName = _view->getCLIview()->name();

				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 3, path);
				}
				catch (const char* error) {

					_view->getprintView()->printWarnings(_out, error);
					goto loop3;
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 4) {
			loop4:

				string tmp = "please enter maze name";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "maze name :";
				_view->getprintView()->printNotifications(_out, tmp);
			
				mazeName = _view->getCLIview()->name();

				tmp = "please enter file name";
				_view->getprintView()->printNotifications(_out, tmp);
				tmp = "file name :";
				_view->getprintView()->printNotifications(_out, tmp);
		
				fileName = _view->getCLIview()->Filename();
				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 4, path);
				}
				catch (const char* error) {

					_view->getprintView()->printWarnings(_out, error);
					goto loop4;
				}

				tmp = "your file was succsesfuly saved";
				_view->getprintView()->printNotifications(_out, tmp);
			
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 5) {
			loop5:

				string tmp = "please enter maze name";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "maze name :";
				_view->getprintView()->printNotifications(_out, tmp);

				mazeName = _view->getCLIview()->name();

				tmp = "please enter file name";
				_view->getprintView()->printNotifications(_out, tmp);
				tmp = "file name :";
				_view->getprintView()->printNotifications(_out, tmp);
			
				fileName = _view->getCLIview()->Filename();
				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 5, path);
				}
				catch (const char* error) {

					_view->getprintView()->printWarnings(_out, error);
					goto loop5;
				}

				tmp = "your maze was succsesfuly loaded and saved to map ";
				_view->getprintView()->printNotifications(_out, tmp);
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 6) {

			loop6:
				string tmp = "please enter maze name";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "maze name :";
				_view->getprintView()->printNotifications(_out, tmp);
				
				mazeName = _view->getCLIview()->name();

				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 6, path);
				}
				catch (const char* error) {

					_view->getprintView()->printWarnings(_out, error);
					goto loop6;
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 7) {
			loop7:

				string tmp = "please enter maze name";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "maze name :";
				_view->getprintView()->printNotifications(_out, tmp);
		
				mazeName = _view->getCLIview()->name();

				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 7, path);
				}
				catch (const char* error) {

					_view->getprintView()->printWarnings(_out, error);
					goto loop7;
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////

			else if (choosen == 8) {
			loop8:

				string tmp = "please enter maze name";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "maze name :";
				_view->getprintView()->printNotifications(_out, tmp);

		
				mazeName = _view->getCLIview()->name();

				tmp = "please choose algorithm number ";
				_view->getprintView()->printNotifications(_out, tmp);

				tmp = "press '1' for A* with pitagoras huristic :";
				_view->getprintView()->printNotifications(_out, tmp);
				tmp = "press '2' for A* with manhattan huristic :";
				_view->getprintView()->printNotifications(_out, tmp);
				tmp = "press '3' for BFS  :";
				_view->getprintView()->printNotifications(_out, tmp);
	
				
				alg = _view->getCLIview()->myAlgor();
				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 8, path);
				}
				catch (const char* error) {

					_view->getprintView()->printWarnings(_out, error);
					goto loop8;
				}

				tmp = "solution is ready";
				_view->getprintView()->printNotifications(_out, tmp);
			
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 9) {

			loop9:
				string tmp = "please enter maze name";
				_view->getprintView()->printNotifications(_out, tmp);
				tmp = "maze name :";
				_view->getprintView()->printNotifications(_out, tmp);
			
				mazeName = _view->getCLIview()->name();

				try {
					mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 9, path);
				}
				catch (const char* error) {

					_view->getprintView()->printWarnings(_out, error);
					goto loop9;
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 10) {	//exit

				mycontrol->initializeCommands(mazeName, fileName, _rows, _colums, alg, 10, path);		// free all dynamic allocations
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 11) {

				Demo testDemo;
				testDemo.run();
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (choosen == 12) {

				Demo testDemo;
				testDemo.playTestMazeGenerator();
			}

	}

	Model* getModel() { return _model; }
	void getDmemortView() {					// delete dynamic memeory
		delete _view->getCLIview();
		delete _view->getprintView();
	}

private:
	Model* _model;
	View* _view;
	myController* mycontrol;

	istream& _in;
	ostream& _out;
};
