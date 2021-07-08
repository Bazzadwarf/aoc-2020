#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Shared.h"

class Part1
{
public:
	static void Solution(std::string f);

private:
	static void MoveNorth(Ship& s, int n);
	static void MoveSouth(Ship& s, int n);
	static void MoveEast(Ship& s, int n);
	static void MoveWest(Ship& s, int n);
	static void TurnLeft(Ship& s, int n);
	static void TurnRight(Ship& s, int n);
	static void MoveForward(Ship& s, int n);	
};
