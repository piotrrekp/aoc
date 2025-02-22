#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <string>
#include <vector>
class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();
private:
	std::vector<std::string> data{};
	int result1{};
	int result2{};
	void part1(const std::string &line);
	void part2(const std::string &line);
};

#endif // _CSOLUTION_H_
