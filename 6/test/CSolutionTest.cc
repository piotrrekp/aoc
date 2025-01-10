#include <bitset>
#include <gtest/gtest.h>
#include <numeric>
#include <regex>

#include "../src/CSolution.h"

class CTestData {
public:
	CTestData(const std::string &path, const int expected) :
	mCommand(path), mExpected(expected) {};
	std::string command() const { return mCommand; }
	int getExpected() const {return mExpected; }
	friend std::ostream& operator<<(std::ostream &os, const CTestData &obj) {
		os << "command \"" << obj.command() << "\" should result with expeced = " << obj.getExpected();
		return os;
	}
private:
	const std::string mCommand;
	const int mExpected;

};

class CSolutionTester : public CSolution, public testing::TestWithParam<CTestData> {};

std::vector<CTestData> testingData{
	CTestData("turn on 0,0 throught 999,999", LIGHTS_SIZE*LIGHTS_SIZE),
	CTestData("turn on 0,0 throught 999,0", LIGHTS_SIZE),
	CTestData("toggle 0,0 throught 999,0", LIGHTS_SIZE),

};

INSTANTIATE_TEST_CASE_P(, CSolutionTester, testing::ValuesIn(testingData));

TEST_P(CSolutionTester, check) {
	command(GetParam().command());
	ASSERT_EQ(getTurnedLights(), GetParam().getExpected());
}

TEST(commandParser, parseCommandTurnOn) {
	CCommandParser parser("turn on 1,2 throught 3,4");
	CCommand result = parser.getCommand();
	ASSERT_EQ(result.getCommand(), ECommand::TURN_ON);
	ASSERT_EQ(result.getStart(), CPoint(1, 2));
	ASSERT_EQ(result.getEnd(), CPoint(3, 4));
}


TEST(commandParser, parseCommandTurnOff) {
	CCommandParser parser("turn off 100,200 throught 999,999");
	CCommand result = parser.getCommand();
	ASSERT_EQ(result.getCommand(), ECommand::TURN_OFF);
	ASSERT_EQ(result.getStart(), CPoint(100, 200));
	ASSERT_EQ(result.getEnd(), CPoint(999, 999));
}

TEST(commandParser, parseCommandToggle) {
	CCommandParser parser("toggle 100,0 throught 100,69");
	CCommand result = parser.getCommand();
	ASSERT_EQ(result.getCommand(), ECommand::TOGGLE);
	ASSERT_EQ(result.getStart(), CPoint(100, 0));
	ASSERT_EQ(result.getEnd(), CPoint(100, 69));
}

TEST(lights, noLightlitWhenStart) {
	CLights light;
	ASSERT_EQ(light.getLit(), 0);
}


TEST(lights, turnOnSingleLight) {
	CLights light;
	CCommand command{ECommand::TURN_ON, CPoint(0,0), CPoint(0,0)};
	light.execute(command);
	ASSERT_EQ(light.getLit(), 1);
}


TEST(lights, turnOnSingleLightAndTurnThemOff) {
	CLights light;
	CCommand commandON{ECommand::TURN_ON, CPoint(0,0), CPoint(0,0)};

	light.execute(commandON);
	CCommand commandOFF{ECommand::TURN_OFF, CPoint(0,0), CPoint(0,0)};
	light.execute(commandOFF);
	ASSERT_EQ(light.getLit(), 0);
}

TEST(lighs, part2) {
	CLights lights;
	CCommand commandON{ECommand::TURN_ON, CPoint(0,0), CPoint(0,0)};
	lights.execute2(commandON);
	ASSERT_EQ(lights.getLit(), 1);
	CCommand commandToggle{ECommand::TOGGLE, CPoint(0,0), CPoint(0,0)};
	lights.execute2(commandToggle);
	ASSERT_EQ(lights.getLit(), 3);
	lights.execute2(commandToggle);
	ASSERT_EQ(lights.getLit(), 5);
	CCommand commandOff{ECommand::TURN_OFF, CPoint(0,0), CPoint(0,0)};
	lights.execute2(commandOff);
	ASSERT_EQ(lights.getLit(), 4);
	lights.execute2(commandOff);
	ASSERT_EQ(lights.getLit(), 3);
	lights.execute2(commandOff);
	ASSERT_EQ(lights.getLit(), 2);
	lights.execute2(commandOff);
	lights.execute2(commandOff);
	ASSERT_EQ(lights.getLit(), 0);
	lights.execute2(commandOff);
	ASSERT_EQ(lights.getLit(), 0);


}

