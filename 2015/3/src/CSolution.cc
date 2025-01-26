#include <iostream>
#include "CSolution.h"


int CSolution::getVisitedHouses(const std::string &list) {
	std::map<std::pair<int,int>, int> visitedHouses;
	int x = 0;
	int y = 0;
	visitedHouses[std::make_pair(0,0)] = 1;

	for (const auto &c : list) {
		switch (c) {
			case 'v':
				--y;
				break;
			case '^':
				++y;
				break;
			case '>':
				++x;
				break;
			case '<':
				--x;
				break;
			default:
				std::cerr << "unhandled char: " << c << std::endl;
				break;
		}
		visitedHouses[std::make_pair(x,y)]++;
	}

	return visitedHouses.size();
}

int CSolution::getVisitedHouses_v2(const std::string &list) {
	std::map<std::pair<int,int>, int> visitedHouses;
	int x = 0;
	int x1 = 0;
	int y = 0;
	int y1 = 0;

	visitedHouses[std::make_pair(0,0)] = 2;

	for (std::size_t i = 0; i < list.size(); i = i + 2) {
		const char c = list.at(i);
		switch (c) {
			case 'v':
				--y;
				break;
			case '^':
				++y;
				break;
			case '>':
				++x;
				break;
			case '<':
				--x;
				break;
			default:
				std::cerr << "unhandled char: " << c << std::endl;
				break;
		}
		visitedHouses[std::make_pair(x,y)]++;

		if (i + 1 >= list.size()) break;
		const char c1 = list.at(i+1);

		switch (c1) {
			case 'v':
				--y1;
				break;
			case '^':
				++y1;
				break;
			case '>':
				++x1;
				break;
			case '<':
				--x1;
				break;
			default:
				std::cerr << "unhandled char: " << c << std::endl;
				break;
		}
		visitedHouses[std::make_pair(x1,y1)]++;
	}

	return visitedHouses.size();
}
