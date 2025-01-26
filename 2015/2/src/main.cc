#include "CSolution.h"
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
	if (argc < 1) {
		std::cerr << "Input path to file!" << std::endl;
		return -1;
	}
	std::fstream file(argv[1]);
	std::vector<std::string> input;
	std::string line;
	while (getline(file, line)) {
		input.push_back(line);
	}
	file.close();

	CSolution solution;
	int vResult = solution.getTotalNeededSurface(input);
	int vSecondResult = solution.getTotalRibbonNeeded(input);
	std::cout << vResult << ", " << vSecondResult << std::endl;

	return 0;
}
