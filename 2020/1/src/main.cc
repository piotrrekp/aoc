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
	if (argc < 1) {
		std::cerr << "Input path to file!" << std::endl;
		return -1;
	}
	auto input = readInput(argv[1]);
	CSolution sol;
	std::cout << "Ans part 1 = " << sol.partOne(input, 2020) << std::endl;
	std::cout << "Ans part 2 = " << sol.partTwo(input, 2020) << std::endl;

	return 0;
}
