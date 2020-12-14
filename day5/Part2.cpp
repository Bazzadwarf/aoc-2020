#include "Part2.h"

#define MAXROW 127
#define MAXCOLUMN 7

void Part2::Solution(std::string f)
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
			std::cout << "The answer is: " << i << std::endl;
			break;
		}
	}
}
