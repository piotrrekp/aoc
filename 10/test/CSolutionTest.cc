#include <gtest/gtest.h>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"

class CSingleLineData {
public:
	CSingleLineData(const std::string &_input, const int numberOfItearation, const std::string expected) :
	input(_input), iteration(numberOfItearation), mExpected(expected) {};
	std::string getData() const { return input; }
	std::string getExpected() const {return mExpected; }
	int getIteration() const {return iteration; }
	friend std::ostream& operator<<(std::ostream &os, const CSingleLineData &obj) {
		os << "_input \"" <<  obj.getData() << "\" after " 
			<< obj.getIteration() <<" iteration should result with expeced = " << obj.getExpected();
		return os;
	}
private:
	const std::string input;
	const int iteration;
	const std::string mExpected;

};



class CSolutionTester : public CSolution, public testing::TestWithParam<CSingleLineData> {};

std::vector<CSingleLineData> testingData{
	CSingleLineData("1", 1, "11"),
	CSingleLineData("11", 1, "21"),
	CSingleLineData("21", 1, "1211"),
	CSingleLineData("1211", 1, "111221"),
	CSingleLineData("111221", 1, "312211"),
	CSingleLineData("1", 2, "21"),
	CSingleLineData("1", 3, "1211"),
	CSingleLineData("1", 4, "111221"),
	CSingleLineData("1", 5, "312211"),
};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	solution(GetParam().getData(), GetParam().getIteration());
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}

