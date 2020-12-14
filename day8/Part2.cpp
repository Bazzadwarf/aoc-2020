#include "Part2.h"

void Part2::Solution(std::string f)
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

	int answer = 0;

	for (size_t i = 0; i < program.size(); i++)
	{
		if (program[i].instruction != inst::acc)
		{
			flipInstruction(&program[i]);
		}

		answer = execute(program);

		if (answer == -1)
		{
			flipInstruction(&program[i]);
		}
		else
		{
			std::cout << "Answer: " << answer << std::endl;
			break;
		}
	}	
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

int Part2::execute(std::vector<Line> program)
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

		if (i >= program.size())
		{
			break;
		}
	}

	if (i != program.size())
	{
		return -1;
	}

	return accumulator;
}

void Part2::flipInstruction(Line* line)
{
	if (line->instruction == inst::jmp)
	{
		line->instruction = inst::nop;
	}
	else if (line->instruction == inst::nop)
	{
		line->instruction = inst::jmp;
	}
}
