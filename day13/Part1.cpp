#include "Part1.h"

void Part1::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	// Get time
	file >> temp;
	int time = stoi(temp);

	// Get bus ID input;
	file >> temp;

	std::vector<int> busIDs = std::vector<int>();

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
			busIDs.push_back(stoi(lhs));
		}

		temp = rhs;
	}

	int ans = 0;
	int currTime = time;

	while (ans == 0)
	{
		for (auto bus : busIDs)
		{
			if (currTime % bus == 0)
			{
				ans = bus * (currTime - time);
			}
		}

		currTime++;
	}

	std::cout << ans << std::endl;

}
