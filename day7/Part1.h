#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Bag
{
public:
	Bag(string s, vector<string> c);

	string bagName;
	vector<string> children;
	vector<Bag*> childrenPtr;
	vector<Bag*> parentPtr;
};

class Part1
{
public:
	static void Solution(string f);

private:
	static vector<string> splitString(string s, const string delimiter);

};

