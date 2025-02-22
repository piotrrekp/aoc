#include "CSolution.h"
#include <algorithm>
#include <iostream>
#include <utility>


void CSolution::setData(const std::string &_input) {
	data = std::move(_input);
}

int CSolution::getResultPart1() {
	return result1;
}

int CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution() {
	CPoint cp;
	size_t pos = 0;
	size_t find = 0;
	while (find != std::string::npos) {
		find = data.substr(pos).find(',');
		auto r = ERotation::R;
		if (data.substr(pos)[0] == 'L') {
			r = ERotation::L;
		}
		cp.move(r, std::stoi(data.substr(pos + 1, find)));
		pos += find + 2;
	}
	result1 = cp.getDistance();
	result2 = cp.getDistanceToFirstPointVisitedTwice();
}

void CPoint::move(const ERotation turn, const int value) {
	auto startingPoint = std::make_pair(x, y);
	auto endingPoint = std::make_pair(x, y);
	if ((currentDirection == EDirection::N && turn == ERotation::R)
			|| (currentDirection == EDirection::S && turn == ERotation::L)) {
		currentDirection = EDirection::E;
		x += value;
		endingPoint.first = x - 1;
	} else if ((currentDirection == EDirection::N && turn == ERotation::L)
			|| (currentDirection == EDirection::S && turn == ERotation::R)) {
		x -= value;
		startingPoint.first = x + 1;
		currentDirection = EDirection::W;
	} else if ((currentDirection == EDirection::W && turn == ERotation::L)
			|| (currentDirection == EDirection::E && turn == ERotation::R)) {
		y -= value;
		startingPoint.second = y + 1;
		currentDirection = EDirection::S;
	} else if ((currentDirection == EDirection::W && turn == ERotation::R)
			|| (currentDirection == EDirection::E && turn == ERotation::L)) {
		y += value;
		endingPoint.second  = y - 1;
		currentDirection = EDirection::N;
	}

	if (intersectWasFound) {
		return;
	}

	for (int i = startingPoint.first; i <= endingPoint.first; ++i) {
		for (int j = startingPoint.second; j <= endingPoint.second; ++j) {
			auto point = std::make_pair(i, j);
			auto find = std::find_if(visited.begin(), visited.end(), [&point] (const auto &iter) {
				return point.first == iter.first && point.second == iter.second;
			});
			if (find == visited.end()) {
				std::cout << "adding point  = (" << point.first << "," << point.second << ")\n";
				visited.push_back(point);
			} else {
				std::cout << "found intersect! point  = (" << point.first << "," << point.second << ")\n";
				distance = std::abs(point.first) + std::abs(point.second);
				intersectWasFound = true;
				return;
			}
		}
	}
}
