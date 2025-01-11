#include "CSolution.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <numeric>
#include <regex>
#include <stack>
#include <vector>



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
		result1 += check(line);
		result2 += check2();
	}
}

int CSolution::check(const std::string &_line) {
	int result = 0;
	std::regex pattern{"-{0,1}\\d+"};
	std::string line = std::move(_line);
	for (std::smatch match; std::regex_search(line, match, pattern);) {
		result += std::stoi(match[0]);
		line = match.suffix();
	}

	return result;
}

int CSolution::check2() {
	json js = json::parse(data.at(0));
	int total = validate(js);
	return total;

}

int CSolution::validate(json js) {
	int total = 0;
	for (const auto &x : js) {
		if (x.is_number()) {
			total += x.get<int>();
		} if (x.is_string() && x == "red" && js.is_object()) {
			js.clear(); 
			return 0;
		} else if (x.is_object() || x.is_array()) {
			total += validate(x);
		}
	}
	return total;
}

