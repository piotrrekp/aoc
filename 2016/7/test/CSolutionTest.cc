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

class CSolutionTesterPart1 : public CSolution, public testing::TestWithParam<CSingleLineData> {};

std::vector<CSingleLineData> testingData{
	CSingleLineData("abba[mnop]qrst", 1),
	CSingleLineData("abcd[bddb]xyyx", 0),
	CSingleLineData("aaaa[qwer]tyui", 0),
	CSingleLineData("ioxxoj[asdfgh]zxcvbn", 1),
	CSingleLineData("abba", 1),
	CSingleLineData("asdadsabbadasdsa", 1),
	CSingleLineData("asdadsabdadasdsa", 0),
	CSingleLineData("zxcvqwezyyz", 1),
	CSingleLineData("zxcv[qwe]zyyz", 1),
	CSingleLineData("zxcv[abba]zyyz", 0),
	CSingleLineData("zxcv[asd]zyyz[xyyx]", 0),
};

INSTANTIATE_TEST_CASE_P(, CSolutionTesterPart1, testing::ValuesIn(testingData));

TEST_P(CSolutionTesterPart1, check) {
	setData({GetParam().getData()});
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}


class CSolutionTesterPart2 : public CSolution, public testing::TestWithParam<CSingleLineData> {};

std::vector<CSingleLineData> data{
	CSingleLineData("aba[bab]", 1),
};

INSTANTIATE_TEST_CASE_P(, CSolutionTesterPart2, testing::ValuesIn(data));

TEST_P(CSolutionTesterPart2, check) {
	setData({GetParam().getData()});
	solution();
	ASSERT_EQ(getResultPart2(), GetParam().getExpected());
}
