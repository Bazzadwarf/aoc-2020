#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


class Part2
{
public:

	static void Solution(std::string f);

private:

	static int CheckTrees(std::vector<std::vector<bool>> map, int right, int down);
};

