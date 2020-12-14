#include "Part2.h"

void Part2::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<std::vector<bool>> map = std::vector<std::vector<bool>>();
	std::vector<bool> newRow = std::vector<bool>();

	// Read the file
	while (file >> temp)
	{
		int length = temp.size();
		newRow.resize(length);

		for (int i = 0; i < length; i++)
		{
			if (temp.at(i) == '#')
			{
				newRow[i] = true;
			}
		}

		map.push_back(newRow);
		newRow.clear();
	}
	
	long long a = CheckTrees(map, 1, 1);
	a *= CheckTrees(map, 3, 1);
	a *= CheckTrees(map, 5, 1);
	a *= CheckTrees(map, 7, 1);
    a *= CheckTrees(map, 1, 2);

	std::cout << "Answer: " << a << std::endl;
}

int Part2::CheckTrees(std::vector<std::vector<bool>> map, int right, int down)
{
	int treesHit = 0;
	int currentColumn = 0;
	int length = map.size() - 1;

	for (size_t i = 0; i < length; i += down)
	{
		currentColumn = (currentColumn + right) % 31;
		
		if (map[i + down][currentColumn])
		{
			treesHit++;
		}
	}

	return treesHit;
}