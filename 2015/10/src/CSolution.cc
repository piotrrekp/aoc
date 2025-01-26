#include "CSolution.h"


void CSolution::setData(const std::vector<std::string> &_input) {
	data = std::move(_input);
}

std::string CSolution::getResultPart1() {
	return result1;
}

int CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution(const std::string &_line, const int _iteration) {
	auto result = _line;
	for (auto i = 0; i < _iteration; ++i) {
		result = singleLoop(result);
	}
	result1 = result;
}

std::string CSolution::singleLoop(const std::string &_line) {
	std::string ans = "";
	int counter = 1;
	auto lastChar = *_line.begin();
	for (auto iter = std::next(_line.begin()); iter != _line.end(); ++iter) {
		if (lastChar == *iter) {
			++counter;
			continue;
		} else {
			ans += std::to_string(counter);
			ans += lastChar;
			lastChar = *iter;
			counter = 1;
		}

	}
	ans += std::to_string(counter);
	ans += lastChar;
	return ans;

}
