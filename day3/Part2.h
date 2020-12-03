#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Part2
{
public:

	static void Solution(string f);

private:

	static int CheckTrees(vector<vector<bool>> map, int right, int down);
};

