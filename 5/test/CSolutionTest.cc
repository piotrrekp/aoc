#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"

class CTestData {
public:
	CTestData(const std::vector<std::string> &path, const int expected) :
	mInput(path), mExpected(expected) {};
	std::vector<std::string> getInput() const { return mInput; }
	int getExpected() const {return mExpected; }
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

};

class CSolutionTester : public CSolution, public testing::TestWithParam<CTestData> {};

std::vector<CTestData> testingData{
	CTestData({""}, 0),
	CTestData({"axxx"}, 0),
	CTestData({"axra"}, 0),
	CTestData({"axxaxa"}, 1),
	CTestData({"axexxa"}, 1),
	CTestData({"axeqxa"}, 0),
	CTestData({"axeqxa", "ggaaa"}, 1),
	CTestData({"cdaxxaxa"}, 0),
	CTestData({"abaxxaxa"}, 0),
	CTestData({"xyaxxaxa"}, 0),
	CTestData({"pqaxxaxa"}, 0),
	CTestData({"ugknbfddgicrmopn"}, 1),
	CTestData({"jchzalrnumimnmhp"}, 0),
	CTestData({"haegwjzuvuyypxyu"}, 0),
	CTestData({"dvszwmarrgswjxmb"}, 0),

};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	setData(GetParam().getInput());
	ASSERT_EQ(getNiceStringCount(), GetParam().getExpected());
}


class CSolutionTesterPartTwo : public CSolution, public testing::TestWithParam<CTestData> {};

std::vector<CTestData> testingDataPartTwo{
	CTestData({"ieodomkazucvgmuy"}, 0),
	CTestData({"uurcxstgmygtbstg"}, 0),
	CTestData({"aba"}, 0),
	CTestData({"aaa"}, 0),
	CTestData({"xxyxx"}, 1),
	CTestData({"qjhvhtzxzqqjkmpb"}, 1),

};

INSTANTIATE_TEST_CASE_P(, CSolutionTesterPartTwo, testing::ValuesIn(testingDataPartTwo));

TEST_P(CSolutionTesterPartTwo, check) {
	setData(GetParam().getInput());
	ASSERT_EQ(getNiceStringCountPartTwo(), GetParam().getExpected());
}

