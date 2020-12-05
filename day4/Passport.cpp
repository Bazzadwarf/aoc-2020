#include "Passport.h"

void Passport::ParseData(string s)
{
	char* nextToken = _strdup(s.c_str());
	vector<char*> fields = vector<char*>();

	while (strlen(nextToken) != 0)
	{
		fields.push_back(strtok_s(nextToken, " ", &nextToken));
	}

	size_t length = fields.size();

	for (size_t i = 0; i < length; i++)
	{
		field f = GetFieldEnum((string)strtok_s(fields[i], ":", &nextToken));

		switch (f)
		{
		case field::byr:
			ParseBirthYear(nextToken);
			break;
		case field::iyr:
			ParseIssueYear(nextToken);
			break;
		case field::eyr:
			ParseExpirationYear(nextToken);
			break;
		case field::hgt:
			ParseHeight(nextToken);
			break;
		case field::hcl:
			ParseHairColor(nextToken);
			break;
		case field::ecl:
			ParseEyeColor(nextToken);
			break;
		case field::pid:
			ParsePassportID(nextToken);
			break;
		case field::cid:
			ParseCountryID(nextToken);
			break;
		default:
			break;
		}
	}
}

bool Passport::ValidatePassport()
{
	if (birthYear == ""
		|| issueYear == ""
		|| expirationYear == ""
		|| height == ""
		|| hairColor == ""
		|| eyeColor == ""
		|| passportID == "")
	{
		return false;
	}

	return true;
}

void Passport::ParseBirthYear(string s)
{
	birthYear = s;
}

void Passport::ParseIssueYear(string s)
{
	issueYear = s;
}

void Passport::ParseExpirationYear(string s)
{
	expirationYear = s;
}

void Passport::ParseHeight(string s)
{
	height = s;
}

void Passport::ParseHairColor(string s)
{
	hairColor = s;
}

void Passport::ParseEyeColor(string s)
{
	eyeColor = s;
}

void Passport::ParsePassportID(string s)
{
	passportID = s;
}

void Passport::ParseCountryID(string s)
{
	countryID = s;
}

field Passport::GetFieldEnum(string s)
{
	if (s == "byr") return field::byr;
	if (s == "iyr") return field::iyr;
	if (s == "eyr") return field::eyr;
	if (s == "hgt") return field::hgt;
	if (s == "hcl") return field::hcl;
	if (s == "ecl") return field::ecl;
	if (s == "pid") return field::pid;
	if (s == "cid") return field::cid;

	return field();
}

void Passport::Print()
{
	if (birthYear != "") std::cout << "byr:" << birthYear << " ";
	if (issueYear != "") std::cout << "iyr:" << issueYear << " ";
	if (expirationYear != "") std::cout << "eyr:" << expirationYear << " ";
	if (height != "") std::cout << "hgt:" << height << " ";
	if (hairColor != "") std::cout << "hcl:" << hairColor << " ";
	if (eyeColor != "")	std::cout << "ecl:" << eyeColor << " ";
	if (passportID != "") std::cout << "pid:" << passportID << " ";
	if (countryID != "") std::cout << "cid:" << countryID << " ";

	std::cout << endl;
}
