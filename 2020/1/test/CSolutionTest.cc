#include <gtest/gtest.h>

#include "../src/CSolution.h"

TEST(example, fromSite) {
	std::vector<int> input{1721, 979,366,299,675,1456};
	CSolution sol;
	ASSERT_EQ(sol.partOne(input, 2020), 514579);
}

TEST(simple, partTwo) {
	CSolution sol;
	ASSERT_EQ(sol.partTwo({3,2,1}, 6), 6);
}

TEST(simple, partTwo_case1) {
	CSolution sol;
	ASSERT_EQ(sol.partTwo({5,4,3,2,1}, 10), 20);
}
TEST(simple, partTwo_case2) {
	CSolution sol;
	ASSERT_EQ(sol.partTwo({1,2,3,4,5}, 10), 20);
}

TEST(complex, partTwo) {
	CSolution sol;
	ASSERT_EQ(sol.partTwo({1721, 979,366,299,675,1456}, 2020), 241861950);
}
