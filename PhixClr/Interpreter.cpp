#include "stdafx.h"
#include "Interpreter.h"

char asChar(void* vptr) { return *(char*)vptr; }

int Interpreter::Eat(TokenType type) {

	if (CurrentToken->Type != type) return Error();
	return Lex->NextToken(*CurrentToken);
}

int Interpreter::Factor(float& factor) {
	Token* t = CurrentToken;
	int error = Eat(NUMBER);
	if (!error) factor = *((float*)t->Value);
	return error;
}

int Interpreter::Expression(float& result) {
	int error = Factor(result);
	if (error) return error;

	while (CurrentToken->Type == OPERATOR) {
		Token* t = CurrentToken;
		float next;
		char valAsChar = asChar(t->Value);

		if (asChar(t->Value) == PLUS) {
			error = Factor(next);
			if (error) return error;
			result += next;
		}
		else if (asChar(t->Value) == MINUS) {
			error = Factor(next);
			if (error) return error;
			result -= next;
		}
		else if (asChar(t->Value) == MULTIPLY) {
			error = Factor(next);
			if (error) return error;
			result *= next;
		}
		else if (asChar(t->Value) == DIVIDE) {
			error = Factor(next);
			if (error) return error;
			result /= next;
		}
		else if (asChar(t->Value) == POWER) {
			error = Factor(next);
			if (error) return error;
			result = pow(result, next);
		}
	}

	return Valid();
}