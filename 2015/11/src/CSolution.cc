#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <regex>
#include <set>
#include <string>

std::string &operator++(std::string &input) {
	auto iter = input.end();
	while (*(--iter) == 'z') {
		if (iter == input.begin()) {
			*iter = 'a';
			input = 'a' + input;
			return input;
		}
		*iter = 'a';
	};
	++(*iter);
	return input;
};

std::string operator++(std::string &input, int) {
	auto old = input;
	++input;
	return old;
};

std::string CSolution::getResultPart1() {
	return result1;
}

int CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution(const std::string &input) {
	result1 = input;
	while(true) {
		bool founded = checkExcluded(result1)
			&& checkPairs(result1)
			&& checkStraightAtLeastThreeLetters(result1);
		if (founded) return;
		++result1;
	}
}

bool CSolution::checkStraightAtLeastThreeLetters(const std::string &input) {
	char c = 'a';
	std::string tmp{"abc"};
	for (; c != 'z' - 1; ++c) {
		auto found = input.find(tmp);
		if (found != std::string::npos) {
			return true;
		}
		++tmp[0];
		++tmp[1];
		++tmp[2];
	}
	return false;
}

bool CSolution::checkExcluded(const std::string &input) {
	std::string excluded = "ilo";
	return !std::any_of(
		excluded.begin(),
		excluded.end(),
		[&input](char c){
			return input.find(c) != std::string::npos;
		});
}

bool CSolution::checkPairs(const std::string &input) {
	std::set<char> pairs{};
	auto iter = input.begin();
	while (iter != input.end()) {
		iter = std::adjacent_find(iter, input.end());
		if (iter != input.end()) {
			pairs.insert(*iter);
			++iter;
		}
		if (pairs.size() >= 2) return true;
	}
	return false;

}
