using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Reflection;

namespace Phix {
	class NodeVisitor : IErrorProne {
		public object Visit(Node node) {
			Console.WriteLine("\n| Crawling {0}", GetType().Name);

			MethodInfo[] methods = GetType().GetRuntimeMethods().Where(mi => {

				if (!mi.IsPublic) return false;

				ParameterInfo[] parameters = mi.GetParameters();

				Console.Write("|	.{0}(", mi.Name, parameters.Length);
				for (int i = 0; i < parameters.Length; i++) {
					Console.Write("{0} {1}", parameters[i].ParameterType.Name, parameters[i].Name);

					if (i != parameters.Length - 1) Console.Write(", ");
				}
				Console.Write(")\n");

				return mi.Name == ("Visit" + node.GetType().Name) &&
				parameters.Length == 1 &&
				parameters[0].ParameterType.Equals(node.GetType());
			}).ToArray();
			return methods[0].Invoke(this, new[] { node });
		}
	}
}
