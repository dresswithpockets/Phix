#pragma once

#ifndef LENGTH_DEF
#define LENGTH_DEF
#define LENGTH(TEXT) sizeof(TEXT)/sizeof(TEXT[0])
#endif

#include <stdlib.h>
#include <string>

#include "Token.h"
#include "PChar.h"

struct Lexer {

	string text;
	int pos;
	PChar* current_char;

	Lexer(string text) : text(text) {
		pos = 0;
		*current_char = text[pos];
	}

	void advance() {
		pos++;
		if (pos > LENGTH(text) - 1) current_char = nullptr;
		else *current_char = text[pos];
	}

	PChar peek() {
		if (pos + 1 > LENGTH(text) - 1) return '\0';
		else return text[pos];
	}

	PChar peek(int n) {
		if (pos + n > LENGTH(text) - 1) return '\0';
		else return text[pos + n];
	}

	bool peek_forward(string str) {
		int n = str.length();
		for (int i = 0; i < n; i++) {
			if (peek(i) != str[i]) return false;
		}

		return true;
	}

	void skip_whitespace() {
		while (current_char != nullptr && current_char->is_whitespace()) advance();
	}

	token number() {
		string result;
		while (current_char != nullptr && current_char->valid("1234567890.")) {
			result.append(*current_char);
		}

		if (result[result.length() - 1] == '.') result.pop_back();

		return token(NUMBER, atof(result.c_str()));
	}

	token word() {
		string result = "";
		while (current_char != nullptr && current_char->valid("1234567890abcdefghijklmnopABCDEFGHIJKLMNOP_")) {
			result.append(*current_char);
			advance();
		}

		token t = get_kw(result);
		if (t.type != NONE) return t;
		return token(WORD, result);
	}

	token next_token() {
		while (current_char != nullptr) {
			if (current_char->is_whitespace()) {
				skip_whitespace();
				continue;
			}

			if (current_char->is_alpha()) return word();

			if (current_char->is_digit()) return number();

			if (peek_forward("->")) return token(RETURN_ARROW, "->");

			else if (peek_forward("...")) return token(VARIABLE_ARGUMENTS, "...");

			else if (*current_char == "+") return token(ADD, "+");

			else if (*current_char == "-") return token(SUBTRACT, "-");

			else if (*current_char == "*") return token(MULTIPLY, "*");

			else if (*current_char == "/") return token(DIVIDE, "/");

			else if (*current_char == "%") return token(MOD, "%");

			else if (peek_forward("**")) return token(POWER, "**");

			else if (*current_char == "&") return token(BIT_AND, "&");

			else if (*current_char == "|") return token(BIT_OR, "|");

			else if (peek_forward("<<")) return token(BIT_SHIFT_LEFT, "<<");

			else if (peek_forward(">>")) return token(BIT_SHIFT_RIGHT, ">>");

			else if (*current_char == "^") return token(CARET, "^");

			else if (*current_char == "$") return token(DOLLAR, "$");

			else if (peek_forward("++")) return token(ADD_ONE, "++");

			else if (peek_forward("--")) return token(SUBTRACT_ONE, "--");

			else if (peek_forward("+=")) return token(ADD_ASSIGN, "+=");

			else if (peek_forward("-=")) return token(SUBTRACT_ASSIGN, "-=");

			else if (peek_forward("*=")) return token(MULTIPLY_ASSIGN, "*=");

			else if (peek_forward("/=")) return token(DIVIDE_ASSIGN, "/=");

			else if (peek_forward("%=")) return token(MOD_ASSIGN, "%=");

			else if (peek_forward("**=")) return token(POW_ASSIGN, "**=");
			
			else if (peek_forward("&=")) return token(BIT_AND_ASSIGN, "&=");

			else if (peek_forward("|=")) return token(BIT_OR_ASSIGN, "|=");

			else if (peek_forward("<<=")) return token(BIT_SHIFT_LEFT_ASSIGN, "<<=");

			else if (peek_forward(">>=")) return token(BIT_SHIFT_RIGHT_ASSIGN, ">>=");

			else if (peek_forward("==")) return token(EQUALS_TO, "==");

			else if (peek_forward("!=")) return token(NOT_EQUALS_TO, "!=");

			else if (*current_char == ">") return token(GREATER_THAN, ">");

			else if (peek_forward(">=") || peek_forward("=>")) return token(GREATER_THAN_OR_EQUAL_TO, ">=");

			else if (*current_char == "<") return token(LESS_THAN, "<");

			else if (peek_forward("<=") || peek_forward("=<")) return token(LESS_THAN_OR_EQUAL_TO, "<=");

			else if (peek_forward("||")) return token(OR_COMPARE, "||");

			else if (peek_forward("&&")) return token(AND_COMPARE, "&&");

			else if (*current_char == "!") return token(NOT, "!");

			else if (*current_char == "=") return token(EQUALS, "=");

			else if (*current_char == "~") return token(TILDE, "~");

			else if (peek_forward("::")) return token(DOUBLE_COLON, "::");

			else if (*current_char == ".") return token(DOT, ".");

			else if (*current_char == ",") return token(COMMA, ",");

			else if (*current_char == "{") return token(LEFT_BRACKET, "{");

			else if (*current_char == "}") return token(RIGHT_BRACKET, "}");

			else if (*current_char == "(") return token(LEFT_PARENTHESES, "(");

			else if (*current_char == ")") return token(RIGHT_PARENTHESES, ")");

			else if (*current_char == "[") return token(LEFT_SQUARE_BRACKET, "[");

			else if (*current_char == "]") return token(RIGHT_SQUARE_BRACKET, "]");

			else if (*current_char == ":") return token(COLON, ":");

			else if (*current_char == "?") return token(QUESTION, "?");

			else if (*current_char == ";") return token(SEMICOLON, ";");

			else if (*current_char == "'") return token(SINGLE_QUOTE, "'");
			
			else if (*current_char == "\"") return token(DOUBLE_QUOTE, "\"");
		}

		return token(END, nullptr);
	}
};