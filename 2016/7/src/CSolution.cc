#include "CSolution.h"
#include <algorithm>
#include <iterator>
#include <iostream>


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
	for (const auto &line : data) {
		part1(line);
		part2(line);
	}
}

void CSolution::part1(const std::string &line) {
	bool abbaPresent{false};
	bool insideBracket{false};

	char lastChar{line.at(2)};
	char prevChar{line.at(1)};
	char prevPrevChar{line.at(0)};
	for (std::size_t i = 3; i < line.size(); i++) {
		if (line.at(i) == '[') {
			insideBracket = true;
		} else if (line.at(i) == ']') {
			insideBracket = false;
		}
		if (prevChar != prevPrevChar && line.at(i) == prevPrevChar && lastChar == prevChar) {
			if (insideBracket) {
				return;
			}
			abbaPresent = true;
		}
		prevPrevChar = prevChar;
		prevChar = lastChar;
		lastChar = line.at(i);
	}
	result1 += abbaPresent;
}

void CSolution::part2(const std::string &line) {
	bool insideBracket{false};
	char lastChar{line.at(1)};
	char prevChar{line.at(0)};
	std::vector<std::string> abaInside;
	std::vector<std::string> abaOutside;
	for (std::size_t i = 2; i < line.size(); i++) {
		if (line.at(i) == '[') {
			insideBracket = true;
		} else if (line.at(i) == ']') {
			insideBracket = false;
		}
		if (prevChar != lastChar && line.at(i) == prevChar) {
			std::string aba = std::string(1, line.at(i)) + lastChar + prevChar;
			if (insideBracket) {
				abaInside.push_back(aba);
			} else {
				abaOutside.push_back(aba);

			}
		}
		prevChar = lastChar;
		lastChar = line.at(i);
	}
	std::vector<std::string> common{};
	std::copy_if(
		abaInside.begin(),
		abaInside.end(),
		std::back_inserter(common),
		[&abaOutside](const auto & in){
			std::string tmp = std::string(1, in.at(1)) + in.at(0) + in.at(1);
			return std::find(abaOutside.begin(), abaOutside.end(), tmp) != abaOutside.end();
		}
	);
	result2 += (!common.empty());
}
