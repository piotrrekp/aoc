#include "CSolution.h"
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <regex>
#include <string>
#include <sys/wait.h>


void CSolution::setData(const std::vector<std::string> &_input) {
	data = std::move(_input);
}

int CSolution::getResultPart1() {
	return result1;
}

int CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution(const int time) {
	std::for_each(data.begin(), data.end(), [this](const std::string &l){ this->analyze(l);});
	getMaxDistance(time);
	solvePart2(time);
}

void CSolution::analyze(const std::string &line) {
	std::regex pattern(R"(^(.*?) .*?(\d+).*?(\d+).*?(\d+).*)");
	std::smatch match;
	std::regex_match(line, match, pattern);
	param.emplace(param.end(), raindeerParam(match[1], std::stoi(match[2]), std::stoi(match[3]), std::stoi(match[4])));
}

bool operator<(const std::pair<std::string,int> &a, const std::pair<std::string, int> &b) {
	return a.second < b.second;
}

void CSolution::getMaxDistance(const int time) {
	std::map<std::string, int> results;
	std::for_each(param.begin(), param.end(), [&results, &time](raindeerParam const &p) {
		auto singleRoundTime = p.rest + p.duration;
		auto const rounds = time / singleRoundTime;
		auto const timeLeft = time - rounds * singleRoundTime;
		auto distance = rounds*p.speed * p.duration;
		auto const lastSprintTime = (timeLeft >= p.duration) ? p.duration : timeLeft;
		distance += p.speed * lastSprintTime;
		results.insert(std::make_pair(p.name, distance));
	});
	result1 = std::accumulate(results.begin(), results.end(), 0, [](int res, const auto &p) {return std::max(res, p.second);});
}
void CSolution::solvePart2(const int time) {
	std::map<std::string, int> results;
	for(int i = 1; i <= time; ++i) {
		std::map<std::string, int> roundResults;
		std::for_each(param.begin(), param.end(), [&roundResults, &i](raindeerParam const &p) {
			auto singleRoundTime = p.rest + p.duration;
			auto const rounds = i / singleRoundTime;
			auto const timeLeft = i - rounds * singleRoundTime;
			auto distance = rounds*p.speed * p.duration;
			auto const lastSprintTime = (timeLeft >= p.duration) ? p.duration : timeLeft;
			distance += p.speed * lastSprintTime;
			roundResults.insert(std::make_pair(p.name, distance));
		});
		auto roundWinner = std::max_element(roundResults.begin(), roundResults.end(), [](const auto &lhs, const auto &rhs) {
			return lhs.second <= rhs.second;
		});
		if (roundWinner != roundResults.end())
			++results[roundWinner->first];
	}
	result2 = std::max_element(results.begin(), results.end(), [](const auto &lhs, const auto &rhs) {
		return lhs.second < rhs.second;
		})->second;
}
