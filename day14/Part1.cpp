#include "Part1.h"

static MaskVal currentMask[36];
static std::bitset<36> mem[65196];

void Part1::Solution(std::string f)
{
	std::ifstream file(f);

	std::string instruction, eq, value;	

	while (file >> instruction >> eq >> value)
	{
		switch (instruction[1])
		{
		case 'a':
			ParseMask(value);
			break;
		case 'e':
			ParseMem(instruction, value);
			break;
		default:
			break;
		}
	}

	unsigned long long ans = 0;

	for (auto var : mem)
	{
		ans += var.to_ullong();
	}

	std::cout << ans << std::endl;
}

void Part1::ParseMask(std::string s)
{
	for (size_t i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case 'X':
			currentMask[i] = x;
			break;
		case '0':
			currentMask[i] = zero;
			break;
		case '1':
			currentMask[i] = one;
			break;
		default:
			break;
		}
	}
}

void Part1::ParseMem(std::string inst, std::string value)
{
	int pim = stoi(inst.substr(4, inst.size() - 5));
	std::bitset<36> v = stoi(value);
	
	for (size_t i = 0, j = 35; i < 36; i++, j-- )
	{
		switch (currentMask[j])
		{
		case x:
			mem[pim].set(i, v[i]);
			break;
		case zero:
			mem[pim].set(i, false);
			break;
		case one:
			mem[pim].set(i, true);
			break;
		default:
			break;
		}
	}
}
