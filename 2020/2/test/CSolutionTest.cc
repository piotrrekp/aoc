#include <gtest/gtest.h>
#include <vector>

#include "../src/CSolution.h"

TEST(partOne, fromSite) {
	const std::vector<std::string> input = {
		"1-3 a: abcde",
		"1-3 b: cdefg",
		"2-19 c: cccccccc",
		"12-19 d: dddddddddddd"
	};
	CSolution sol;
	ASSERT_EQ(sol.partOne(input), 3);

}

TEST(partOne, case_1) {
	const std::vector<std::string> input = {
		"12-19 d: dddddddddddd"
	};
	CSolution sol;
	ASSERT_EQ(sol.partOne(input), 1);

}

TEST(partOne, case_2) {
	const std::vector<std::string> input = {
		"1-2 z: zz"
	};
	CSolution sol;
	ASSERT_EQ(sol.partOne(input), 1);

}

TEST(partOne, case_3) {
	const std::vector<std::string> input = {
		"1-2 z: zzz"
	};
	CSolution sol;
	ASSERT_EQ(sol.partOne(input), 0);
}

TEST(partTwo, fromSite) {
	const std::vector<std::string> input = {
		"1-3 a: abcde",
		"1-3 b: cdefg",
		"2-9 c: ccccccccc",
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 1);
}

TEST(partTwo, case_1) {
	const std::vector<std::string> input = {
		"1-3 b: cdefg",
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 0);
}

TEST(partTwo, case_2) {
	const std::vector<std::string> input = {
		"1-3 a: abcde",
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 1);
}

TEST(partTwo, case_3) {
	const std::vector<std::string> input = {
		"2-9 c: ccccccccc",
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 0);
}

TEST(partTwo, case_4) {
	const std::vector<std::string> input = {
		"2-9 z: aaaaaaaaaaaaa",
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 0);
}

TEST(partTwo, case_5) {
	const std::vector<std::string> input = {
		"2-19 a: aaaaaa",
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 1);
}

TEST(partTwo, case_6) {
	const std::vector<std::string> input = {
		"12-19 a: aaaaaa",
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 0);
}

TEST(from_input, case_1) {
	const std::vector<std::string> input = {
		"1-5 k: kkkkhkkkkkkkkkk"
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 1);
}

TEST(from_input, case_2) {
	const std::vector<std::string> input = {
		"5-6 x: xqftxz"
	};
	CSolution sol;
	ASSERT_EQ(sol.partTwo(input), 1);
}
