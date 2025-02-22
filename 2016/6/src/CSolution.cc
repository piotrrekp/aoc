#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <string>


void CSolution::setData(const std::vector<std::string> &_input) {
	data = std::move(_input);
}

std::string CSolution::getResultPart1() {
	return result1;
}

std::string CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution() {
	std::map<int, std::map<char, int>> occurance;
	for(const auto &line : data) {
		for (std::size_t i = 0; i < line.size(); ++i) {
			++occurance[i][line[i]];
		}
	}
	result1 = std::accumulate(occurance.begin(), occurance.end(), std::string{},
		[](auto res, const auto &oc) {
			   auto max = std::max_element(
				   oc.second.begin(),
				   oc.second.end(),
				   [](const auto &a, const auto &b){
					return a.second <= b.second;
				   });
				   return res += max->first;
			   ;});
	result2 = std::accumulate(occurance.begin(), occurance.end(), std::string{},
		[](auto res, const auto &oc) {
			   auto max = std::max_element(
				   oc.second.begin(),
				   oc.second.end(),
				   [](const auto &a, const auto &b){
					return a.second >= b.second;
				   });
				   return res += max->first;
			   ;});

}
