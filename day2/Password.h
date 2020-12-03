#pragma once

#include <string>

using namespace std;

struct password
{
	int lowerBound;
	int upperBound;
	char testchar;
	string pass;

	password(int lb, int ub, char tc, string p)
	{
		lowerBound = lb;
		upperBound = ub;
		testchar = tc;
		pass = p;
	}
};