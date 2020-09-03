
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <iostream>     // std::cout, std::ios
#include "myController.h"
#include "CLIview.h"
#include "View.h"
#include "Model.h"
#include "controller.h"


using namespace std;

int main() {

	//myController controller;
	//CLIview myinteface(cout, cin, controller);
	//myinteface.start();


	myController C;
	View V;
	Model M;

	controller myC(cout, cin, M, V, C);
	myC.start();

	return 0;
}