#include "CSolution.h"
#include "CCommand.h"
#include "CPoint.h"
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <numeric>


void CLights::execute(const CCommand &_command) {
	switch (_command.getCommand()) {
		case ECommand::TURN_ON:
			turnOn(_command.getStart(), _command.getEnd());
			break;
		case ECommand::TURN_OFF:
			turnOff(_command.getStart(), _command.getEnd());
			break;
		case ECommand::TOGGLE:
			toggle(_command.getStart(), _command.getEnd());
			break;
		default:
			break;
	}
}

void CLights::execute2(const CCommand &_command) {
	switch (_command.getCommand()) {
		case ECommand::TURN_ON:
			turnOn(_command.getStart(), _command.getEnd(), true);
			break;
		case ECommand::TURN_OFF:
			turnOff(_command.getStart(), _command.getEnd(), true);
			break;
		case ECommand::TOGGLE:
			toggle(_command.getStart(), _command.getEnd(), true);
			break;
		default:
			break;
	}

}

void CLights::toggle(const CPoint &_start, const CPoint &_end, const bool _part2) {
	auto const startRow = matrix.begin() + _start.getY();
	auto const endRow = matrix.begin() + _end.getY() + 1;

	std::for_each(startRow, endRow, [&](std::array<int, LIGHTS_SIZE> &row) {
		std::for_each(row.begin() + _start.getX(), row.begin() + _end.getX() + 1, [&_part2](int &x) {
			if(_part2) {
				x += 2;
			} else {
				x = !x;
			}
		});
	});
}

void CLights::turnOff(const CPoint &_start, const CPoint &_end, const bool _part2) {
	auto const startRow = matrix.begin() + _start.getY();
	auto const endRow = matrix.begin() + _end.getY() + 1;

	std::for_each(startRow, endRow, [&](std::array<int, LIGHTS_SIZE> &row) {
		std::for_each(row.begin() + _start.getX(), row.begin() + _end.getX() + 1, [&_part2](int &x) {
			if(_part2) {
				x = std::max(0, x - 1);
			} else {
				x = 0;
			}
		});
	});
}

void CLights::turnOn(const CPoint &_start, const CPoint &_end, const bool _part2) {
	auto const startRow = matrix.begin() + _start.getY();
	auto const endRow = matrix.begin() + _end.getY() + 1;

	std::for_each(startRow, endRow, [&](std::array<int, LIGHTS_SIZE> &row) {
		std::for_each(row.begin() + _start.getX(), row.begin() + _end.getX() + 1, [&_part2](int &x) {
			if(_part2) {
				x += 1;
			} else {
				x = 1;
			}
		});
	});
}

int CLights::getLit() {
	auto suma = [](int sum, std::array<int, LIGHTS_SIZE> b) {
		return sum + std::accumulate(b.begin(), b.end(), 0);
	};
	return std::accumulate(matrix.begin(), matrix.end(), 0, suma);
}


void CSolution::command(const std::string &_command, const bool _part2) {
	CCommandParser command(_command);
	if (_part2) {
		lights.execute2(command.getCommand());
	} else {
		lights.execute(command.getCommand());
	}
}

int CSolution::getTurnedLights() {
	return lights.getLit();
}
