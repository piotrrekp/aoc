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
	CMultiData({"aaaaa-bbb-z-y-x-123[abxyz]"}, 123),
	CMultiData({"totally-real-room-200[decoy]"}, 0),
	CMultiData({
		"aaaaa-bbb-z-y-x-123[abxyz]",
		"a-b-c-d-e-f-g-h-987[abcde]",
		"not-a-real-room-404[oarel]",
		"totally-real-room-200[decoy]"
	}, 1514),

};

INSTANTIATE_TEST_CASE_P(, CSolutionMultiTester, testing::ValuesIn(multiTest));

TEST_P(CSolutionMultiTester, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}

TEST(secondPart, from_example) {
	CSolution sol;
	ASSERT_EQ(sol.analyzePart2("qzmt-zixmtkozy-ivhz", 343), "very encrypted name");

}


TEST(secondPart, case1) {
	CSolution sol;
	ASSERT_EQ(sol.analyzePart2("a", 1), "b");

}

TEST(secondPart, case2) {
	CSolution sol;
	ASSERT_EQ(sol.analyzePart2("aa", 1), "bb");
}

TEST(secondPart, case3) {
	CSolution sol;
	ASSERT_EQ(sol.analyzePart2("z", 1), "a");

}

TEST(secondPart, case4) {
	CSolution sol;
	ASSERT_EQ(sol.analyzePart2("z", 343), "e");

}
