#include "Part2.h"

void Part2::Solution(std::string f)
{
	std::vector<password> passwords = std::vector<password>();

	std::ifstream file(f);

	std::string bounds, testchar, pass;

	while (file >> bounds)
	{
		file >> testchar;
		file >> pass;
		passwords.push_back(ParsePassword(bounds, testchar, pass));
	}

	file.close();
	passwords.shrink_to_fit();

	int validPasswords = 0;
	int length = passwords.size();

	for (size_t i = 0; i < length; i++)
	{
		validPasswords += VerifyPassword(&passwords[i]);
	}

	std::cout << validPasswords << std::endl;
}

password Part2::ParsePassword(std::string bounds, std::string tchar, std::string p)
{
	char* nextToken;
	char* token = strtok_s(_strdup(bounds.c_str()), "-", &nextToken);

	return password(std::stoi(token), std::stoi(nextToken), tchar[0], p);
}

bool Part2::VerifyPassword(password* p)
{
	if (p->pass[p->lowerBound - 1] == p->testchar || p->pass[p->upperBound - 1] == p->testchar)
	{
		if (p->pass[p->lowerBound - 1] != p->pass[p->upperBound - 1])
		{
			return true;
		}		
	}

	return false;
}