#include <gtest/gtest.h>
#include <numeric>
#include <vector>

#include "../src/CSolution.h"

TEST(simple, check) {
	CSolution s;
	s.setData({1,2,3,2});
	ASSERT_EQ(s.solvePart1(4), 2);
}

TEST(complex, firstPart) {
	CSolution s;
	s.setData({5,5,10,15,20});
	ASSERT_EQ(s.solvePart1(25), 4);
}

TEST(complex, secondPart) {
	CSolution s;
	s.setData({5,5,10,15,20});
	ASSERT_EQ(s.solvePart2(25), 3);
}

TEST(simple, secondPart) {
	CSolution s;
	s.setData({5,20});
	ASSERT_EQ(s.solvePart2(25), 1);
}

TEST(simple, secondPart1) {
	CSolution s;
	s.setData({5,5,20});
	ASSERT_EQ(s.solvePart2(25), 2);
}
