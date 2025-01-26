#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>

#include "../src/CSolution.h"

class CTestData {
public:
	CTestData(const std::string &path, const int expected) :
	mPath(path), mExpected(expected) {};
	std::string getPath() const { return mPath; }
	int getExpected() const {return mExpected; }

	friend std::ostream& operator<<(std::ostream &os, const CTestData &obj) {
		os << "path \"" << obj.getPath() << "\" should result with expeced = " << obj.getExpected();
		return os;
	}
private:
	const std::string mPath;
	const int mExpected;

};

class CSolutionTester : public CSolution, public testing::TestWithParam<CTestData> {};

std::vector<CTestData> testingData{
	CTestData("v", 2),
	CTestData("vv", 3),
	CTestData(">", 2),
	CTestData("<", 2),
	CTestData("^", 2),
	CTestData(">>", 3),
	CTestData("<<", 3),
	CTestData("^^", 3),
	CTestData("^^v", 3),
	CTestData("^v^v", 2),
	CTestData("<<>>", 3),
	CTestData("<><>", 2),
	CTestData("^>v<", 4),
};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	ASSERT_EQ(getVisitedHouses(GetParam().getPath()), GetParam().getExpected());
}

class CSolutionTesterPartTwo : public CSolution, public testing::TestWithParam<CTestData> {};

std::vector<CTestData> testingData_v2{
	CTestData("v", 2),
	CTestData("vv", 2),
	CTestData("^v", 3),
	CTestData("^>v<", 3),
	CTestData("^v^v^v^v^v", 11),
};

INSTANTIATE_TEST_CASE_P(, CSolutionTesterPartTwo, testing::ValuesIn(testingData_v2));

TEST_P(CSolutionTesterPartTwo, check) {
	ASSERT_EQ(getVisitedHouses_v2(GetParam().getPath()), GetParam().getExpected());
}

