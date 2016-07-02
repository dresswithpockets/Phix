// PhixClr.cpp : main project file.

#include "stdafx.h"
#include "Phix.h"
#include "Lexer.h"
#include "Interpreter.h"

using namespace System;

void NullTerminate(char*& cstr) {
	cstr = (char*)calloc(1, strlen(cstr) + sizeof(char));
}

int main(int argc, char* argv)
{
	while (true) {
		try {
			char* input;
			printf("calc>");
			scanf("%s", input);

			NullTerminate(input);

			Lexer* lex = new Lexer(input);
			Interpreter* interp = new Interpreter(lex);

			float result;
			int error = interp->Expression(result);

			if (!error) {
				printf("\n%f\n", result);
			}

			delete interp;
			delete lex;
		}
		catch (AccessViolationException^ ave) {
			Console::WriteLine(ave->Message);
		}
		catch (NullReferenceException^ nre) {
			Console::WriteLine(nre->Source);
			Console::WriteLine(nre->Message);
			Console::WriteLine(nre->StackTrace);
		}
		catch (Exception^ e) {
			Console::WriteLine(e->Message);
		}
	}
    return 0;
}