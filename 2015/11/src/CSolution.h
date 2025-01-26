#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <string>
#include <vector>


std::string &operator++(std::string &input);
std::string operator++(std::string &input, int);

class CSolution {
public:
	void solution(const std::string &input);
	std::string getResultPart1();
	int getResultPart2();
private:
	std::vector<std::string> data{};
	bool checkStraightAtLeastThreeLetters(const std::string &input);
	bool checkExcluded(const std::string &input);
	bool checkPairs(const std::string &input);
	std::string result1{""};
	int result2{};

};

#endif // _CSOLUTION_H_
