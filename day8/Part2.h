#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>

#include "Line.h"

class Part2
{
public:
	static void Solution(std::string f);

private:
	static std::vector<std::string> splitString(std::string s, const std::string delimiter);
	static int execute(std::vector<Line> program);
	static void flipInstruction(Line* line);
};

