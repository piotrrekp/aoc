#include "CSolution.h"
#include <algorithm>
#include <map>
#include <unordered_map>
#include <vector>

int CSolution::partOne(const std::vector<int> &data, const int sum) {
	std::map<int, int> twoNumbers;
	for (const auto & x : data) {
		if(twoNumbers.count(x)) {
			return  x*(sum-x);
		} else {
			twoNumbers[sum-x] = 1;
		}
	}
	return -1;
}

int CSolution::partTwo(const std::vector<int> &data, const int sum) {
	std::unordered_map<int, int> lackingNumbers{};
	for (const auto & x : data) {
		for (const auto & y : data) {
			lackingNumbers[sum - x -y] = x * y;
		}
	}

	auto res = std::find_if(data.begin(), data.end(), [&lackingNumbers](auto x){return lackingNumbers[x];});
	return res != data.end() ? *res * lackingNumbers[*res] : -1;
}
