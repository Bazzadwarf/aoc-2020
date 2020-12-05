#pragma once

#include <string>

using namespace std;

class Seat
{
public:
	Seat(string s);

	int row;
	int column;
	int id;

private:
	int GetNum(string s, int max);
};
