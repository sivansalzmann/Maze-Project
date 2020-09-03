#include "maze2dGeneratorAB.h"

string Maze2dGeneratorAB::measureAlgorithmTime(size_t height, size_t width, string name) {
	ostringstream oss;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	generate(height, width, name);
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	oss << "Time difference" << " " << (end - begin).count() << " " << "[ns]" << endl;
	string var = oss.str();
	return var;
}
