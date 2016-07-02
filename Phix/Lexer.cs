using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {
	class Lexer : IErrorProne {

		public static readonly char[] Operators = { PLUS, MINUS, MULTIPLY, DIVIDE, POWER, MODULUS };
		public static readonly char[] ExpressionOps = { PLUS, MINUS };
		public static readonly char[] TermOps = { MULTIPLY, DIVIDE };

		public static readonly Dictionary<string, Token> ReservedKeywords = new Dictionary<string, Token>() {
			{ "", null }
		};

		public const char PLUS = '+';
		public const char MINUS = '-';
		public const char MULTIPLY = '*';
		public const char DIVIDE = '/';
		public const char POWER = '^';
		public const char MODULUS = '%';
		public const char LPAREN = '(';
		public const char RPAREN = ')';

		public string Text { get; private set; }
		public int Pos { get; private set; }
		public PChar CurrentChar { get; private set; }

		public Lexer(string text) {
			Text = text;
			Pos = 0;
			CurrentChar = Text[Pos];
		}

		public void Advance() {
			Pos++;
			if (Pos > Text.Length - 1) CurrentChar = null;
			else CurrentChar = Text[Pos];
		}

		public void SkipWhitespace() {
			while (CurrentChar != null && CurrentChar.IsWhiteSpace()) Advance();
		}

		public float Number() {

			StringBuilder builder = new StringBuilder("");

			while (CurrentChar != null && (CurrentChar.IsDigit() || CurrentChar == '.')) {
				builder.Append(CurrentChar);
				Advance();
			}

			return float.Parse(builder.ToString());
		}

		public PChar Peek() {
			int pos = Pos + 1;
			if (pos > Text.Length - 1) return null;

			return Text[pos];
		}
		
		public Token Variable() {
			string result = "";

			return null; // TODO: temp
		}

		public Token NextToken() {
			while (CurrentChar != null) {

				if (CurrentChar.IsWhiteSpace()) {
					SkipWhitespace();
					continue;
				}

				if (CurrentChar.IsDigit()) return new Token(TokenType.NUMBER, Number());

				if (CurrentChar == PLUS) {
					Advance();
					return new Token(TokenType.ADDITION, PLUS);
				}
				else if (CurrentChar == MINUS) {
					Advance();
					return new Token(TokenType.SUBTRACTION, MINUS);
				}
				else if (CurrentChar == MULTIPLY) {
					Advance();
					return new Token(TokenType.MULTIPLICATION, MULTIPLY);
				}
				else if (CurrentChar == DIVIDE) {
					Advance();
					return new Token(TokenType.DIVISION, DIVIDE);
				}
				else if (CurrentChar == LPAREN) {
					Advance();
					return new Token(TokenType.LEFT_PARENTHESES, LPAREN);
				}
				else if (CurrentChar == RPAREN) {
					Advance();
					return new Token(TokenType.RIGHT_PARENTHESES, RPAREN);
				}

				Error();
			}

			return new Token(TokenType.EOF, null);
		}
	}
}
