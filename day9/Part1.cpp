#include "Part1.h"

void Part1::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<long long> nums = std::vector<long long>();

	while (getline(file, temp))
	{
		nums.push_back(stoll(temp));
		
		if (nums.size() > 26)
		{
			nums.erase(nums.begin());

			if (!CheckList(nums))
			{
				std::cout << "Answer: " << nums.back() << std::endl;
				break;
			}
		}	
	}
}

bool Part1::CheckList(std::vector<long long> nums)
{
	int length = nums.size() - 1;

	for (size_t i = 0; i < length; i++)
	{
		for (size_t k = 0; k < length; k++)
		{
			if (nums[i] + nums[k] == nums[length])
			{
				return true;
			}
		}
	}

	return false;
}
