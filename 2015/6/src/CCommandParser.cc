#include "CCommandParser.h"
#include "CCommand.h"
#include "CPoint.h"

#include <iostream>
#include <regex>

CCommandParser::CCommandParser(const std::string &_command) : fullCommand(_command) {}


ECommand CCommandParser::getCommandFromString() {
	std::regex pattern("(turn on)|(turn off)|(toggle)");
	std::smatch match;
	std::regex_search(fullCommand.begin(), fullCommand.end(), match, pattern);
	if (match.str() == "turn on") {
		return ECommand::TURN_ON;
	} else if (match.str() == "turn off") {
		return ECommand::TURN_OFF;
	} else if (match.str() == "toggle") {
		return ECommand::TOGGLE;
	}
	return ECommand::UNKNOWN;
}

CPoint CCommandParser::getStartingPoint() {
	std::regex pattern("(\\d{1,3}),(\\d{1,3})");
	std::smatch match;
	std::regex_search(fullCommand.begin(), fullCommand.end(), match, pattern);

	return CPoint(std::stoi(match[1]), std::stoi(match[2]));
}

CPoint CCommandParser::getEndingPoint() {
	std::regex pattern(R"((.*) (\d{1,3}),(\d{1,3}))");
	std::smatch match;
	std::regex_search(fullCommand.begin(), fullCommand.end(), match, pattern);

	return CPoint(std::stoi(match[2]), std::stoi(match[3]));
}

CCommand CCommandParser::getCommand() {
	return CCommand{
		getCommandFromString(),
		getStartingPoint(),
		getEndingPoint()};
}
