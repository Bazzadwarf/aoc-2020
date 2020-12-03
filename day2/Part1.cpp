#include "Part1.h"

void Part1::Solution(string f)
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

password Part1::ParsePassword(string bounds, string tchar, string p)
{
	char* nextToken;
	char* token = strtok_s(_strdup(bounds.c_str()), "-", &nextToken);

	return password(stoi(token), stoi(nextToken), tchar[0], p);
}

bool Part1::VerifyPassword(password* p)
{
	int occurances = count(p->pass.begin(), p->pass.end(), p->testchar);

	if (occurances >= p->lowerBound && occurances <= p->upperBound)
	{
		return true;
	}
	return false;
}
