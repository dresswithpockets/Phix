#pragma once

#include "typedefs.h"

struct PChar {
	char Value;

	operator char() { return Value; }

	bool IsWhiteSpace();
	bool IsDigit();
	bool IsOperator();

	char* ToString();

	PChar() : Value('\0') {};
	PChar(char val) : Value(val) {};
};

