#pragma once

#include "Phix.h"
#include "Token.h"
#include "Lexer.h"
#include "IErrorProne.h"

class Lexer : IErrorProne {

public:
	char* Text;
	int Pos = 0;
	PChar* CurrentChar;

	int Advance();
	int SkipWhitespace();
	int Number(float& num);
	int NextToken(Token& token);

	Lexer(char* text) : Text(text) { CurrentChar = new PChar(Text[Pos]); };
	~Lexer() {
		delete CurrentChar;
	}
};

