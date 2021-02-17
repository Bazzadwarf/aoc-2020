#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Seat.h"

class Part2
{
public:
	static void Solution(std::string f);

private:
	static std::vector<std::vector<Seat>> SimulateSeatingArrangement(std::vector<std::vector<Seat>> currentSeatingArrangement);

	static bool CheckChangeInSeatingArrangements(std::vector<std::vector<Seat>> currentSeatingArrangement, std::vector<std::vector<Seat>> newSeatingArrangement);
};

