#include "CSolution.h"
#include <bitset>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

void CSolution::operator()(const std::vector<std::string> &_circut) {
	input(_circut);
}

void CSolution::input(const std::vector<std::string> &_input) {
	std::vector<std::string> tmp;
	for (const auto line : _input) {
		auto success = analyze(line);
		if (!success) {
			tmp.emplace_back(line);
		}
	}
	if (tmp.empty()) {
		return;
	} else {
		tmp = fillData(tmp);
		input(tmp);
	}
}

std::vector<std::string> CSolution::fillData(const std::vector<std::string> &_circut) {
	std::regex pattern(R"((|NOT )(\b\w+\b)(?: )*(AND|OR|RSHIFT|LSHIFT)*(?: )*(\b\w*\b) (?:->) (.*))");
	std::vector<std::string> result;
	std::smatch match;
	for (const auto line : _circut) {
		bool added = false;
		if (std::regex_search(line.begin(), line.end(), match, pattern)) {
			auto firstUnknonw = match[2].str();
			auto secondUnknonw = match[4].str();
			if (wires.count(firstUnknonw)) {
				added = true;
				auto repl = wires[firstUnknonw];
				result.emplace_back(std::regex_replace(line, std::regex(firstUnknonw), std::to_string(repl.to_ulong())));
			}
			if (wires.count(secondUnknonw)) {
				added = true;
				auto repl = wires[secondUnknonw];
				result.emplace_back(std::regex_replace(line, std::regex(secondUnknonw), std::to_string(repl.to_ulong())));
			}
			if (!added) {
				result.emplace_back(line);
			}
		}
	}
	return result;
}


bool CSolution::analyze(const std::string &_line) {
	std::regex pattern(R"((^|NOT )(\b\d+\b)(?: )*(AND|OR|RSHIFT|LSHIFT)*(?: )*(\b\d*\b) (?:->) (.*))");
	std::smatch result;
	if (std::regex_search(_line.begin(), _line.end(), result, pattern)) {
		std::string oper = result[3].str();
		std::string wire = result[5].str();

		if (!result[1].str().empty()) {
			SIGNAL tmp = std::stoi(result[2]);
			wires.emplace(std::make_pair(wire, ~tmp));
			return true;
		}
		if (oper.empty()) {
			wires.emplace(std::make_pair(wire, std::stoi(result[2])));
			return true;
		} else if (oper == "AND" && result[2].length() && result[4].length()) {
			SIGNAL tmp1 = std::stoi(result[2]);
			SIGNAL tmp2 = std::stoi(result[4]);
			wires.emplace(std::make_pair(wire, tmp1 & tmp2));
			return true;
		} else if (oper == "OR" && result[2].length() && result[4].length()) {
			SIGNAL value = std::stoi(result[2])|std::stoi(result[4]);
			wires.emplace(std::make_pair(wire, value));
			return true;
		} else if (oper == "RSHIFT") {
			SIGNAL tmp1 = std::stoi(result[2]);
			int tmp2 = std::stoi(result[4]);
			wires.emplace(std::make_pair(wire, tmp1 >> tmp2));
			return true;
		} else if (oper == "LSHIFT") {
			SIGNAL tmp1 = std::stoi(result[2]);
			int tmp2 = std::stoi(result[4]);
			wires.emplace(std::make_pair(wire, tmp1 << tmp2));
			return true;
		}
	}
	return false;
}

long CSolution::getSignalFromWire(const std::string &_wire) {
	if (wires.count(_wire)) {
		return wires[_wire].to_ulong();
	}
	return 0;
}

