#include "Part2.h"

void Part2::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<Bag> bags;
	Bag* shinyGold = nullptr;

	// Create List of Bags
	while (getline(file, temp))
	{
		std::vector<std::string> tokens = splitString(temp, " bags contain ");
		std::string bagColour = tokens[0];
		tokens[1].pop_back();
		tokens = splitString(tokens[1], ", ");

		if (tokens[0] == "no other bags")
		{
			tokens.clear();
		}

		bags.push_back(Bag(bagColour, tokens));
	}

	// Point bags to other bags
	for (size_t i = 0; i < bags.size(); i++)
	{
		for (size_t j = 0; j < bags[i].children.size(); j++)
		{
			for (size_t k = 0; k < bags.size(); k++)
			{
				if (bags[i].children[j].find(bags[k].bagName) != std::string::npos)
				{
					bags[i].childrenPtr.push_back(&bags[k]);
					bags[k].parentPtr.push_back(&bags[i]);
				}
			}
		}

		if (bags[i].bagName == "shiny gold")
		{
			shinyGold = &bags[i];
		}
	}

	std::cout << "Answer: " << checkBags(shinyGold) << std::endl;
}

std::vector<std::string> Part2::splitString(std::string s, const std::string delimiter)
{
	std::vector<std::string> strings = std::vector<std::string>();
	int pos;

	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		strings.push_back(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
	}

	strings.push_back(s);

	return strings;
}

int Part2::checkBags(Bag* b)
{
	int instancesOfBag = 0;
	for (size_t i = 0; i < b->childrenPtr.size(); i++)
	{
		instancesOfBag += (b->children[i].front() - '0');
		instancesOfBag += (b->children[i].front() - '0') * checkBags(b->childrenPtr[i]);
	}

	return instancesOfBag;
}
