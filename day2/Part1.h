#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Password.h"

using namespace std;

class Part1
{
public:

	static void Solution(string f);

private:

	static password ParsePassword(string bounds, string tchar, string p);

	static bool VerifyPassword(password* p);
};

