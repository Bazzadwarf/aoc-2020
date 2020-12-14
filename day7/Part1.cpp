#include "Part1.h"

void Part1::Solution(std::string f)
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

	int result = 0;

	std::vector<Bag*> b;

	checkBags(&result, &b, shinyGold);

	std::cout << "Answer: " << result << std::endl;
}

std::vector<std::string> Part1::splitString(std::string s, const std::string delimiter)
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

void Part1::checkBags(int* c, std::vector<Bag*>* bags, Bag* b)
{
	for (size_t i = 0; i < b->parentPtr.size(); i++)
	{
		if (find(bags->begin(),bags->end(),b->parentPtr[i]) == bags->end())
		{
			bags->push_back(b->parentPtr[i]);
			(*c)++;
			checkBags(c, bags, b->parentPtr[i]);
		}
	}
}
