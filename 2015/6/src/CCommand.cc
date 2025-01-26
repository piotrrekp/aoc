#include "CCommand.h"

CCommand::CCommand(const ECommand &_command, const CPoint &_start, const CPoint &_end)
	: command(_command), start(_start), end(_end) {}

ECommand CCommand::getCommand() const {
	return command;
}

CPoint CCommand::getStart() const {
	return start;
}

CPoint CCommand::getEnd() const {
	return end;

}
