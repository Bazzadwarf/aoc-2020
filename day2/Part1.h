#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Password.h"


class Part1
{
public:

	static void Solution(std::string f);

private:

	static password ParsePassword(std::string bounds, std::string tchar, std::string p);

	static bool VerifyPassword(password* p);
};

