#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include "CSolution.h"

std::vector<std::string> readInput(const char *aPath) {
	std::fstream file(aPath);
	std::vector<std::string> input;
	std::string line;
	while (getline(file, line)) {
		input.push_back(line);
	}
	file.close();
	return input;
}

int main(int argc, char **argv) {
	if (argc < 1) {
		std::cerr << "Input path to file!" << std::endl;
		return -1;
	}
	auto input = readInput(argv[1]);
	CSolution solution;
	CSolution solution2;
	for (const auto line : input) {
		solution.command(line);
		solution2.command(line, true);
	}
	std::cout << solution.getTurnedLights() << std::endl;
	std::cout << solution2.getTurnedLights() << std::endl;


	return 0;
}
