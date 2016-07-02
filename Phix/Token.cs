using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {

	enum TokenType {

		NONE = 0,

		// Delimeters
		COMMA,
		LEFT_BRACKET,
		RIGHT_BRACKET,
		LEFT_PARENTHESES,
		RIGHT_PARENTHESES,
		SEMICOLON,

		// Operators
		ADDITION,
		SUBTRACTION,
		MULTIPLICATION,
		DIVISION,

		INITIALIZE,
		ASSIGN,
		CONSTANT,

		// Variables and Naming
		WORD,
		NUMBER,
		STRING,
		CHARACTER,

		// Functions
		RETURN_ARROW,

		EOF
	}

	class Token {

		public TokenType Type;
		public object Value;

		public Token(TokenType type, object value) {
			Type = type;
			Value = value;
		}

		public override string ToString() {
			return string.Format("Token({0}, {1})", Type.ToString(), Value.ToString());
		}
	}
}
