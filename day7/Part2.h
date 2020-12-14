#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Bag.h"


class Part2
{
public:
	static void Solution(std::string f);

private:
	static std::vector<std::string> splitString(std::string s, const std::string delimiter);
	static int checkBags(Bag* b);
};
