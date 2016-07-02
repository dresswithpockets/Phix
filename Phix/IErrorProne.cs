using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Phix {
	abstract class IErrorProne {
		public virtual void Error() {
			throw new Exception("Error Parsing Input");
		}

		public virtual void ArgumentError(string paramName, string paramValue) {
			throw new ArgumentException(string.Format("{0} = '{1}'", paramName, paramValue));
		}
	}
}
