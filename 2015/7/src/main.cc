#include "CSolution.h"
#include <thread>
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
	auto input1 = readInput(argv[1]);
	auto input2 = readInput(argv[2]);

	CSolution sol1, sol2;
	
	auto th1 = std::thread(std::ref(sol1), std::ref(input1));
	auto th2 = std::thread(std::ref(sol2), std::ref(input2));

	th1.join();
	th2.join();
	
	std::cout << "Ans part 1 = " << sol1.getSignalFromWire("a") << std::endl;
	std::cout << "Ans part 2 = " <<  sol2.getSignalFromWire("a") << std::endl;


	return 0;
}
