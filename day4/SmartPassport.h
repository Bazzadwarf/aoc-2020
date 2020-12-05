#pragma once
#include "Passport.h"
class SmartPassport : public Passport
{
public:
	SmartPassport() {};

protected:

	virtual void ParseBirthYear(string s) override;
	virtual void ParseIssueYear(string s) override;
	virtual void ParseExpirationYear(string s) override;
	virtual void ParseHeight(string s) override;
	virtual void ParseHairColor(string s) override;
	virtual void ParseEyeColor(string s) override;
	virtual void ParsePassportID(string s) override;
	virtual void ParseCountryID(string s) override;
};

