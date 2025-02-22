#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <array>
#include <map>
#include <string>
#include <vector>

const std::array<std::array<int, 3>, 3> SIMPLE_KEYBOARD = {{{{1,2,3}}, {{4,5,6}}, {{7,8,9}}}};
const std::array<std::string, 7> COMPLEX_KEYBOARD = {{
	{"XXXXXXX"},
	{"XXX1XXX"},
	{"XX234XX"},
	{"X56789X"},
	{"XXABCXX"},
	{"XXXDXXX"},
	{"XXXXXXX"}
}};

const std::map<char, std::pair<int, int>> MOVE {
	{'U', {-1, 0}},
	{'D', {1, 0}},
	{'R', {0, 1}},
	{'L', {0, -1}}
};


class CSolution {
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	std::string getResultPart2();
private:
	void move_simple(const std::pair<int, int> &direction);
	void move_complex(const std::pair<int, int> &direction);
	std::pair<int, int> currentPoint_simple{1, 1};
	std::pair<int, int> currentPoint_complex{3, 1};
	std::vector<std::string> data{};
	int result1{};
	std::string result2{""};

};

#endif // _CSOLUTION_H_
