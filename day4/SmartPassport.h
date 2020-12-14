#pragma once
#include "Passport.h"
class SmartPassport : public Passport
{
public:
	SmartPassport() {};

protected:

	virtual void ParseBirthYear(std::string s) override;
	virtual void ParseIssueYear(std::string s) override;
	virtual void ParseExpirationYear(std::string s) override;
	virtual void ParseHeight(std::string s) override;
	virtual void ParseHairColor(std::string s) override;
	virtual void ParseEyeColor(std::string s) override;
	virtual void ParsePassportID(std::string s) override;
	virtual void ParseCountryID(std::string s) override;
};

