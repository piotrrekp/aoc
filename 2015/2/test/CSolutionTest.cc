#include <gtest/gtest.h>
#include "../src/CSolution.h"

class CSolutionTester : public CSolution, public testing::Test {};

TEST_F(CSolutionTester, getNeededSurface) {
	ASSERT_EQ(getNeededSurface(1,1,1), 7);
}

TEST_F(CSolutionTester, getNeededSurface2) {
	ASSERT_EQ(getNeededSurface(2,3,4), 58);
}

TEST_F(CSolutionTester, getNeededSurface3) {
	ASSERT_EQ(getNeededSurface(1,1,10), 43);
}

TEST_F(CSolutionTester, getTotalNeededSurface) {
	std::vector<std::string> vList = {"1x1x1"};
	ASSERT_EQ(getTotalNeededSurface(vList), 7);
}

TEST_F(CSolutionTester, getTotalNeededSurface_multipleLine) {
	std::vector<std::string> vList = {"1x1x1", "2x3x4", "1x1x10"};
	ASSERT_EQ(getTotalNeededSurface(vList), 108);
}

TEST_F(CSolutionTester, getTotalRibbon_1) {
	std::vector<std::string> vList = {"2x3x4"};
	ASSERT_EQ(getTotalRibbonNeeded(vList), 34);

}
