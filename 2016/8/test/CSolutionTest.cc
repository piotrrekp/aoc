#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"


TEST(display, createDisplay) {
	CDisplay dis(4,3);
	ASSERT_EQ(dis.getLitPixelCount(), 0);
}

TEST(display, rect_1) {
	CDisplay dis(4,3);
	dis.rect(2, 1);
	ASSERT_EQ(dis.getLitPixelCount(), 2);
}

TEST(display, rect_2) {
	CDisplay dis(4,3);
	dis.rect(5, 7);
	ASSERT_EQ(dis.getLitPixelCount(), 12);
}

TEST(display, rotate_row_1) {
	CDisplay dis(7, 5);
	dis.rect(1, 1);
	ASSERT_EQ(dis.getLitPixelCount(), 1);
	ASSERT_TRUE(dis.getPixel(0, 0));
	ASSERT_FALSE(dis.getPixel(1, 0 ));

	dis.rotateRow(0, 1);
	ASSERT_TRUE(dis.getPixel(0, 1));
	ASSERT_FALSE(dis.getPixel(0, 0));
}

TEST(display, rotate_row_2) {
	CDisplay dis(5, 5);
	dis.rect(1, 3);
	ASSERT_EQ(dis.getLitPixelCount(), 3);

	dis.rotateRow(1, 6);
	ASSERT_TRUE(dis.getPixel(1, 1));
	ASSERT_FALSE(dis.getPixel(1, 0));
}

TEST(display, rotate_column_1) {
	CDisplay dis(5, 5);
	dis.rect(1, 1);

	dis.rotateColumn(0, 2);
	ASSERT_TRUE(dis.getPixel(2, 0));
	ASSERT_FALSE(dis.getPixel(0, 0));
}

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
	CMultiData({"rect 3x2", "rotate column x=5 by 8"}, 6)

};

INSTANTIATE_TEST_CASE_P(, CSolutionMultiTester, testing::ValuesIn(multiTest));

TEST_P(CSolutionMultiTester, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}


TEST(rotation, test) { std::vector<bool> a{0,0,1,0,0};
	GTEST_SKIP();
	std::cout << "0 : "; for ( const auto &x : a) {std::cout << (x?'X':'.') << " ";}std::cout<<'\n';
	for (auto i = 1; i < 20; ++i) {
		std::rotate(a.rbegin(), a.rbegin() + 1, a.rend());
		std::cout << i << " : "; for ( const auto &x : a) {std::cout << (x?'X':'.') << " ";}std::cout<<'\n';
	}
}
