#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <numeric>
#include <regex>
#include <string>
#include <unordered_map>


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
		std::regex pattern(R"(^(.*)-(\d+)\[(.*)\])");
		std::smatch match;
		std::regex_match(line, match, pattern);

		analyzePart1(match[1].str(), std::stoi(match[2]), match[3].str());
		std::cout << analyzePart2(match[1].str(), std::stoi(match[2])) << " - " << std::stoi(match[2]) << std::endl;
	}
}

void CSolution::analyzePart1(const std::string_view &name, const int id, const std::string_view &checksum) {
	std::unordered_map<char, int> histogram;

	for (const auto &c : name) {
		if (c != '-')
			++histogram[c];
	}
	std::vector<std::pair<char, int>> sortedHistogram(
		histogram.begin(), histogram.end()
		);
	std::partial_sort(
		sortedHistogram.begin(),
		sortedHistogram.begin() + checksum.size(),
		sortedHistogram.end(),
		[](const auto &a, const auto &b) {
			return (a.second == b.second) ?
				a.first < b.first :
				a.second > b.second;
		}
	);
	auto tmp = std::accumulate(
		sortedHistogram.begin(),
		sortedHistogram.begin() + checksum.size(),
		std::string{},
		[](auto res, auto x){return res += x.first;}
	);
	if (tmp == checksum) result1 += id;
}

std::string CSolution::analyzePart2(const std::string_view &name, const int id) {

	return std::accumulate(name.begin(), name.end(), std::string{}, [&id](auto res, auto c) {
		if (c == '-') return res += ' ';
		char x = c + id % 26;
		if (x > 'z') {
			 x -= 'z' - 'a' + 1;
		}
		return res += x;
	});
}
