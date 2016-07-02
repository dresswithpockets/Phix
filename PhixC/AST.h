#pragma once

#include "Token.h"

struct node {

} node;

struct binary_operator : node {
	token left;
	token op;
	token right;

	binary_operator(token l, token r, token o) : left(l), right(r), op(o) {}
};

struct unary_operator : node {
	token op;
	token expr;

	unary_operator(token o, token e) : op(o), expr(e) {}
};

typedef enum {
	FLOAT_T,
	DOUBLE_T,
	SHORT_T,
	INT_T,
	LONG_T
} num_type;

struct number : node {
	token tok;

	num_type n_type;

	float float_value;
	double double_value;
	short short_value;
	int int_value;
	long long_value;

	number(token t, type_info ti) : tok(t) {
		if (ti == typeid(float)) {
			float_value = atof(t.str_value.c_str());
			n_type = FLOAT_T;
		}
		if (ti == typeid(double)) {
			double_value = atof(t.str_value.c_str());
			n_type = DOUBLE_T;
		}
		if (ti == typeid(short)) {
			short_value = (short)atoi(t.str_value.c_str());
			n_type = SHORT_T;
		}
		if (ti == typeid(int)) {
			short_value = atoi(t.str_value.c_str());
			n_type = INT_T;
		}
		if (ti == typeid(long)) {
			short_value = stol(t.str_value);
			n_type = LONG_T;
		}
	}
};

struct char_value : node {
	token tok;
};

struct program : node {
	node* statements;

	program(node list[]) { memcpy(statements, list, sizeof(list)); }
};

struct routine : node {
	token name;

	bool has_parameters;
	parameter* parameters;

	bool has_return_type;
	type* types;

	node statements[];

	routine(token _name, parameter _params[], type _types[], node _statements[]) : name(_name) {
		
		if (_params) memcpy(statements, _params, sizeof(_params));

		if (_types) memcpy(statements, _types, sizeof(_types));

		if (_statements) memcpy(statements, _statements, sizeof(_statements));
	}
};

struct parameter : node {
	token var_word;
	type var_type;

	parameter(token word, type t) : var_word(word), var_type(t) {}
};

struct if_statement : node {

};

struct type : node {
	bool reference;
	type_prefix* prefixes;
	token word;

	type(bool ref, type_prefix* _prefixes, token _word) : reference(ref), word(_word) {
		if (_prefixes) memcpy(prefixes, _prefixes, sizeof(_prefixes));
	}
};

struct type_prefix : node {
	bool caret;
	array_prefix prefix;

	type_prefix(bool _caret, array_prefix _prefix) : caret(_caret), prefix(_prefix) {}
};

//[] = no roots dynamic
//[,,,] = 4d dynamic array
//[5] = statically sized array
//[5,2] = statically sized 2d array
struct array_prefix : node {
	token* roots;

	array_prefix(token* _roots) {
		if (_roots) memcpy(roots, _roots, sizeof(_roots));
	}
};

struct array_access : node {
	int index;

	array_access(int i) : index(i) {}
};