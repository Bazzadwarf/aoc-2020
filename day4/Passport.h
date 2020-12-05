#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Fields.h"

using namespace std;

class Passport
{

public:
	Passport() {};

	virtual void ParseData(string s);
	virtual bool ValidatePassport();

protected:

	virtual void ParseBirthYear(string s);
	virtual void ParseIssueYear(string s);
	virtual void ParseExpirationYear(string s);
	virtual void ParseHeight(string s);
	virtual void ParseHairColor(string s);
	virtual void ParseEyeColor(string s);
	virtual void ParsePassportID(string s);
	virtual void ParseCountryID(string s);

	virtual field GetFieldEnum(string s);
	virtual void Print();

	string birthYear;
	string issueYear;
	string expirationYear;
	string height;
	string hairColor;
	string eyeColor;
	string passportID;
	string countryID;
};