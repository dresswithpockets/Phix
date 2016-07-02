using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {
	class Interpreter : NodeVisitor {
		
		public Parser Parser { get; private set; }
		
		public Interpreter(Parser parser) {
			Parser = parser;
		}

		public float VisitBinaryOperator(BinaryOperator op) {
			switch (op.Token.Type) {
				case TokenType.ADDITION:
					return (float)Visit(op.Left) + (float)Visit(op.Right);
				case TokenType.SUBTRACTION:
					return (float)Visit(op.Left) - (float)Visit(op.Right);
				case TokenType.MULTIPLICATION:
					return (float)Visit(op.Left) * (float)Visit(op.Right);
				case TokenType.DIVISION:
					return (float)Visit(op.Left) / (float)Visit(op.Right);
			}

			return 0f;
		}

		public float VisitUnaryOperator(UnaryOperator op) {
			switch (op.Operator.Type) {
				case TokenType.ADDITION:
					return +(float)Visit(op.Expression);
				case TokenType.SUBTRACTION:
					return -(float)Visit(op.Expression);
			}

			return 0f;
		}

		public float VisitNumber(Number num) {
			return num.Value;
		}

		public float Interpret() {
			Node tree = Parser.Parse();
			return (float)Visit(tree);
		}

		/*public Lexer Lex { get; private set; }
		public Token CurrentToken { get; private set; }

		public Interpreter(Lexer lex) {
			Lex = lex;
			CurrentToken = Lex.NextToken();
		}

		public void Eat(TokenType type) {
			if (CurrentToken.Type == type) CurrentToken = Lex.NextToken();
			else Error();
		}

		public float Factor() {
			Token t = CurrentToken;
			if (t.Type == TokenType.NUMBER) {
				Eat(TokenType.NUMBER);
				return (float)t.Value;
			}
			else if (t.Type == TokenType.LPAREN) {
				Eat(TokenType.LPAREN);
				float result  = Expression();
				Eat(TokenType.RPAREN);
				return result;
			}
			return 0;
		}

		public float Term() {
			float result = Factor();

			while (CurrentToken.Type == TokenType.MUL || CurrentToken.Type == TokenType.DIV) {
				Token t = CurrentToken;

				if (t.Type == TokenType.MUL) {
					Eat(TokenType.MUL);
					result *= Factor();
				}
				else if (t.Type == TokenType.DIV) {
					Eat(TokenType.DIV);
					result /= Factor();
				}
			}

			return result;
		}

		public float Expression() {
			float result = Term();

			while (CurrentToken.Type == TokenType.PLUS || CurrentToken.Type == TokenType.MINUS) {
				Token t = CurrentToken;

				if (t.Type == TokenType.PLUS) {
					Eat(TokenType.PLUS);
					result += Term();
				}
				else if (t.Type == TokenType.MINUS) {
					Eat(TokenType.MINUS);
					result -= Term();
				}
			}

			return result;
		}*/
	}
}
