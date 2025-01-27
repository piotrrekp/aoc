#include <exception>
#include <gtest/gtest.h>
#include <fstream>
#include <limits>
#include <string>
#include <vector>



std::vector<std::string> readInput(const char *aPath) {
	std::fstream file(aPath);
	std::vector<std::string> input;
	std::string line;
	while (getline(file, line)) {
		input.push_back(line);
	}
	file.close();
	return input;
}


int countTrees( std::vector<std::string> &data, const int right = 3, const int down = 1) {
	const int size = data.size();
	const int lenght = data.at(0).size();
	std::pair<int,int> currentPosition{0,0};
	auto trees{0};
	while (currentPosition.first < size - 1) {
		if(lenght > currentPosition.second + right) {
			currentPosition.second += right;
		} else {
			currentPosition.second = ((currentPosition.second + right) % lenght);
		}
		currentPosition.first += down;
		trees += (data[currentPosition.first][currentPosition.second] == '#');
	}
	return trees;
}

TEST(simple_test, case_4) {
	std::vector<std::string> input = {
		"..",
		"##"
	};
	ASSERT_EQ(countTrees(input), 1);
}

TEST(simple_test, case_3) {
	std::vector<std::string> input = {
		"....",
		"...#"
	};
	ASSERT_EQ(countTrees(input), 1);
}

TEST(fromExample,test) {
	auto input = readInput("input/testcase");
	ASSERT_EQ(countTrees(input), 7);
}

TEST(simple_test, case_1) {
	std::vector<std::string> input = {
		"....",
		"...."
	};
	ASSERT_EQ(countTrees(input), 0);
}

TEST(simple_test, case_2) {
	std::vector<std::string> input = {
		"..##",
		".##."
	};
	ASSERT_EQ(countTrees(input), 0);
}

TEST(fromInput,test) {
	auto input = readInput("input/input");
	ASSERT_EQ(countTrees(input), 284);
}

TEST(fromInput, test_partTwo) {
	auto input = readInput("input/input");
	unsigned int ans =
		countTrees(input, 1, 1)
		* countTrees(input, 3, 1)
		* countTrees(input, 5, 1)
		* countTrees(input, 7, 1)
		* countTrees(input, 1, 2);
	ASSERT_EQ(ans, 3510149120);
}


TEST(fromExample, test_partTwo) {
	auto input = readInput("input/testcase");
	auto ans{1};
	ans *= countTrees(input, 1, 1)
		* countTrees(input, 3, 1)
		* countTrees(input, 5, 1)
		* countTrees(input, 7, 1)
		* countTrees(input, 1, 2);
	ASSERT_EQ(ans, 336);
}

TEST(fromExample, test_partTwo_1) {
	auto input = readInput("input/testcase");
	ASSERT_EQ(countTrees(input, 1, 1), 2);
}

TEST(fromExample, test_partTwo_2) {
	auto input = readInput("input/testcase");
	ASSERT_EQ(countTrees(input, 3, 1), 7);
}

TEST(fromExample, test_partTwo_3) {
	auto input = readInput("input/testcase");
	ASSERT_EQ(countTrees(input, 5, 1), 3);
}
TEST(fromExample, test_partTwo_4) {
	auto input = readInput("input/testcase");
	ASSERT_EQ(countTrees(input, 7, 1), 4);
}
TEST(fromExample, test_partTwo_5) {
	auto input = readInput("input/testcase");
	ASSERT_EQ(countTrees(input, 1, 2), 2);
}

