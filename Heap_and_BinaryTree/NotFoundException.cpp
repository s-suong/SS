#include "NotFoundException.h"

NotFoundException::NotFoundException(const string& msg)
	: logic_error("Target not found: " + msg)
{
}