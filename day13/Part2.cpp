#include "Part2.h"

void Part2::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	// Get time
	file >> temp;
	int time = stoi(temp);

	// Get bus ID input;
	file >> temp;

	std::vector<Bus> busIDs = std::vector<Bus>();
	int offset = 0;

	while (temp.size() > 0)
	{
		size_t comma = temp.length();
		std::string rhs;

		if (temp.find(',') != std::string::npos)
		{
			comma = temp.find_first_of(',');
			rhs = temp.substr(comma + 1, temp.length() - comma);
		}

		std::string lhs = temp;
		lhs.resize(comma);

		if (lhs != "x")
		{
			busIDs.push_back({ stoi(lhs), offset });
		}

		temp = rhs;
		offset++;
	}

	// This is a sieve search as of such the computational time is exponential
	// it is somewhat inefficent but does the job fine here.

	int64_t ans = 0;
	int64_t currProd = 1;

	for (auto bus : busIDs)
	{
		while ((ans + bus.Offset) % bus.ID != 0)
		{
			ans += currProd;
		}
		
		currProd *= bus.ID;
	}
	std::cout << ans << std::endl;

}
