#include "CSolution.h"

#include <iostream>
#include <regex>

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
	if (data.empty()) {
		result1 = 0;
		result2 = 0;
		return;
	}
	for (const auto &line : data) {
		result1 += analyze(line);
		result2 += partTwo(line);
	}

}

int CSolution::analyze(const std::string &_line) {
	std::regex pattern{R"((\\")|(\\x[a-fA-F0-9]{2})|(\\\\))"};
	auto text = removeOutherQuote(_line);
	text = std::regex_replace(text, pattern, "#");
	
	return _line.size() - text.size();
}

int CSolution::partTwo(const std::string &_line) {
	std::cout << "|" <<  _line << "|" << " : " << _line.size() << std::endl;
	std::regex pattern{R"((")|(\\))"};
	auto text = std::move(_line);
	text = std::regex_replace(text, pattern, "XX");
	std::cout << "|" << text << "|" << " : " << text.size() << std::endl;

	return text.size() - _line.size() + 2 /*outher quote*/;
}

std::string CSolution::removeOutherQuote(const std::string &_line) {
	auto text = std::regex_replace(_line, std::regex("(^\")"), "");
	return  std::regex_replace(text, std::regex("(\"$)"), "");
}
