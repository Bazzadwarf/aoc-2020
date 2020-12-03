#include "Part2.h"

void Part2::Solution(string f)
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
	
	long long a = CheckTrees(map, 1, 1);
	a *= CheckTrees(map, 3, 1);
	a *= CheckTrees(map, 5, 1);
	a *= CheckTrees(map, 7, 1);
    a *= CheckTrees(map, 1, 2);

	cout << "Answer: " << a << endl;
}

int Part2::CheckTrees(vector<vector<bool>> map, int right, int down)
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