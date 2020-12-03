#include "Part2.h"

void Part2::Solution(string f)
{
	vector<password> passwords = vector<password>();

	ifstream file(f);

	string bounds, testchar, pass;

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

	cout << validPasswords << endl;
}

password Part2::ParsePassword(string bounds, string tchar, string p)
{
	char* nextToken;
	char* token = strtok_s(_strdup(bounds.c_str()), "-", &nextToken);

	return password(stoi(token), stoi(nextToken), tchar[0], p);
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