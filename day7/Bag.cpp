#include "Bag.h"

Bag::Bag()
{
}

Bag::Bag(std::string s, std::vector<std::string> c)
{
	bagName = s;
	children = c;
}