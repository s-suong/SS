#include "NotFoundException.h"

NotFoundException::NotFoundException(const string& msg)
	: exception("Target not found: " + msg);
{
}