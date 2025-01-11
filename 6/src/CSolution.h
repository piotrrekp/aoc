#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <array>
#include <bitset>
#include <string>
#include "CPoint.h"
#include "CCommand.h"
#include "CCommandParser.h"


const int LIGHTS_SIZE = 1000;

class CLights {
public:
	void execute(const CCommand &_command);
	void execute2(const CCommand &_command);
	int getLit();

private:
	template <typename Function>
	void doIt(const CPoint &_start, const CPoint &_end, Function &f);
	void toggle(const CPoint &_start, const CPoint &_end, const bool part2 = false);
	void turnOn(const CPoint &_start, const CPoint &_end, const bool part2 = false);
	void turnOff(const CPoint &_start, const CPoint &_end, const bool part2 = false);
	std::array<std::array<int, LIGHTS_SIZE>, LIGHTS_SIZE> matrix{};

};

class CSolution {
public:
	void command(const std::string &command, const bool _part2 = false);
	int getTurnedLights();
private:
	CLights lights;
};

#endif // _CSOLUTION_H_

