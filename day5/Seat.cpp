#include "Seat.h"
#define MAXROW 127
#define MAXCOLUMN 7

Seat::Seat(std::string s)
{ 
	row = GetNum(s.substr(0, 7), MAXROW);
	column = GetNum(s.substr(7, 3), MAXCOLUMN);
	id = row * 8 + column;

}

int Seat::GetNum(std::string s, int max)
{
	int min = 0;

	size_t length = s.size();

	for (size_t i = 0; i < length; i++)
	{
		if (s[i] == 'F' || s[i] == 'L')
		{
			max = floorf(((float)max + (float)min) / 2);
		}
		else if (s[i] == 'B' || s[i] == 'R')
		{
			min = ceilf(((float)max + (float)min) / 2);
		}
	}

	return max;
}
