#include "CSolution.h"
#include <utility>


void CSolution::setData(const std::vector<std::string> &_input) {
	data = std::move(_input);
}

int CSolution::getResultPart1() {
	return result1;
}

std::string CSolution::getResultPart2() {
	return result2;
}

void CSolution::solution() {
	for (const auto &line : data) {
		for (const auto &c : line) {
			move_simple(MOVE.at(c));
			move_complex(MOVE.at(c));
		}
		result1 = result1 * 10 + SIMPLE_KEYBOARD[currentPoint_simple.first][currentPoint_simple.second];
		result2 = result2  + COMPLEX_KEYBOARD[currentPoint_complex.first][currentPoint_complex.second];
	}
}

void CSolution::move_simple(const std::pair<int, int> &direction) {
	auto [x, y] = currentPoint_simple;
	x += direction.first;
	y += direction.second;

	if (x < 0) x = 0;
	else if (x > 2) x = 2;

	if (y < 0) y = 0;
	else if (y > 2) y = 2;

	currentPoint_simple = {x, y};
}

void CSolution::move_complex(const std::pair<int, int> &direction) {
	auto [x, y] = currentPoint_complex;
	x += direction.first;
	y += direction.second;
	if (COMPLEX_KEYBOARD[x][y] == 'X') return;
	currentPoint_complex = {x,y};
}
