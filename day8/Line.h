#pragma once
#include "Instructions.h"

struct Line
{
public:
	inst instruction;
	int value;
	bool prevExecuted = false;
};