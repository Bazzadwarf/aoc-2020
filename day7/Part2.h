#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Bag.h"

using namespace std;

class Part2
{
public:
	static void Solution(string f);

private:
	static vector<string> splitString(string s, const string delimiter);
	static int checkBags(Bag* b);
};
