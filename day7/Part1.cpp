#include "Part1.h"

void Part1::Solution(string f)
{
	ifstream file(f);

	string temp;

	vector<Bag> bags;

	// Create List of Bags
	while (getline(file, temp))
	{
		vector<string> tokens = splitString(temp, " bags contain ");
		string bagColour = tokens[0];
		tokens[1].pop_back();
		tokens = splitString(tokens[1], ", ");
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
	}

	cout << "DONE" << endl;
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

Bag::Bag(string s, vector<string> c)
{
	bagName = s;
	children = c;
}
