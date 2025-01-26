#include <gtest/gtest.h>
#include <numeric>
#include <sstream>
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
	CMultiData(const std::string &_description, const std::vector<std::string> &_input, const int expected) :
	description(_description), data(_input), mExpected(expected) {};
	
	std::vector<std::string> getData() const { return data; }

	int getExpected() const {return mExpected; }


	friend std::ostream& operator<<(std::ostream &os, const CMultiData &obj) {
		os << obj.getDescription();
		return os;
	}	
	std::string getDescription() const {
		return description;
	}

	std::string getDetail() const {
		auto vect = std::accumulate(std::next(data.begin()), data.end(), *data.begin(), [](std::string output, std::string x) {return output + ", " + x;});
		std::stringstream os;
		os << "input: \"" << vect << "\" should result with expeced = " << mExpected;
		return os.str();
	}

private:
	const std::string description;
	const std::vector<std::string > data;
	const int mExpected;

};


class CSolutionTester : public CSolution, public testing::TestWithParam<CSingleLineData> {};

std::vector<CSingleLineData> testingData{

};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	ASSERT_EQ(true, true);
}



class CSolutionMultiTester : public CSolution, public testing::TestWithParam<CMultiData> {};

std::vector<CMultiData> multiTest{
	CMultiData("simplest double gain" ,{
		"Alice would gain 1 happiness units by sitting next to Bob.",
		"Bob would gain 2 happiness units by sitting next to Alice.",
	}, 3),
	CMultiData("simplest triple gain" ,{
		"Alice would gain 1 happiness units by sitting next to Bob.",
		"Alice would gain 1 happiness units by sitting next to Piotr.",
		"Piotr would gain 1 happiness units by sitting next to Alice.",
		"Piotr would gain 1 happiness units by sitting next to Bob.",
		"Bob would gain 1 happiness units by sitting next to Alice.",
		"Bob would gain 1 happiness units by sitting next to Piotr.",
	}, 6),
	CMultiData("full example", { 
		"Alice would gain 54 happiness units by sitting next to Bob.",
		"Alice would lose 79 happiness units by sitting next to Carol.",
		"Alice would lose 2 happiness units by sitting next to David.",
		"Bob would gain 83 happiness units by sitting next to Alice.",
		"Bob would lose 7 happiness units by sitting next to Carol.",
		"Bob would lose 63 happiness units by sitting next to David.",
		"Carol would lose 62 happiness units by sitting next to Alice.",
		"Carol would gain 60 happiness units by sitting next to Bob.",
		"Carol would gain 55 happiness units by sitting next to David.",
		"David would gain 46 happiness units by sitting next to Alice.",
		"David would lose 7 happiness units by sitting next to Bob.",
		"David would gain 41 happiness units by sitting next to Carol.",
	}, 330),

};

INSTANTIATE_TEST_CASE_P(, CSolutionMultiTester, testing::ValuesIn(multiTest));

TEST_P(CSolutionMultiTester, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected()) << GetParam().getDetail();
}
