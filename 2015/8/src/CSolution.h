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
	int analyze(const std::string &_line);
	int partTwo(const std::string &_line);
	std::string removeOutherQuote(const std::string &_line);

	std::vector<std::string> data{};
	int result1{};
	int result2{};

};

#endif // _CSOLUTION_H_
