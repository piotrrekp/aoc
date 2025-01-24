#include "CSolution.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

std::vector<int> readInput(const char *aPath) {
	std::fstream file(aPath);
	std::vector<int> input;
	std::string line;
	while (getline(file, line)) {
		input.push_back(std::stoi(line));
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
	sol.setData(input);

	std::cout << sol.solvePart1(150) << std::endl;
	std::cout << sol.solvePart2(150) << std::endl;
	return 0;

}
