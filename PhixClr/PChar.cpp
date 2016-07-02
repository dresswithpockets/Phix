
#include "stdafx.h"
#include "Phix.h"
#include "Interpreter.h"

template <typename T, unsigned S>
inline unsigned arraysize(const T(&v)[S]) { return S; }

bool PChar::IsDigit() {
	switch (Value) {
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	case '0':
		return true;
	}
	return false;
}

bool PChar::IsWhiteSpace() {
	return Value == ' ' || Value == '\n' || Value == '\r' || Value == '\t';
}

bool PChar::IsOperator() {

	int asize = arraysize(Operators);
	for (int i = 0; i < asize; i++) {
		if (Operators[i] == Value) return true;
	}
	return false;
}