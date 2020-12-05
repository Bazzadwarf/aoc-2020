#include "Part2.h"

#define MAXROW 127
#define MAXCOLUMN 7

void Part2::Solution(string f)
{
	ifstream file(f);

	string temp;

	vector<Seat> tickets = vector<Seat>();

	while (file >> temp)
	{
		tickets.push_back(Seat(temp));
	}

	size_t length = tickets.size();
	int highestID = 0; 
	bool seats[(MAXROW * 8 + MAXCOLUMN)] = { };
	
	for (size_t i = 0; i < length; i++)
	{
		seats[tickets[i].id] = true;
	}
	
	length = MAXROW * 8 + MAXCOLUMN;
	for (size_t i = 1; i < length; i++)
	{
		if (seats[i - 1] && !seats[i] && seats[i + 1])
		{
			cout << "The answer is: " << i << endl;
			break;
		}
	}
}
