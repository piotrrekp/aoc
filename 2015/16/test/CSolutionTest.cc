#include <gtest/gtest-param-test.h>
#include <gtest/gtest.h>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"

struct testData {
	std::vector<std::string> input;
	int expected;

	testData(const std::vector<std::string> &_input, const bool &_expected)
		: input(_input), expected(_expected) {}

	friend std::ostream& operator<<(std::ostream &os, const testData &obj) {
		std::string inp = std::accumulate(std::next(obj.input.begin()), obj.input.end(), *obj.input.begin(),
			[](auto res, const auto &x) {return res + ", " + x;});
		os << "_input \"" <<  inp << "\" should result with expeced = " << obj.expected;
		return os;
	}
};

class CSolutionTester : public CSolution, public ::testing::TestWithParam<testData> {
};

INSTANTIATE_TEST_SUITE_P(, CSolutionTester, ::testing::Values(
	testData({"Sue 1: cars: 9, akitas: 3, goldfish: 0"}, 1)
    ));

TEST_P(CSolutionTester, TestName) {
	setData(GetParam().input);
	solution();

	ASSERT_EQ(getResultPart1(), GetParam().expected);
}
