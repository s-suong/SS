#pragma once
#include <stdexcept>
#include <string>

using namespace std;

class NotFoundException : public exception
{
public:
	NotFoundException(const string& msg = "");
};