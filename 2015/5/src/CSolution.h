#ifndef _CSOLUTION_H_
#define _CSOLUTION_H_

#include <list>
#include <string>
#include <vector>

class CSolution {
	const std::string VOWELS = "aeiou";
	const std::list<std::string> EXCLUDED{"ab", "cd", "pq", "xy"};
public:
	void setData(const std::vector<std::string> &data);
	int getNiceStringCount();
	int getNiceStringCountPartTwo();

	bool hasPairWithOneLetterBetween(const std::string &text);
	bool hasAtLeastTwicePair(const std::string &text);

private:
	bool hasAtLeastOneLetterTwiceInRow(const std::string &text);
	bool hasAtLeast3vowels(const std::string &text);
	bool notContainExcludedStrings(const std::string &text);

	std::vector<std::string> mData;

};

#endif // _CSOLUTION_H_
