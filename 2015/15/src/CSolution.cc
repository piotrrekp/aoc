#include "CSolution.h"
#include <algorithm>
#include <alloca.h>
#include <cstdio>
#include <filesystem>
#include <functional>
#include <limits>
#include <numeric>
#include <iostream>
#include <string>


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
	analyze();
	result1 = maximizeScore();

	int index = 0;
	int remaining = TOTAL;
	result2 = std::numeric_limits<int>::min();
	std::vector<int> allocation(ingredients.size(), 0);
	findMaxScoreUnder500kcal(ingredients, allocation, index, remaining, result2);
	// result2 = max_score;
}


void CSolution::analyze() {	char dummy[500];
	int c = 0;
	int d = 0;
	int f = 0;
	int t = 0;
	int cal = 0;
	for (const auto &line : data) {
		sscanf(
			line.c_str(),
			"%[^:]: capacity %d, durability %d, flavor %d, texture %d, calories %d",
			dummy, &c, &d, &f, &t, &cal);
		ingredients.emplace_back(properties({c, d, f, t, cal}));
	}
}

int CSolution::maximizeScore() {
	int index = 0;
	int remaining = TOTAL;
	int max_score = std::numeric_limits<int>::min();
	std::vector<int> allocation(ingredients.size(), 0);
	findMaxScore(ingredients, allocation, index, remaining, max_score);
	return max_score;
}


void CSolution::findMaxScore(
		const std::vector<properties> &prop,
		std::vector<int> &allocation,
		std::size_t index,
		int remaining,
		int &max_score) {
	if (prop.size() == 1) {
		max_score = TOTAL * std::accumulate(prop.begin(), prop.end(), 0, [](auto sum, const properties &p) {
			return sum + p.flavor * p.texture * p.capacity * p.durability;
		});
	}

	if (index == prop.size() - 1) {
		*allocation.rbegin() = remaining;
		int c = 0, d = 0, f = 0, t = 0;

		for(std::size_t i = 0; i < prop.size(); ++i) {
			c += allocation.at(i) * prop.at(i).capacity;
			d += allocation.at(i) * prop.at(i).durability;
			f += allocation.at(i) * prop.at(i).flavor;
			t += allocation.at(i) * prop.at(i).texture;
		}
		c = std::max(c, 0);
		f = std::max(f, 0);
		d = std::max(d, 0);
		t = std::max(t, 0);

		max_score = std::max(max_score, c*d*f*t);
		return;
	}

	for (auto i = 0; i <= remaining; ++i) {
		allocation[index] = i;
		findMaxScore(prop, allocation, index + 1, remaining - i, max_score);
	}
}
void CSolution::findMaxScoreUnder500kcal(
		const std::vector<properties> &prop,
		std::vector<int> &allocation,
		std::size_t index,
		int remaining,
		int &max_score) {
	if (prop.size() == 1) {
		max_score = TOTAL * std::accumulate(prop.begin(), prop.end(), 0, [](auto sum, const properties &p) {
			return sum + p.flavor * p.texture * p.capacity * p.durability;
		});
	}

	if (index == prop.size() - 1) {
		*allocation.rbegin() = remaining;
		int c = 0, d = 0, f = 0, t = 0;
		int kcal = 0;

		for(std::size_t i = 0; i < prop.size(); ++i) {
			d += allocation.at(i) * prop.at(i).durability;
			f += allocation.at(i) * prop.at(i).flavor;
			t += allocation.at(i) * prop.at(i).texture;
			c += allocation.at(i) * prop.at(i).capacity;
			kcal += allocation.at(i) * prop.at(i).calories;
		}
			// std::cout << "total kcal = " << kcal << std::endl;
		if (kcal > 500) return;

		c = std::max(c, 0);
		f = std::max(f, 0);
		d = std::max(d, 0);
		t = std::max(t, 0);

		max_score = std::max(max_score, c*d*f*t);
		return;
	}

	for (auto i = 0; i <= remaining; ++i) {
		allocation[index] = i;
		findMaxScoreUnder500kcal(prop, allocation, index + 1, remaining - i, max_score);
	}
}
