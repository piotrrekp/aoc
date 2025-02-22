#include "CSolution.h"
#include <ios>
#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

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
	if (argc < 2) {
		std::cerr << "Input path to file!" << std::endl;
		return -1;
	}
	auto input = readInput(argv[1]);
	CSolution sol;
	sol.setData(input.at(0));
	sol.solution();

	std::cout << sol.getResultPart1() << std::endl;
	std::cout << sol.getResultPart2() << std::endl;
	return 0;

}
