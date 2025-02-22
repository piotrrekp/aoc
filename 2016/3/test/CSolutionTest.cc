#include <gtest/gtest.h>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"

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

class CSolutionMultiTester : public CSolution, public testing::TestWithParam<CMultiData> {};

std::vector<CMultiData> multiTest{
	CMultiData({"5 10 25"}, 0),
	CMultiData({"20 41 648"}, 0),
	CMultiData({"20 41 48"}, 1),

};

INSTANTIATE_TEST_CASE_P(, CSolutionMultiTester, testing::ValuesIn(multiTest));

TEST_P(CSolutionMultiTester, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}

TEST(CSolutionTester, check_case1) {
	CSolution sol;
	sol.setData({"101 200 300", "102, 200 300", "103 800 302"});
	sol.solution();
	ASSERT_EQ(sol.getResultPart2(), 2);
}
