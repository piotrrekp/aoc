#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <vector>
#include <string>

class CSolution {
public:
	int getNeededSurface(const int, const int, const int);
	int getTotalNeededSurface(const std::vector<std::string> &);
	int getTotalRibbonNeeded(const std::vector<std::string> &);
private:
	int getNeededRibbon(const int, const int, const int);
};

class CBox {
public:
	explicit CBox(const std::string &dimension);
	int a, b, c;
};

#endif // _CSOLUTION_H_
