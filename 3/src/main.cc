#include "CSolution.h"
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>

int main(int argc, char **argv) {
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
	std::cout << solution.getVisitedHouses(line) << std::endl;
	std::cout << solution.getVisitedHouses_v2(line) << std::endl;

	return 0;
}
