#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <array>
#include <string>
#include <vector>

struct properties {
	int capacity;
	int durability;
	int flavor;
	int texture;
	int calories;
};

class CSolution {
	const int TOTAL = 100;
public:
	void setData(const std::vector<std::string> &_input);
	void solution();
	int getResultPart1();
	int getResultPart2();

private:
	void analyze();
	int maximizeScore();
	void findMaxScore(
		const std::vector<properties> &prop,
		std::vector<int> &allocation,
		std::size_t index,
		int remaining,
		int &max_score);
	void findMaxScoreUnder500kcal(
		const std::vector<properties> &prop,
		std::vector<int> &allocation,
		std::size_t index,
		int remaining,
		int &max_score);
	std::vector<std::string> data{};
	std::vector<properties> ingredients{};
	int result1{};
	int result2{};
};

#endif // _CSOLUTION_H_
