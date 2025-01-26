#include <cstdio>
#include <fstream>
#include <gtest/gtest.h>
#include <iterator>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"

TEST(CSolutionE2ETest, fromFile) {
	const std::string pathToFile = "../input/test";
	std::vector<std::string> input;
	std::string line;
	std::fstream file(pathToFile);
	while(getline(file, line)) {
		input.push_back(line);
	}
	file.close();
	CSolution sol;
	sol.setData(input);
	ASSERT_EQ(sol.getResultPart1(), 605);
}

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

class CSolutionMultiTester : public CSolution, public testing::TestWithParam<CMultiData> {};

std::vector<CMultiData> multiTest{
	CMultiData({"a to b = 1"}, 1),

};

INSTANTIATE_TEST_CASE_P(, CSolutionMultiTester, testing::ValuesIn(multiTest));

TEST_P(CSolutionMultiTester, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}


TEST(tree, create) {
	Tree tree("a");
	tree.buildTree({"a", "b"}, {{{"a","b"}, 1}});
	
	ASSERT_EQ(tree.getTree(), "a - b\n");
	
}

