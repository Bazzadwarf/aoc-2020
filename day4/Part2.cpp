#include "Part2.h"

void Part2::Solution(string f)
{
	vector<SmartPassport> passports = vector<SmartPassport>();

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
			SmartPassport newPassport = SmartPassport();
			newPassport.ParseData(tempPassport);
			passports.push_back(newPassport);
			tempPassport.clear();
		}
	}

	SmartPassport newPassport = SmartPassport();
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
