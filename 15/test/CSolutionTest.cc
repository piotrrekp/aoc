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
	CMultiData({"Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3"}, 1200),
	CMultiData({
		"Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8"}, 3600),
	CMultiData({
		"Butterscotch: capacity -1, durability -2, flavor 6, texture 3, calories 8",
		"Cinnamon: capacity 2, durability 3, flavor -2, texture -1, calories 3"}, 62842880),
	CMultiData({
		"Sprinkles: capacity 2, durability 0, flavor -2, texture 0, calories 3",
		"Butterscotch: capacity 0, durability 5, flavor -3, texture 0, calories 3",
		"Chocolate: capacity 0, durability 0, flavor 5, texture -1, calories 8",
		"Candy: capacity 0, durability -1, flavor 0, texture 5, calories 8"}, 21367368)
	};

INSTANTIATE_TEST_CASE_P(, CSolutionMultiTester, testing::ValuesIn(multiTest));

TEST_P(CSolutionMultiTester, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}
