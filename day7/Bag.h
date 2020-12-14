#pragma once
#include <string>
#include <vector>

using namespace std;

class Bag
{
public:
	Bag();
	Bag(string s, vector<string> c);

	string bagName;
	vector<string> children;
	vector<Bag*> childrenPtr;
	vector<Bag*> parentPtr;
};
