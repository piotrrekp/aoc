#include <cassert>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>

int countFloor(const std::string &atext) {
	int vResult = 0;
	vResult = std::accumulate(atext.begin(), atext.end(), vResult, [](int sum, char x){return sum + (x == '(');});
	vResult = std::accumulate(atext.begin(), atext.end(), vResult, [](int sum, char x){return sum - (x == ')');});
	return vResult;
}

int getBasementPosition(const std::string &atext) {
	int vResult = 0;
	for (std::size_t i = 0; i < atext.size(); ++i) {
		vResult += (atext.at(i) == '(') ? 1 : -1;
		if (vResult < 0) {
			return i + 1;
		}

	}
	return atext.size();
}

int main(int argc, const char **argv) {
	const std::string testCase1 = "(())";
	const std::string testCase2 = "(((()()))";
	const std::string testCase3 = "))(())";
	const std::string testCase4 = "()()))(())";
	assert(countFloor(testCase1) == 0);
	assert(countFloor(testCase2) == 1);
	assert(countFloor(testCase3) == -2);
	assert(countFloor(testCase4) == -2);

	const std::string testCaseSecondPart1 = ")";
	const std::string testCaseSecondPart2 = "(((()()))))";
	assert(getBasementPosition(testCaseSecondPart1) == 1);
	assert(getBasementPosition(testCaseSecondPart2) == 11);
	
	std::fstream vFile(argv[1]);
	std::string line;
	getline(vFile, line);
	std::cout << countFloor(line) << ", " << getBasementPosition(line) << std::endl;

return 0;
}
