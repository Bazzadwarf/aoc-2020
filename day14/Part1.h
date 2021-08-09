#pragma once
#include <algorithm>
#include <bitset>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "MaskVal.h"

class Part1
{

public:
	static void Solution(std::string f);

private:
	static void ParseMask(std::string s);
	static void ParseMem(std::string inst, std::string value);
};
