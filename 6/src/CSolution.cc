#include "CSolution.h"
#include "CCommand.h"
#include "CPoint.h"
#include <array>
#include <iostream>
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
	for (std::size_t i = _start.getX(); i <= _end.getX(); ++i) {
		for (std::size_t j = _start.getY(); j <= _end.getY(); ++j) {
			if (_part2) {
				matrix.at(i)[j] += 2;

			} else {
				matrix.at(i)[j] = !matrix.at(i)[j];
			}
		}
	}
}

void CLights::turnOff(const CPoint &_start, const CPoint &_end, const bool _part2) {
	for (std::size_t i = _start.getX(); i <= _end.getX(); ++i) {
		for (std::size_t j = _start.getY(); j <= _end.getY(); ++j) {
			if (_part2) {
				matrix.at(i)[j] = std::max(0, matrix.at(i)[j] - 1);


			} else {
				matrix.at(i)[j] = 0;
			}
		}
	}
}

void CLights::turnOn(const CPoint &_start, const CPoint &_end, const bool _part2) {
	for (std::size_t i = _start.getX(); i <= _end.getX(); ++i) {
		for (std::size_t j = _start.getY(); j <= _end.getY(); ++j) {
			if (_part2) {
				matrix.at(i)[j] += 1;
			} else {
				matrix.at(i)[j] = 1;
			}
		}
	}
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
