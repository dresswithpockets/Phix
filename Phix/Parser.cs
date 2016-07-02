using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {
	class Parser : IErrorProne {
		public Lexer Lex { get; private set; }
		public Token CurrentToken { get; private set; }

		public Parser(Lexer lex) {
			Lex = lex;
			CurrentToken = lex.NextToken();
		}

		public void Eat(TokenType type) {
			if (CurrentToken.Type == type) CurrentToken = Lex.NextToken();
			else Error();
		}

		public Node Factor() {

			Token t = CurrentToken;
			switch (t.Type) {
				case TokenType.ADDITION:
					Eat(TokenType.ADDITION);
					return new UnaryOperator(t, Factor());
				case TokenType.SUBTRACTION:
					Eat(TokenType.SUBTRACTION);
					return new UnaryOperator(t, Factor());
				case TokenType.NUMBER:
					Eat(TokenType.NUMBER);
					return new Number(t);
				case TokenType.LEFT_PARENTHESES:
					Eat(TokenType.LEFT_PARENTHESES);
					Node n = Expression();
					Eat(TokenType.RIGHT_PARENTHESES);
					return n;
			}

			return null;
		}

		public Node Term() {

			Node node = Factor();

			while (CurrentToken.Type == TokenType.MULTIPLICATION || CurrentToken.Type == TokenType.DIVISION) {
				Token t = CurrentToken;

				Eat(t.Type);

				node = new BinaryOperator(node, Factor(), t);
			}

			return node;
		}

		public Node Expression() {

			Node node = Term();

			while (CurrentToken.Type == TokenType.ADDITION || CurrentToken.Type == TokenType.SUBTRACTION) {
				Token t = CurrentToken;
				Eat(t.Type);

				node = new BinaryOperator(node, Term(), t);
			}

			return node;
		}

		public Node Parse() {
			return Expression();
		}
	}
}
