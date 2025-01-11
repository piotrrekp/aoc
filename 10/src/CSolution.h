#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <string>
#include <vector>
class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution(const std::string &_line, const int _iteration);
	std::string getResultPart1();
	int getResultPart2();
private:
	std::string singleLoop(const std::string &_line);
	std::vector<std::string> data{};
	std::string result1{};
	int result2{};

};

#endif // _CSOLUTION_H_
