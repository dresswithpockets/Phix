using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {
	class Phix {
		public static void Main(string[] args) {

			string text = "";

			while (true) {
				Console.Write("calc> ");
				text = Console.ReadLine();

				/*Interpreter interpreter = new Interpreter(new Lexer(text));
				Console.WriteLine(interpreter.Expression());*/

				Lexer lexer = new Lexer(text);
				Parser parser = new Parser(lexer);
				Interpreter interpreter = new Interpreter(parser);
				float result = interpreter.Interpret();
				Console.WriteLine(result);
				try {
				}
				catch (ArgumentException ae) {
					Console.WriteLine("Invalid Expression: " + ae.Message);
				}
				catch (Exception e) {
					Console.WriteLine("Error: " + e.Message);
				}
			}
		}
	}
}
