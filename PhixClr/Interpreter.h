#pragma once

#include "stdafx.h"
#include "Phix.h"
#include "Token.h"
#include "Lexer.h"
#include "IErrorProne.h"

const char PLUS = '+';
const char MINUS = '-';
const char MULTIPLY = '*';
const char DIVIDE = '/';
const char POWER = '^';

const char Operators[5] = { PLUS, MINUS, MULTIPLY, DIVIDE, POWER };

class Interpreter : IErrorProne {
public:

	Lexer* Lex;
	Token* CurrentToken;

	Interpreter(Lexer* lex) : Lex(lex) { Lex->NextToken(*CurrentToken); }

	int Eat(TokenType type);
	int Factor(float& factor);
	int Expression(float& result);
};