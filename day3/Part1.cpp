#include "Part1.h"

void Part1::Solution(string f)
{
	ifstream file(f);

	string temp;

	vector<vector<bool>> map = vector<vector<bool>>();
	vector<bool> newRow = vector<bool>();

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

	cout << "Trees hit: " << CheckTrees(map) << endl;
}

int Part1::CheckTrees(vector<vector<bool>> map)
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
