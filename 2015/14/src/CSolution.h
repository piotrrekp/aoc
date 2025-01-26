#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <map>
#include <string>
#include <vector>
class CSolution {
	struct raindeerParam {
		std::string name;
		int speed;
		int duration;
		int rest;
		raindeerParam(const std::string &_n, const int _s, const int _d, const int _r) : 
			name(_n), speed(_s), duration(_d), rest(_r) {}
	};
public:
	void setData(const std::vector<std::string> &_input);
	void solution(const int time);
	int getResultPart1();
	int getResultPart2();
private:
	void solvePart2(const int time);
	void getMaxDistance(const int time);
	void analyze(const std::string &line);
	std::vector<std::string> data{};
	int result1{};
	int result2{};
	std::vector<raindeerParam> param;
	std::map<std::string, int> scoreboard;

};

#endif // _CSOLUTION_H_
