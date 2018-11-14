#pragma once
#include <stdexcept>
#include <string>

using namespace std;

class PrecondViolatedExcep: public logic_error
{
public:
	PrecondViolatedExcep(const string& msg = "");
};

