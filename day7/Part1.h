#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Bag.h"


class Part1
{
public:
	static void Solution(std::string f);

private:
	static std::vector<std::string> splitString(std::string s, const std::string delimiter);
	static void checkBags(int* c, std::vector<Bag*>* bags, Bag* b);
};

