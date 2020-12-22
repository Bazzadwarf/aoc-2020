#include "Part1.h"

void Part1::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<std::vector<Seat>> seats = std::vector<std::vector<Seat>>();

	while (file >> temp)
	{
		std::cout << temp << std::endl;

		std::vector<Seat> row = std::vector<Seat>();

		for (size_t i = 0; i < temp.size(); i++)
		{
			switch (temp[i])
			{
			case 'L':
				row.push_back(Seat::empty);
				break;
			case '.':
				row.push_back(Seat::noseat);
				break;
			default:
				break;
			}
		}

		seats.push_back(row);
	}

	std::vector<std::vector<Seat>> newSeatingArrangement = SimulateSeatingArrangement(seats);

	while (CheckChangeInSeatingArrangements(seats, newSeatingArrangement))
	{
		seats = newSeatingArrangement;
		newSeatingArrangement = SimulateSeatingArrangement(seats);
	}

	int numOccupiedSeats = 0;

	for (size_t i = 0; i < seats.size(); i++)
	{
		for (size_t j = 0; j < seats[i].size(); j++)
		{
			if (seats[i][j] == Seat::occupied)
			{
				numOccupiedSeats++;
			}
		}
	}

	std::cout << numOccupiedSeats << std::endl;
}

std::vector<std::vector<Seat>> Part1::SimulateSeatingArrangement(std::vector<std::vector<Seat>> currentSeatingArrangement)
{
	std::vector<std::vector<Seat>> newSeatingArrangement = currentSeatingArrangement;

	for (size_t row = 0; row < currentSeatingArrangement.size(); row++)
	{
		for (size_t col = 0; col < currentSeatingArrangement[row].size(); col++)
		{
			int numberOfOccupiedSeats = 0;

			// Check NW
			if (row > 0 && col > 0 && currentSeatingArrangement[row-1][col-1] == Seat::occupied)
			{
				numberOfOccupiedSeats++;
			}

			// Check N
			if (row > 0 && currentSeatingArrangement[row - 1][col] == Seat::occupied)
			{
				numberOfOccupiedSeats++;
			}

			// Check NE
			if (row > 0 && col < currentSeatingArrangement[row].size() - 1 && currentSeatingArrangement[row - 1][col + 1] == Seat::occupied)
			{
				numberOfOccupiedSeats++;
			}

			// Check E
			if (col < currentSeatingArrangement[row].size() - 1 && currentSeatingArrangement[row][col + 1] == Seat::occupied)
			{
				numberOfOccupiedSeats++;
			}

			// Check SE
			if (row < currentSeatingArrangement.size() - 1 && col < currentSeatingArrangement[row].size() - 1 && currentSeatingArrangement[row + 1][col + 1] == Seat::occupied)
			{
				numberOfOccupiedSeats++;
			}

			// Check S
			if (row < currentSeatingArrangement.size() - 1 && currentSeatingArrangement[row + 1][col] == Seat::occupied)
			{
				numberOfOccupiedSeats++;
			}

			// Check SW
			if (row < currentSeatingArrangement.size() - 1 && col > 0 && currentSeatingArrangement[row + 1][col - 1] == Seat::occupied)
			{
				numberOfOccupiedSeats++;
			}

			// Check W
			if (col > 0 && currentSeatingArrangement[row][col - 1] == Seat::occupied)
			{
				numberOfOccupiedSeats++;
			}


			if (currentSeatingArrangement[row][col] == Seat::empty && numberOfOccupiedSeats == 0)
			{
				newSeatingArrangement[row][col] = Seat::occupied;
			}
			else if (currentSeatingArrangement[row][col] == Seat::occupied && numberOfOccupiedSeats > 3)
			{
				newSeatingArrangement[row][col] = Seat::empty;
			}
		}
	}
	
	return newSeatingArrangement;
}

bool Part1::CheckChangeInSeatingArrangements(std::vector<std::vector<Seat>> currentSeatingArrangement, std::vector<std::vector<Seat>> newSeatingArrangement)
{
	for (size_t i = 0; i < currentSeatingArrangement.size(); i++)
	{
		for (size_t j = 0; j < currentSeatingArrangement[i].size(); j++)
		{
			if (currentSeatingArrangement[i][j] != newSeatingArrangement[i][j])
			{
				return true;
			}
		}
	}
	
	return false;
}
