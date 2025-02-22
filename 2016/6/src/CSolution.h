#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <string>
#include <vector>
class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	std::string getResultPart1();
	std::string getResultPart2();
private:
	std::vector<std::string> data{};
	std::string result1{};
	std::string result2{};

};

#endif // _CSOLUTION_H_
