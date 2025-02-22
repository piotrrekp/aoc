#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <sstream>


void CSolution::setData(const std::vector<std::string> &_input) {
	data = std::move(_input);
}

int CSolution::getResultPart1() {
	return result1;
}

int CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution() {
	for (std::size_t i = 0; i < data.size(); ++i) {
		std::stringstream ss;
		auto sides = std::vector<int>(3);
		ss << data.at(i);
		ss >> sides[0] >> sides[1] >> sides[2];
		result1 += isTriangle(sides);

		//part Two
		if (i%3 != 0 || (data.size() >= 3 && i > (data.size() - 3))) {
			continue;
		}
		std::stringstream stringStream;
		auto secondPart = std::vector<int>(9);

		stringStream << data.at(i) << data.at(i + 1) << data.at(i + 2);
		for (auto &x : secondPart) {
			stringStream >> x;
		}

		result2 += isTriangle(std::vector<int>({secondPart[0], secondPart[3], secondPart[6]}));
		result2 += isTriangle(std::vector<int>({secondPart[1], secondPart[4], secondPart[7]}));
		result2 += isTriangle(std::vector<int>({secondPart[2], secondPart[5], secondPart[8]}));
	}
}

bool CSolution::isTriangle(const std::vector<int> &sides) {
	auto first = sides.begin();
	auto last = sides.end();
	return (std::accumulate(first, last, 0) - 2 * (*std::max_element(first, last))) > 0;
}
