#pragma once

#ifndef LENGTH_DEF
#define LENGTH_DEF
#define LENGTH(arr) sizeof(arr)/sizeof(arr[0])
#endif

#include <stdio.h>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;

typedef enum {
	NONE = 0,

	END,

	// Values and Variables
	WORD,
	STRING,
	CHARACTER,
	NUMBER,

	// Functions
	RETURN_ARROW,
	VARIABLE_ARGUMENTS,

	// Operators
	ADD,
	SUBTRACT,
	MULTIPLY,
	DIVIDE,
	MOD,
	POWER,
	BIT_AND,
	BIT_OR,
	BIT_SHIFT_LEFT,
	BIT_SHIFT_RIGHT,

	// Pointers
	CARET, // '^' used for defining pointer types, referencing and dereferencing.
	DOLLAR, // '$' used to identify reference parameters

	// Unary Arithmetic
	ADD_ONE,
	SUBTRACT_ONE,

	// Comparison Operators
	EQUALS_TO,
	NOT_EQUALS_TO,
	GREATER_THAN,
	GREATER_THAN_OR_EQUAL_TO,
	LESS_THAN,
	LESS_THAN_OR_EQUAL_TO,
	OR_COMPARE,
	AND_COMPARE,

	// Negation
	NOT,

	// Assignment
	EQUALS,
	ADD_ASSIGN,
	SUBTRACT_ASSIGN,
	MULTIPLY_ASSIGN,
	DIVIDE_ASSIGN,
	MOD_ASSIGN,
	POW_ASSIGN,
	BIT_AND_ASSIGN,
	BIT_OR_ASSIGN,
	BIT_SHIFT_LEFT_ASSIGN,
	BIT_SHIFT_RIGHT_ASSIGN,

	// Delimeters
	TILDE,
	DOUBLE_COLON,
	COLON,
	DOT,
	COMMA,
	LEFT_BRACKET,
	RIGHT_BRACKET,
	LEFT_PARENTHESES,
	RIGHT_PARENTHESES,
	LEFT_SQUARE_BRACKET,
	RIGHT_SQUARE_BRACKET,
	QUESTION,
	SEMICOLON,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,

	// Keywords
	USING,

	IF,
	ELSE,
	SWITCH,
	CASE,
	BREAK,
	CONTINUE,
	FOR,
	FOREACH,
	WHILE,
	DO,

	IS,
	TYPEOF,
	SIZEOF,
	NEW,
	DELETE,
	NULLPTR,
	VOID,

	INLINE,

	TRUE,
	FALSE,

	STRUCT,
	UNION,
	THIS,

	RETURN,

	INT8,
	INT16,
	INT32,
	INT64,
	UINT8,
	UINT16,
	UINT32,
	UINT64,

	INT,
	SINT,
	UINT,

	SINGLE,
	DOUBLE,
	FLOAT,

	STRING,
	CHAR,

	BYTE,

	VAR

} token_type;

struct token {
	token_type type;

	string str_value;

	token(token_type t, string str) : type(t), str_value(str) {}

	string tostr() {
		ostringstream buffer;
		//buffer << "token(" << (int)type << ", " << str_value << "," << num_value << ")";
		return buffer.str();
	}
};

struct key_token {
	string key;
	token value;
	key_token(string k, token t) : key(k), value(t) {}
};

const key_token KEYWORDS[] = {
	key_token("int8", token(INT8, "int8")),
	key_token("int16", token(INT16, "int16")),
	key_token("int32", token(INT32, "int32")),
	key_token("int64", token(INT64, "int64")),
	key_token("uint8", token(UINT8, "uint8")),
	key_token("uint16", token(UINT16, "uint16")),
	key_token("uint32", token(UINT32, "uint32")),
	key_token("uint64", token(UINT64, "uint64")),

	key_token("int", token(INT, "int")),
	key_token("sint", token(SINT, "sint")),
	key_token("uint", token(UINT, "uint")),

	key_token("single", token(SINGLE, "single")),
	key_token("float32", token(SINGLE, "float32")),
	key_token("double", token(DOUBLE, "double")),
	key_token("float64", token(DOUBLE, "float64")),
	key_token("float", token(FLOAT, "float")),

	key_token("string", token(STRING, "string")),
	key_token("char", token(CHAR, "char")),
	key_token("byte", token(BYTE, "byte")),

	key_token("var", token(VAR, "var")),

	key_token("void", token(VOID, "void")),

	key_token("using", token(USING, "using")),

	key_token("is", token(IS, "is")),
	key_token("new", token(NEW, "new")),
	key_token("delete", token(DELETE, "delete")),
	key_token("null", token(NULLPTR, "null")),
	key_token("typeof", token(TYPEOF, "typeof")),
	key_token("sizeof", token(SIZEOF, "sizeof")),

	key_token("true", token(TRUE, "true")),
	key_token("false", token(FALSE, "false")),

	key_token("for", token(FOR, "for")),
	key_token("while", token(WHILE, "while")),
	key_token("foreach", token(FOREACH, "foreach")),
	key_token("if", token(IF, "if")),
	key_token("else", token(ELSE, "else")),
	key_token("switch", token(SWITCH, "switch")),
	key_token("case", token(CASE, "case")),
	key_token("break", token(BREAK, "break")),
	key_token("continue", token(CONTINUE, "continue")),
	key_token("do", token(DO, "do")),

	key_token("struct", token(STRUCT, "struct")),
	key_token("union", token(UNION, "union")),
	key_token("this", token(THIS, "this")),

	key_token("return", token(RETURN, "return")),

	key_token("inline", token(INLINE, "inline")),

	key_token("using", token(USING, "using")),
};

token get_kw(string str) {
	int n = str.length();
	for (int i = 0; i < n; i++) {
		if (KEYWORDS[n].key == str) return KEYWORDS[n].value;
	}
	return token(END, "\0");
}