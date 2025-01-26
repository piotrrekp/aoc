#include <gtest/gtest.h>
#include <gtest/internal/gtest-param-util.h>
#include <vector>

#include "../src/CSolution.h"

class CSingleLineData {
public:
	CSingleLineData(const std::string &_input, const std::string &expected) :
	input(_input), mExpected(expected) {};
	std::string getData() const { return input; }
	std::string getExpected() const {return mExpected; }
	friend std::ostream& operator<<(std::ostream &os, const CSingleLineData &obj) {
		os << "_input \"" << obj.getData() << "\" should result with expeced = " << obj.getExpected();
		return os;
	}
private:
	const std::string input;
	const std::string mExpected;

};


class CSolutionTester : public CSolution, public testing::TestWithParam<CSingleLineData> {};

std::vector<CSingleLineData> testingData{
	CSingleLineData("bbaaaa", "bbaabc"),
	CSingleLineData("bbaaa", "bbcdd"),
	CSingleLineData("ccbbz", "ccdee"),
	CSingleLineData("xxx", "aabcc"),
	CSingleLineData("ffggi", "ffghh"),
	CSingleLineData("abcdefgh", "abcdffaa"),
	CSingleLineData("ghijklmn", "ghjaabcc"),

};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	solution(GetParam().getData());
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());

}

TEST(wordincrement, simple5) {
	auto tmp = std::string{"z"};
	++tmp;
	EXPECT_EQ(tmp, "aa");
}

TEST(wordincrement, simple4) {
	auto tmp = std::string{"bzz"};
	++tmp;
	EXPECT_EQ(tmp, "caa");
	tmp++;
	EXPECT_EQ(tmp, "cab");
}
TEST(wordIncrement, simple3) {
	auto tmp = std::string{"az"};
	++tmp;
	EXPECT_EQ(tmp, "ba");
}
TEST(wordIncrement, simple2) {
	auto tmp = std::string{"aa"};
	++tmp;
	EXPECT_EQ(tmp, "ab");
}
TEST(wordIncrement, simple) {
	auto tmp = std::string{"a"};
	++tmp;
	EXPECT_EQ(tmp, "b");
}

TEST(wordIncrement, simple_1) {
	auto tmp = std::string{"b"};
	++tmp;
	EXPECT_EQ(tmp, "c");
}

