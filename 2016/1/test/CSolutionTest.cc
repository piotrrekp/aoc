#include <gtest/gtest.h>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"

class CSingleLineData {
public:
	CSingleLineData(const std::string &_input, const int expected) :
	input(_input), mExpected(expected) {};
	std::string getData() const { return input; }
	int getExpected() const {return mExpected; }
	friend std::ostream& operator<<(std::ostream &os, const CSingleLineData &obj) {
		os << "_input \"" << obj.getData() << "\" should result with expeced = " << obj.getExpected();
		return os;
	}
private:
	const std::string input;
	const int mExpected;
};

class CSolutionTester : public CSolution, public testing::TestWithParam<CSingleLineData> {};

std::vector<CSingleLineData> testingData{
	CSingleLineData("R2, L3", 5),
	CSingleLineData("R2, L185", 187),
	CSingleLineData("R185, L2", 187),
	CSingleLineData("R2, L3, R2, L3", 10),
	CSingleLineData("R2, R2, R2", 2),
	CSingleLineData("R5, L5, R5, R3", 12)
};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}

TEST(CSolution, partTwo) {
	CSolution sol;
	sol.setData("R8, R4, R4, R8");
	sol.solution();
	ASSERT_EQ(sol.getResultPart2(), 4);
}
