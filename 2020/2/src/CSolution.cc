#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

int CSolution::partOne(const std::vector<std::string> &data) {
	std::regex pattern(R"(^(\d+)-(\d+) (\w): (.*)$)");
	std::smatch match;
	auto res{0};
	for (const auto &line : data) {
		std::regex_match(line, match, pattern);
		std::string newLine = match[4].str();
		char x = match[3].str()[0];
		auto count = std::count(newLine.begin(), newLine.end(), x);
		if (count >= std::stoi(match[1].str()) && count <= std::stoi(match[2].str())) {
			++res;
		}
	}
	return res;
}
int CSolution::partTwo(const std::vector<std::string> &data) {
	std::regex pattern(R"(^(\d+)-(\d+) (\w): (.*)$)");
	std::smatch match;
	auto res{0};
	for (const auto &line : data) {
		std::regex_match(line, match, pattern);
		std::string newLine = match[4].str();
		char x = match[3].str()[0];
		auto first = std::stoi(match[1].str()) - 1;
		auto last = std::stoi(match[2].str()) - 1;

		if (newLine[first] == x && newLine[last] != x ||
			newLine[first] != x && newLine[last] == x) {
			++res;
		}
	}
	return res;
}
