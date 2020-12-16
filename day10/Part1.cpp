#include "Part1.h"

void Part1::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<int> adapters = std::vector<int>();

	// Add the starting joltage
	adapters.push_back(0);

	// Add out input
	while (file >> temp)
	{
		adapters.push_back(stoi(temp));
	}

	// Sort from smallest to largest
	std::sort(adapters.begin(), adapters.end());

	// Add the device joltage
	adapters.push_back(adapters.back() + 3);

	int onejoltagegaps = 0;
	int threejoltagegaps = 0;

	for (size_t i = 0; i < adapters.size() - 1; i++)
	{
		if (adapters[i + 1] - adapters[i] == 1)
		{
			onejoltagegaps++;
			continue;
		}
		if (adapters[i + 1] - adapters[i] == 3)
		{
			threejoltagegaps++;
			continue;
		}
	}

	std::cout << "Answer: " << onejoltagegaps * threejoltagegaps << std::endl;
}
