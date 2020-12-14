#pragma once

#include <string>


struct password
{
	int lowerBound;
	int upperBound;
	char testchar;
	std::string pass;

	password(int lb, int ub, char tc, std::string p)
	{
		lowerBound = lb;
		upperBound = ub;
		testchar = tc;
		pass = p;
	}
};