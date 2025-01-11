#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <bitset>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

using SIGNAL = std::bitset<16>;

class CSolution {
public:
	void operator()(const std::vector<std::string> &_circut);
	void input(const std::vector<std::string> &_circut);
	long getSignalFromWire(const std::string &_wire);

private:
	std::vector<std::string> fillData(const std::vector<std::string> &_circut);
	bool analyze(const std::string &_line);

	std::map<std::string, SIGNAL> wires;

};

#endif // _CSOLUTION_H_
