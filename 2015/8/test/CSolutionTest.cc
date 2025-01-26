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

class CMultiData {
public:
	CMultiData(const std::vector<std::string> &_input, const int expected) :
	data(_input), mExpected(expected) {};
	
	std::vector<std::string> getData() const { return data; }

	int getExpected() const {return mExpected; }

	friend std::ostream& operator<<(std::ostream &os, const CMultiData &obj) {
		auto data = obj.getData();
		auto vect = std::accumulate(std::next(data.begin()), data.end(), *data.begin(), [](std::string output, std::string x) {return output + ", " + x;});
		os << "input: \"" << vect << "\" should result with expeced = " << obj.getExpected();
		return os;
	}

private:
	const std::vector<std::string > data;
	const int mExpected;

};


class CSolutionTester : public CSolution, public testing::TestWithParam<CSingleLineData> {};

std::vector<CSingleLineData> testingData{
	CSingleLineData("\"\"" , 2),
	CSingleLineData("\"aaa\\\"aaa\"" , 3),
	CSingleLineData("\"\\x27\"" , 5),
	CSingleLineData("\"\\xff\"" , 5),
	CSingleLineData("\"\\x1f\"" , 5),
	CSingleLineData("\"\\xf1\"" , 5),
	CSingleLineData("\"\\xFF\"" , 5),
	CSingleLineData("\"qt\\x89h\"", 5),
	CSingleLineData("\"qt\\\\xxx89h\"", 3),
	CSingleLineData("\"\\\\\"", 3),
	CSingleLineData("\"\\\\\\\"\"", 4),


};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	setData({GetParam().getData()});
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}



class CSolutionMultiTester : public CSolution, public testing::TestWithParam<CMultiData> {};

std::vector<CMultiData> multiTest{
	CMultiData({"\"\""}, 4),
	CMultiData({"\"aaa\\\"aaa\""}, 6),
	CMultiData({"\"aaa\""}, 4),
	CMultiData({"\"\\x27\""}, 5),

};

INSTANTIATE_TEST_CASE_P(, CSolutionMultiTester, testing::ValuesIn(multiTest));

TEST_P(CSolutionMultiTester, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart2(), GetParam().getExpected());
}
