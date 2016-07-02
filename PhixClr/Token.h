#pragma once

#include "Phix.h"

enum TokenType {
	NUMBER = 0,
	OPERATOR,
	END
};

class Token
{
public:
	TokenType Type;
	void* Value;

	Token(TokenType type, void* value) {
		Type = type;
		Value = value;
	}
	~Token() {};
};

