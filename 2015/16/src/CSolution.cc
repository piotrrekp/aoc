#include "CSolution.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <regex>


void CSolution::setData(const std::vector<std::string> &_input) {
	for_each(_input.begin(), _input.end(), [&](auto s){analyze(s);});
}

void CSolution::analyze(const std::string &line) {
	std::regex pattern(R"(^Sue (\d+): (.*?): (\d+), (.*?): (\d+), (.*?): (\d+)$)");
	std::smatch match;
	std::regex_search(line, match, pattern);

	if (
		checkWord((match[2].str()), std::stoi(match[3].str())) &&
		checkWord((match[4].str()), std::stoi(match[5].str())) &&
		checkWord((match[6].str()), std::stoi(match[7].str())) && !res1) {
			res1 = true;
			result1 = std::stoi(match[1].str());
	}
	if (
		checkWordSecondPart((match[2].str()), std::stoi(match[3].str())) &&
		checkWordSecondPart((match[4].str()), std::stoi(match[5].str())) &&
		checkWordSecondPart((match[6].str()), std::stoi(match[7].str())) && !res2) {
			res2 = true;
			result2 = std::stoi(match[1].str());
	}
}

bool CSolution::checkWord(const std::string & key, const int value) {
	return wanted.at(key) == value;
}

bool CSolution::checkWordSecondPart(const std::string & key, const int value) {
	if (key == "cats" || key == "trees") {
		return wanted.at(key) <=  value;
	} else if (key == "pomeraninas" || key == "goldfish") {
		return wanted.at(key) >= value;
	}
	return wanted.at(key) == value;
}

int CSolution::getResultPart1() {
	return result1;
}

int CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution() {

}
