#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <map>
#include <string>
#include <vector>


class CSolution {
	const std::map<std::string, int> wanted {
		{"children", 3},
		{"cats", 7},
		{"samoyeds", 2},
		{"akitas", 0},
		{"vizslas", 0},
		{"goldfish", 5},
		{"trees", 3},
		{"cars", 2},
		{"pomeranians", 3},
		{"perfumes", 1}
	};
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();
private:
	bool checkWord(const std::string & key, const int value);
	bool checkWordSecondPart(const std::string & key, const int value);
	void analyze(const std::string &line);
	int result1{};
	int result2{};
	bool res1{false};
	bool res2{false};
};

#endif // _CSOLUTION_H_
