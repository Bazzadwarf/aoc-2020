#pragma once
#include <string>
#include <vector>


class Bag
{
public:
	Bag();
	Bag(std::string s, std::vector<std::string> c);

	std::string bagName;
	std::vector<std::string> children;
	std::vector<Bag*> childrenPtr;
	std::vector<Bag*> parentPtr;
};
