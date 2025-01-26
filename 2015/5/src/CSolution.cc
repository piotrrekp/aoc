#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <ostream>
#include <string>

void CSolution::setData(const std::vector<std::string> &data) {
	mData = data;
}

int CSolution::getNiceStringCount() {
	auto has3vowels = [this](const std::string &text){
		return this->hasAtLeast3vowels(text) &&
			this->hasAtLeastOneLetterTwiceInRow(text) &&
			this->notContainExcludedStrings(text);};
	return std::count_if(mData.begin(), mData.end(), has3vowels);
}

bool CSolution::hasAtLeast3vowels(const std::string &text) {
	int count = 0;
	for (const auto c : VOWELS) {
		count += std::count(text.begin(), text.end(), c);
		if (count >= 3) return true;
	}
	return false;
}

bool CSolution::hasAtLeastOneLetterTwiceInRow(const std::string &text) {
	return std::adjacent_find(text.begin(), text.end()) != text.end();
}


bool CSolution::notContainExcludedStrings(const std::string &text) {
	return std::none_of(
		EXCLUDED.begin(), EXCLUDED.end(),
		[text](std::string str){return std::string::npos != text.find(str);});
}

int CSolution::getNiceStringCountPartTwo() {
	auto requirements = [this](const std::string &text){
		return hasPairWithOneLetterBetween(text) &&
			hasAtLeastTwicePair(text);
	};

	return std::count_if(mData.begin(), mData.end(), requirements);
}

bool CSolution::hasPairWithOneLetterBetween(const std::string &text) {
	for (std::size_t i = 0; i < text.size() - 2; ++i) {
		if (text.at(i) == text.at(i + 2)) return true;
	}

	return false;
}

bool CSolution::hasAtLeastTwicePair(const std::string &text) {
	std::string sub;
	std::string lastSubstr = "";
	std::map<std::string, int> founded;
	for(std::size_t i = 0; i < (text.size() - 1); ++i) {
		sub = text.substr(i, 2);
		if (sub == lastSubstr) {
			continue;
		}
		if (founded.count(sub)) {
			return true;
		} else {
			founded[sub] = 1;
			lastSubstr = sub;
		}

	}

	return false;
}
