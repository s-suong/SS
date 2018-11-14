#include "PrecondViolatedExcep.h"

PrecondViolatedExcep::PrecondViolatedExcep(const string& msg)
	: logic_error("Precondition Violated Exception: " + msg)
{
}
