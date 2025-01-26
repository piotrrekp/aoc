#ifndef _CCOMMAND_H_
#define _CCOMMAND_H_

#include "CPoint.h"

enum class ECommand {
	UNKNOWN,
	TURN_ON,
	TURN_OFF,
	TOGGLE
};

class CCommand {
public:
	CCommand(const ECommand &_command, const CPoint &_start, const CPoint &_end);
	ECommand getCommand() const;
	CPoint getStart() const;
	CPoint getEnd() const;
private:
	const ECommand command;
	const CPoint start, end;
};


#endif // _CCOMMAND_H_
