#include <gtest/gtest.h>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"

struct singleLineData {
	const std::string input;
	const int time;
	const int expected;
	singleLineData(const std::string &s, const int t, const int e) :
		input(s), time(t), expected(e) {}
	friend std::ostream& operator<<(std::ostream &os, const singleLineData &obj) {
		os << "_input \"" << obj.input << "\" should result with expeced = " << obj.expected;
		return os;
	}
};

struct multiLineData {
	const std::vector<std::string> input;
	const int time;
	const int expected;
	multiLineData(const std::vector<std::string> &s, const int t, const int e) :
		input(s), time(t), expected(e) {}
	friend std::ostream& operator<<(std::ostream &os, const multiLineData &obj) {
		auto folded = obj.input.at(0).substr(0, 10) + std::string{"..."};
		os << "_input \"" << folded << "\" after " << obj.time << "s should result with = " << obj.expected;
		return os;
	}
};

class CSolutionTester : public CSolution, public testing::TestWithParam<singleLineData> {};

std::vector<singleLineData> testingData{
	singleLineData("Comnes fly 14 km/s for 10 seconds, but then must rest for 127 seconds.", 10, 140),
	singleLineData("dasa 14 for 10 secondsfor 127 seconds.", 20, 140),
	singleLineData("asda 10 for 10 secondsfor 127 seconds.", 1, 10),
	singleLineData("a sads 14 for 10 secondsfor 127 seconds.", 1, 14),
	singleLineData("a 16 for 11 secondsfor 162 seconds.", 1, 16),
	singleLineData("a 14 for 10 secondsfor 127 seconds.", 10, 140),
	singleLineData("a 16 for 11 secondsfor 162 seconds.", 10, 160),
	singleLineData("a 14 for 10 secondsfor 127 seconds.", 11, 140),
	singleLineData("a 16 for 11 secondsfor 162 seconds.", 11, 176),
	singleLineData("a 14 for 10 secondsfor 127 seconds.", 138, 154),
	singleLineData("a 16 for 11 secondsfor 162 seconds.", 138, 176),
	singleLineData("a 14 for 10 secondsfor 127 seconds.", 1000, 1120),
	singleLineData("a 16 for 11 secondsfor 162 seconds.", 1000, 1056),
};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	setData({GetParam().input});
	solution(GetParam().time);
	ASSERT_EQ(getResultPart1(), GetParam().expected);
}



class CSolutionMultiTester : public CSolution, public testing::TestWithParam<multiLineData> {};

std::vector<multiLineData> multiTest{
	multiLineData(
		{"Comnes fly 14 km/s for 10 seconds, but then must rest for 127 seconds."
		}, 
		2, 2),
	multiLineData({
			"b 14 for 5 secondsfor 10 seconds.",
			"a 16 for 3 secondsfor 10 seconds.",
		}, 
		1, 1),
	multiLineData({
			"b 14 for 5 secondsfor 10 seconds.",
			"a 16 for 3 secondsfor 10 seconds.",
		}, 
		3, 3),
	multiLineData({
			"b 14 for 5 secondsfor 10 seconds.",
			"a 16 for 3 secondsfor 10 seconds.",
		}, 
		4, 3),
	multiLineData({
			"b 14 for 5 secondsfor 10 seconds.",
			"a 16 for 3 secondsfor 10 seconds.",
		}, 
		5, 3),
	multiLineData({
			"b 14 for 5 secondsfor 10 seconds.",
			"a 16 for 3 secondsfor 10 seconds.",
		}, 
		6, 3),
	multiLineData({
			"b 14 for 5 secondsfor 10 seconds.",
			"a 16 for 3 secondsfor 10 seconds.",
		}, 
		6, 3),
	multiLineData({
			"b 14 for 5 secondsfor 10 seconds.",
			"a 16 for 3 secondsfor 10 seconds.",
		}, 
		7, 3),
};

INSTANTIATE_TEST_CASE_P(, CSolutionMultiTester, testing::ValuesIn(multiTest));

TEST_P(CSolutionMultiTester, check) {
	setData({GetParam().input});
	solution(GetParam().time);
	ASSERT_EQ(getResultPart2(), GetParam().expected);

	ASSERT_EQ(true, true);
}
