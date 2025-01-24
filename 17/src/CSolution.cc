#include "CSolution.h"
#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <utility>


void CSolution::setData(const std::vector<int> &_input) {
	data = std::move(_input);
	std::sort(data.begin(), data.end());
}

int CSolution::solvePart1(const int volume) {
	auto containers = std::vector<int>(data.size());
	std::partial_sort_copy(data.begin(), data.end(), containers.begin(), containers.end(), std::greater<int>());
	auto weights = std::vector<int>(volume + 1, 0);
	weights[0] = 1;

	std::for_each(containers.begin(), containers.end(), [&volume, &weights](const auto &container){
		for (int i = volume; i > container - 1; --i) {
			weights[i] += weights[i - container];
		}
	});
	return *weights.rbegin();
}


int CSolution::solvePart2(const int volume) {
	auto containers = std::vector<int>(data.size());
	// std::partial_sort_copy(data.begin(), data.end(), containers.begin(), containers.end(), std::greater<int>());
	std::partial_sort_copy(data.begin(), data.end(), containers.begin(), containers.end());


	auto dp = std::vector<std::vector<int>>(containers.size() + 1, std::vector<int>(volume + 1, std::numeric_limits<int>::max()));
	auto ways = std::vector<std::vector<int>>(containers.size() + 1, std::vector<int>(volume + 1, 0));
	dp[0][0] = 0;
	ways[0][0] = 1;

	for (std::size_t i = 1; i <= containers.size(); ++i) {
		for (int w = 0; w <= volume; ++w) {
			dp[i][w] = dp[i -1][w];
			ways[i][w] = ways[i -1][w];

			auto weight = containers[i-1];
			if (w >= weight) {
				if (dp[i-1][w-weight] + 1 < dp[i][w]) {
					dp[i][w] = dp[i-1][w-weight] + 1;
					ways[i][w] = ways[i-1][w-weight];
				} else if (dp[i-1][w-weight] == dp[i][w]) {
					ways[i][w] += ways[i-1][w-weight];
				}

			}

		}

	}
	std::cout << "data\n";
	for (const auto y : data) {
		std::cout << y << ",";
	}
	std::cout << '\n';
	std::cout << "containers\n";
	for (const auto y : containers) {
		std::cout << y << ",";
	}
	std::cout << '\n';
	std::cout << "ways\n";
	for (const auto x : ways) {
		for (const auto y : x) {
			std::cout << y << ",";
		}
		std::cout << '\n';
	}
	return ways[containers.size()][volume];
}
