using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {
	class PChar {
		
		public char Value { get; private set; }

		public static implicit operator char(PChar p) {
			return p.Value;
		}

		public static implicit operator PChar(char c) {
			return new PChar(c);
		}

		public bool IsWhiteSpace() {
			return Value == ' ' || Value == '\n' || Value == '\r' || Value == '\t';
		}

		public bool IsDigit() {
			return Value.IsDigit();
		}

		public bool IsOperator() {
			return Lexer.Operators.Contains(Value);
		}

		public override bool Equals(object obj) {
			return Value.Equals(obj);
		}

		public override string ToString() {
			return Value.ToString();
		}

		public override int GetHashCode() {
			return Value.GetHashCode();
		}

		public PChar(char c) {
			Value = c;
		}
	}
}
