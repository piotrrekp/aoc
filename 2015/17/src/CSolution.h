#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <string>
#include <vector>
class CSolution {
public:
	void setData(const std::vector<int> &_input);
	int solvePart1(const int volume);
	int solvePart2(const int volume);
private:
	std::vector<int> data{};
	std::vector<std::vector<int>> possibleSolution{};

};

#endif // _CSOLUTION_H_
