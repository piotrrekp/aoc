#include "CSolution.h"
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
	CSolution sol;
	std::string input = "1113122113";
	sol.solution(input, 40);
	std::cout << sol.getResultPart1().size() << std::endl;
	sol.solution(input, 50);
	std::cout << sol.getResultPart1().size() << std::endl;
	
	return 0;
}
