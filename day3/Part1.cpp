#include "Part1.h"

void Part1::Solution(std::string f)
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

	std::cout << "Trees hit: " << CheckTrees(map) << std::endl;
}

int Part1::CheckTrees(std::vector<std::vector<bool>> map)
{
	int treesHit = 0;
	int length = map.size() - 1;
	
	for (size_t i = 1; i < length; i++)
	{
		if (map[i+1][((i+1)*3)%31])
		{
			treesHit++;
		}
	}

	return treesHit;
}
