#include "SmartPassport.h"


void SmartPassport::ParseBirthYear(std::string s)
{
	int y = stoi(s);
	if (y >= 1920 && y <= 2002)
	{
		birthYear = s;
	}
}

void SmartPassport::ParseIssueYear(std::string s)
{
	int y = stoi(s);
	if (y >= 2010 && y <= 2020)
	{
		issueYear = s;
	}
}

void SmartPassport::ParseExpirationYear(std::string s)
{
	int y = stoi(s);
	if (y >= 2020 && y <= 2030)
	{
		expirationYear = s;
	}
}

void SmartPassport::ParseHeight(std::string s)
{
	if (s.find("cm") != std::string::npos)
	{
		std::string temp = s;
		temp.resize(s.size() - 2);
		int h = stoi(temp);
		if (h >= 150 && h <= 193)
		{
			height = s;
		}
	}

	if (s.find("in") != std::string::npos)
	{
		std::string temp = s;
		temp.resize(s.size() - 2);
		int h = stoi(temp);
		if (h >= 59 && h <= 76)
		{
			height = s;
		}
	}
}

void SmartPassport::ParseHairColor(std::string s)
{
	if (s[0] == '#' && s.find_first_not_of("0123456789abcdefABCDEF", 1) == std::string::npos)
	{
		hairColor = s;
	}
}

void SmartPassport::ParseEyeColor(std::string s)
{
	if (s == "amb" ||
		s == "blu" ||
		s == "brn" ||
		s == "gry" ||
		s == "grn" ||
		s == "hzl" ||
		s == "oth")
	{
		eyeColor = s;
	}
}

void SmartPassport::ParsePassportID(std::string s)
{
	if (s.size() == 9)
	{
		passportID = s;
	}
}

void SmartPassport::ParseCountryID(std::string s)
{
	countryID = s;
}
