#include "Part2.h"

void Part2::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<long long> nums = std::vector<long long>();

	while (getline(file, temp))
	{
		nums.push_back(stoll(temp));

		if (nums.back() == 23278925)
		{
			std::cout << "Answer: " << CheckList(nums) << std::endl;
		}
	}
}

long long Part2::CheckList(std::vector<long long> nums)
{
	std::vector<long long> sums(nums.size());
	std::partial_sum(nums.begin(), nums.end(), sums.begin());

	for (size_t i = 1; i < sums.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (sums[i] - sums[j] == 23278925)
			{
				const auto minmax = std::minmax_element(nums.begin() + j, nums.begin() + i);
				return *minmax.second + *minmax.first;
			}
		}
	}
	return 0;
}
