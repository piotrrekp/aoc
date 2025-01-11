#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <vector>
#include "../src/CSolution.h"

class CTestData {
public:
	CTestData(const std::vector<std::string> &path, const std::string &index, const int expected) :
	mInput(path), mIndex(index), mExpected(expected) {};
	std::vector<std::string> getInput() const { return mInput; }
	int getExpected() const {return mExpected; }
	std::string getIndex() const {return mIndex; }

	friend std::ostream& operator<<(std::ostream &os, const CTestData &obj) {
		auto input = obj.getInput();
		auto fold = [](std::string a, std::string b) {
			return a + ", \"" + b; };
		std::string result = std::accumulate(input.begin(), input.end(), std::string(), fold);

		os << "path \"" << result << "\" should result with expected = " << obj.getExpected();
		return os;
	}

private:
	const std::vector<std::string> mInput;
	const int mExpected;
	const std::string mIndex;
	

};

class CSolutionTester : public CSolution, public testing::TestWithParam<CTestData> {};

TEST_P(CSolutionTester, simple) {
	input(GetParam().getInput());
	ASSERT_EQ(getSignalFromWire(GetParam().getIndex()), GetParam().getExpected());

}

std::vector<CTestData> testingData{
	CTestData({"623 -> x23"}, "x23", 623),
	CTestData({"NOT 777 -> x"}, "x", 64758),
	CTestData({"7 OR 10 -> x"}, "x", 15),
	CTestData({"11 OR 96 -> x213x"}, "x213x", 107),
	CTestData({"7 AND 10 -> j23"}, "j23", 2),
	CTestData({"111 RSHIFT 1 -> g1"}, "g1", 55),
	CTestData({"55 LSHIFT 1 -> g1"}, "g1", 110),

};

INSTANTIATE_TEST_CASE_P(simple, CSolutionTester, testing::ValuesIn(testingData));


std::vector<CTestData> moreComplexTestingData {
	CTestData({"123 -> y23g", "y23g -> x"}, "x", 123),
	CTestData({"123 -> y23", "y23 -> x"}, "x", 123),
	CTestData({"123 -> y23", "y23 -> x"}, "x", 123),
	CTestData({"y AND z -> x", "96 -> y", "y -> z"}, "x", 96),
	CTestData({"yy OR z23 -> x", "96 -> yy", "yy -> z23"}, "x", 96),
	CTestData({"yy RSHIFT z23 -> x", "2 -> yy", "yy -> z23"}, "x", 0),
	CTestData({"yy LSHIFT z23 -> x", "2 -> yy", "yy -> z23"}, "x", 8),
	CTestData({"yy96 OR z23 -> x", "11 -> yy96", "96 -> z23"}, "x", 107),
	CTestData({"das11 OR 96 -> x213x","2 -> das11"}, "x213x", 98),
	CTestData({"2 -> ju", "NOT ju -> ja"}, "ja", 65533),
	CTestData({"NOT ju -> ja", "2 -> ju"}, "ja", 65533),

};
INSTANTIATE_TEST_CASE_P(moreComplex, CSolutionTester, testing::ValuesIn(moreComplexTestingData));

