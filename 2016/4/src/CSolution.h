#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <string>
#include <string_view>
#include <vector>
class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();
	std::string analyzePart2(const std::string_view &name, const int id);
private:
	void analyzePart1(const std::string_view &name, const int id, const std::string_view &checksum);
	std::vector<std::string> data{};
	int result1{};
	int result2{};

};

#endif // _CSOLUTION_H_
