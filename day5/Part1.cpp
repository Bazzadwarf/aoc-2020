#include "Part1.h"
#include <math.h>

void Part1::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<Seat> tickets = std::vector<Seat>();

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

	std::cout << "The highest ID is: " << highestID << std::endl;
}
