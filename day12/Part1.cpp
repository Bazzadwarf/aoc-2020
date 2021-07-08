#include "Part1.h"

void Part1::Solution(std::string f)
{
	Ship ship;

	std::ifstream file(f);

	std::string temp;

	std::vector<std::string> instructions = std::vector<std::string>();

	while (file >> temp)
	{
		instructions.push_back(temp);
	}

	for (size_t i = 0; i < instructions.size(); i++)
	{
		switch (instructions[i].at(0))
		{
		case 'N':
			MoveNorth(ship, stoi(instructions[i].substr(1)));
			break;
		case 'S':
			MoveSouth(ship, stoi(instructions[i].substr(1)));
			break;
		case 'E':
			MoveEast(ship, stoi(instructions[i].substr(1)));
			break;
		case 'W':
			MoveWest(ship, stoi(instructions[i].substr(1)));
			break;
		case 'L':
			TurnLeft(ship, stoi(instructions[i].substr(1)));
			break;
		case 'R':
			TurnRight(ship, stoi(instructions[i].substr(1)));
			break;
		case 'F':
			MoveForward(ship, stoi(instructions[i].substr(1)));
			break;
		default:
			break;
		}
	}

	std::cout << "Current Position: x " << ship.x << ", y " << ship.y << std::endl;
	std::cout << "The ship's Manhattan distance: " << abs(ship.x) + abs(ship.y) << std::endl;
}

void Part1::MoveNorth(Ship& s, int n)
{
	s.y += n;
}

void Part1::MoveSouth(Ship& s, int n)
{
	s.y -= n;
}

void Part1::MoveEast(Ship& s, int n)
{
	s.x += n;
}

void Part1::MoveWest(Ship& s, int n)
{
	s.x -= n;
}

void Part1::TurnLeft(Ship& s, int n)
{
	if (s.facing - n >= 0)
	{
		s.facing = static_cast<Direction>((s.facing - n) % 360);
	}
	else
	{
		s.facing = static_cast<Direction>(((s.facing - n) % 360) + 360);
	}
}

void Part1::TurnRight(Ship& s, int n)
{
	s.facing = static_cast<Direction>((s.facing + n) % 360);
}

void Part1::MoveForward(Ship& s, int n)
{
	switch (s.facing)
	{
	case Direction::North:
		MoveNorth(s, n);
		break;
	case Direction::South:
		MoveSouth(s, n);
		break;
	case Direction::East:
		MoveEast(s, n);
		break;
	case Direction::West:
		MoveWest(s, n);
		break;
	default:
		break;
	}
}
