#include <algorithm>
#include <gtest/gtest.h>
#include <numeric>
#include <stack>
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



class CSolutionMultiTesterPart1 : public CSolution, public testing::TestWithParam<CMultiData> {};
class CSolutionMultiTesterPart2 : public CSolution, public testing::TestWithParam<CMultiData> {};

std::vector<CMultiData> multiTestPart1{
	CMultiData({"[1,2,3]"}, 6),
	CMultiData({"{\"a\":2, \"b\":4}"}, 6),
	CMultiData({"{\"a\":[-1,1]}"}, 0),
	CMultiData({"[-1,{\"a\":1}]"}, 0),
	CMultiData({"[]", "{66, -65}"}, 1),
	CMultiData({"[]", "{66, -65}"}, 1),
	CMultiData({"[1,{\"c\":\"red\",\"b\":2},3]"}, 6),
};

std::vector<CMultiData> multiTestPart2{
	CMultiData({"{\"a\":[\"a\",\"red\",5]}"}, 5),
	CMultiData({"{\"sdada\":\"red\", \"b\": 1}"}, 0),
	CMultiData({"[1,{\"c\":\"red\",\"b\":2},3]"}, 4),
	CMultiData({"{\"d\":\"red\",\"e\":[1,2,3,4],\"f\":5}"}, 0),
	CMultiData({"{\"a\":{\"d\":\"red\"},\"dad\":{\"e\":[1,2,3,4],\"f\":5}}"}, 15),
	CMultiData({"{\"dsa\":{\"x\":[1, 2]}, \"q\":{\"d\":\"red\"},\"daa\":{\"e\":[1,2,3,4],\"f\":5}}"}, 18),
	CMultiData({"{\"o\":1,\"o1\":{\"d\":\"red\",\"iiix\":{\"e\":[1,2,3,4]}},\"f\":5}"}, 6),
	CMultiData({"{\"o\":1,\"o1\":{\"d\":\"red\",\"iiix\":{\"e\":[1,2,3,4]}},\"f\":\"red\"}"}, 0),
	CMultiData({"{\"v\":[1,\"red\",5]}"}, 6),
	CMultiData({"{\"o1\":{\"o2\":{\"o3\":\"red\",\"o4\": 2}, \"o5\":[1,\"red\",5], \"o6\":7, \"o7\":{\"o1\":{\"gf\":4,\"o1\": 78, \"o1\":\"red\", \"o1\":4}, \"o1\":3}}}"}, 16),
	CMultiData({"{\"c\": 42, \"a\": \"blue\", \"b\": \"red\"}"}, 0),

};

INSTANTIATE_TEST_CASE_P(Part1, CSolutionMultiTesterPart1, testing::ValuesIn(multiTestPart1));
INSTANTIATE_TEST_CASE_P(Part2, CSolutionMultiTesterPart2, testing::ValuesIn(multiTestPart2));

TEST_P(CSolutionMultiTesterPart1, check) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart1(), GetParam().getExpected());
}

TEST_P(CSolutionMultiTesterPart2, checkPart2) {
	setData(GetParam().getData());
	solution();
	ASSERT_EQ(getResultPart2(), GetParam().getExpected());
}
