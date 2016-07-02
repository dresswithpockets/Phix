#pragma once

#include <cctype>

const string digits = "1234567890";
const string alphabet = "abcdefghijklmnop";

struct PChar {
	
	char value;

	operator char() { return value; }

	operator string() { return string(&value); }

	operator char*() { return &value; }

	bool is_whitespace() { return isspace(value); }

	bool is_digit() { return isdigit(value); }

	bool is_alpha() { return isalpha(value); }

	bool is_alphanumeric() {
		return isalnum(value);
	}

	bool valid(string validity) {
		int n = validity.length();
		for (int i = 0; i < n; i++) {
			if (validity[i] == value) return true;
		}

		return false;
	}

	PChar(char c) : value(c) {}
};