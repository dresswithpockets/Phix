using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {

	static class Util {

		public static string Digits = "1234567890";
		public static string Alphabet = "abcdefghijklmnop";

		public static bool IsDigit(this char c) {
			return Digits.Contains(c);
		}

		public static bool IsAlphaNumerical(this char c) {
			return Digits.Contains(c) || Alphabet.Contains(c);
		}
	}
}
