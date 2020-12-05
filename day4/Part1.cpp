#include "Part1.h"

void Part1::Solution(string f)
{
	vector<Passport> passports = vector<Passport>();

	ifstream file(f);

	string input, tempPassport;

	while (getline(file, input))
	{
		if (input != "")
		{
			tempPassport.append(input + " ");
		}
		else
		{
			Passport newPassport = Passport();
			newPassport.ParseData(tempPassport);
			passports.push_back(newPassport);
			tempPassport.clear();
		}
	}

	Passport newPassport = Passport();
	newPassport.ParseData(tempPassport);
	passports.push_back(newPassport);
	tempPassport.clear();

	size_t length = passports.size();
	int num = 0;

	for (size_t i = 0; i < length; i++)
	{
		num += passports[i].ValidatePassport();
	}

	cout << "Number of valid passports: " << num << endl;
}

