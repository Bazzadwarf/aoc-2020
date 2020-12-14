#include "Part1.h"

void Part1::Solution(std::string f)
{
	std::ifstream file(f);

	std::string temp;

	std::vector<Line> program = std::vector<Line>();

	static std::unordered_map<std::string, inst> const table = { {"acc", inst::acc}, {"jmp",inst::jmp}, {"nop",inst::nop} };

	while (getline(file, temp))
	{
		std::vector<std::string> tokens = splitString(temp, " ");

		program.push_back({ table.find(tokens[0])->second , stoi(tokens[1]) });
	}

	std::cout << "Answer: " << execute(program) << std::endl;
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

int Part1::execute(std::vector<Line> program)
{
	int accumulator = 0;
	int i = 0;
	
	while (!program[i].prevExecuted && i < program.size())
	{
		program[i].prevExecuted = true;

		switch (program[i].instruction)
		{
		case inst::acc:
			accumulator += program[i].value;
			i++;
			break;
		case inst::jmp:
			i += program[i].value;
			break;
		case inst::nop:
			i++;
			break;
		default:
			i++;
			break;
		}
	}
	return accumulator;
}
