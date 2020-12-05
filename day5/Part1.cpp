#include "Part1.h"
#include <math.h>

void Part1::Solution(string f)
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

	for (size_t i = 0; i < length; i++)
	{
		if (tickets[i].id > highestID)
		{
			highestID = tickets[i].id;
		}
	}

	cout << "The highest ID is: " << highestID << endl;
}
