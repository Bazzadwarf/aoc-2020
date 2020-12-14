#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Fields.h"


class Passport
{

public:
	Passport() {};

	virtual void ParseData(std::string s);
	virtual bool ValidatePassport();

protected:

	virtual void ParseBirthYear(std::string s);
	virtual void ParseIssueYear(std::string s);
	virtual void ParseExpirationYear(std::string s);
	virtual void ParseHeight(std::string s);
	virtual void ParseHairColor(std::string s);
	virtual void ParseEyeColor(std::string s);
	virtual void ParsePassportID(std::string s);
	virtual void ParseCountryID(std::string s);

	virtual field GetFieldEnum(std::string s);
	virtual void Print();

	std::string birthYear;
	std::string issueYear;
	std::string expirationYear;
	std::string height;
	std::string hairColor;
	std::string eyeColor;
	std::string passportID;
	std::string countryID;
};