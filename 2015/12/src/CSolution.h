#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <string>
#include <vector>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();
private:
	int check(const std::string &line);
	int validate(json js);
	int check2();
	std::vector<std::string> data{};
	int result1{};
	int result2{};

};

#endif // _CSOLUTION_H_
