#ifndef _CCOMMANDPARSER_H_
#define _CCOMMANDPARSER_H_

#include "CCommand.h"
#include "CPoint.h"
#include <string>

class CCommandParser {
public:
	explicit CCommandParser(const std::string &_command);
	CCommand getCommand();

private:
	ECommand getCommandFromString();
	CPoint getStartingPoint();
	CPoint getEndingPoint();

	const std::string fullCommand;

};



#endif // _CCOMMANDPARSER_H_
