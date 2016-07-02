using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {
	class Node {
	}
	class Number : Node {
		public Token Token { get; private set; }

		public float Value { get; private set; }

		public Number(Token token) {
			Token = token;
			Value = (float)token.Value;
		}
	}

	class BinaryOperator : Node {
		public Node Left { get; private set; }
		public Node Right { get; private set; }
		public Token Token { get; private set; }

		public BinaryOperator(Node left, Node right, Token op) {
			Left = left;
			Right = right;
			Token = op;
		}
	}

	class UnaryOperator : Node {
		public Token Operator { get; private set; }
		public Node Expression { get; private set; }

		public UnaryOperator(Token op, Node expr) {
			Operator = op;
			Expression = expr;
		}
	}
}
