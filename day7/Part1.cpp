#include "Part1.h"

void Part1::Solution(string f)
{
	ifstream file(f);

	string temp;

	vector<Bag> bags;
	Bag* shinyGold = nullptr;

	// Create List of Bags
	while (getline(file, temp))
	{
		vector<string> tokens = splitString(temp, " bags contain ");
		string bagColour = tokens[0];
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
				if (bags[i].children[j].find(bags[k].bagName) != string::npos)
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

	vector<Bag*> b;

	checkBags(&result, &b, shinyGold);

	cout << "Answer: " << result << endl;
}

vector<string> Part1::splitString(string s, const string delimiter)
{
	vector<string> strings = vector<string>();
	int pos;

	while ((pos = s.find(delimiter)) != string::npos)
	{
		strings.push_back(s.substr(0, pos));
		s.erase(0, pos + delimiter.length());
	}

	strings.push_back(s);

	return strings;
}

void Part1::checkBags(int* c, vector<Bag*>* bags, Bag* b)
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
