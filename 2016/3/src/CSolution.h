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
	bool isTriangle(const std::string &data);
	bool isTriangle(const std::vector<int> &data);
	std::vector<std::string> data{};
	int result1{0};
	int result2{0};

};

#endif // _CSOLUTION_H_
