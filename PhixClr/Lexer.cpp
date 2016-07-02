#include "stdafx.h"
#include "Lexer.h"

int Lexer::Advance() {

	Pos++;
	if (Pos > strlen(Text) - 1) CurrentChar = nullptr;
	else return Error();
	return Valid();
}

int Lexer::SkipWhitespace() {

	while (CurrentChar != nullptr && CurrentChar->IsWhiteSpace()) {
		int error = Advance();
		if (error != Valid()) return error;
	}
	return Valid();
}

int Lexer::Number(float& num) {
	char result[39];

	strcpy(result, "");
	while (CurrentChar != nullptr && (CurrentChar->IsDigit() || *CurrentChar == '.')) {
		strcat(result, &(CurrentChar->Value));
	}

	num = atof(result);

	return Valid();
}

int Lexer::NextToken(Token& token) {

	while (CurrentChar != nullptr) {

		if (CurrentChar->IsWhiteSpace()) {
			SkipWhitespace();
			continue;
		}

		if (CurrentChar->IsDigit()) {
			float num;
			int error = Number(num);
			if (error) return error;

			token = Token(NUMBER, &num);
			return Valid();
		}

		if (CurrentChar->IsOperator()) {

			Token t = Token(OPERATOR, CurrentChar);

			int error = Advance();
			if (error) return error;

			token = t;
			return Valid();
		}

		return Error();

	}

	token = Token(END, nullptr);
	return Valid();
}