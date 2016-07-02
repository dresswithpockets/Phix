#pragma once

class IErrorProne
{
public:
	int Valid() { return 0; }
	int Error() { return 1; }
	int ArgumentError() { return 2; }
};

