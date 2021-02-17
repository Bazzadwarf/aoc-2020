#include "Part2.h"

void Part2::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<std::vector<Seat>> seats = std::vector<std::vector<Seat>>();

	while (file >> temp)
	{
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

std::vector<std::vector<Seat>> Part2::SimulateSeatingArrangement(std::vector<std::vector<Seat>> currentSeatingArrangement)
{
	std::vector<std::vector<Seat>> newSeatingArrangement = currentSeatingArrangement;

	// Check occupied
	for (size_t row = 0; row < currentSeatingArrangement.size(); row++)
	{
		for (size_t col = 0; col < currentSeatingArrangement[row].size(); col++)
		{		
			// NOSEAT CHECK
			if (currentSeatingArrangement[row][col] == Seat::noseat)
			{
				continue;
			}
			
			// OCCUPIED SEAT CHECK
			int seatsVisible = 0;
			size_t crow = 0;
			size_t ccol = 0;

			// Check NW
			for (crow = row, ccol = col; crow > 0 && ccol > 0; crow--, ccol--)
			{
				if (currentSeatingArrangement[crow - 1][ccol - 1] == Seat::occupied)
				{
					seatsVisible++;
					break;
				}

				if (currentSeatingArrangement[crow - 1][ccol - 1] == Seat::empty)
				{
					break;
				}
			}

			// Check N
			for (crow = row, ccol = col; crow > 0; crow--)
			{				
				if (currentSeatingArrangement[crow - 1][ccol] == Seat::occupied)
				{
					seatsVisible++;
					break;
				}

				if (currentSeatingArrangement[crow - 1][ccol] == Seat::empty)
				{
					break;
				}
			}

			// Check NE
			for (crow = row, ccol = col; crow > 0 && ccol < currentSeatingArrangement[crow].size() - 1; crow--, ccol++)
			{
				if (currentSeatingArrangement[crow - 1][ccol + 1] == Seat::occupied)
				{
					seatsVisible++;
					break;
				}

				if (currentSeatingArrangement[crow - 1][ccol + 1] == Seat::empty)
				{
					break;
				}
			}

			// Check E
			for (crow = row, ccol = col; ccol < currentSeatingArrangement[crow].size() - 1; ccol++)
			{
				if (currentSeatingArrangement[crow][ccol + 1] == Seat::occupied)
				{
					seatsVisible++;
					break;
				}

				if (currentSeatingArrangement[crow][ccol + 1] == Seat::empty)
				{
					break;
				}
			}

			// Check SE
			for (crow = row, ccol = col; crow < currentSeatingArrangement.size() - 1 && ccol < currentSeatingArrangement[crow].size() - 1; crow++, ccol++)
			{
				if (currentSeatingArrangement[crow + 1][ccol + 1] == Seat::occupied)
				{
					seatsVisible++;
					break;
				}

				if (currentSeatingArrangement[crow + 1][ccol + 1] == Seat::empty)
				{
					break;
				}
			}

			// Check S
			for (crow = row, ccol = col; crow < currentSeatingArrangement.size() - 1; crow++)
			{
				if (currentSeatingArrangement[crow + 1][ccol] == Seat::occupied)
				{
					seatsVisible++;
					break;
				}

				if (currentSeatingArrangement[crow + 1][ccol] == Seat::empty)
				{
					break;
				}
			}

			// Check SW
			for (crow = row, ccol = col; crow < currentSeatingArrangement.size() - 1 && ccol > 0; crow++, ccol--)
			{
				if (currentSeatingArrangement[crow + 1][ccol - 1] == Seat::occupied)
				{
					seatsVisible++;
					break;
				}

				if (currentSeatingArrangement[crow + 1][ccol - 1] == Seat::empty)
				{
					break;
				}
			}

			// Check W
			for (crow = row, ccol = col; ccol > 0; ccol--)
			{
				if (currentSeatingArrangement[crow][ccol - 1] == Seat::occupied)
				{
					seatsVisible++;
					break;
				}

				if (currentSeatingArrangement[crow][ccol - 1] == Seat::empty)
				{
					break;
				}
			}

			if (currentSeatingArrangement[row][col] == Seat::occupied && seatsVisible > 4)
			{
				newSeatingArrangement[row][col] = Seat::empty;
			}	 

			if (currentSeatingArrangement[row][col] == Seat::empty && seatsVisible == 0)
			{
				newSeatingArrangement[row][col] = Seat::occupied;
			}
		}
	}

	return newSeatingArrangement;
}

bool Part2::CheckChangeInSeatingArrangements(std::vector<std::vector<Seat>> currentSeatingArrangement, std::vector<std::vector<Seat>> newSeatingArrangement)
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
