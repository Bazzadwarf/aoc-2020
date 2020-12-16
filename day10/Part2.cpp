#include "Part2.h"

void Part2::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<uint64_t> adapters = std::vector<uint64_t>();

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

	std::vector<uint64_t> results(adapters.size());
	results[0] = 1;

	// Since our data set is rather small, this is passable as modern PC's are fast
	// Under any circumstance where performance matters...
	// Please for the love of god...
	// Don't do this...
	for (size_t i = 0; i < adapters.size(); i++)
	{
		for (size_t j = i+1; j <= (i + 3) && j < adapters.size(); j++)
		{
			if (adapters[j] - adapters[i] <= 3)
			{
				results[j] += results[i];
			}
		}
	}

	std::cout << "Answer: " << results.back() << std::endl;
}
