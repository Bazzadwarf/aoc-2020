#pragma once

#include <string>


class Seat
{
public:
	Seat(std::string s);

	int row;
	int column;
	int id;

private:
	int GetNum(std::string s, int max);
};
