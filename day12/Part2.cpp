#include "Part2.h"

void Part2::Solution(std::string f)
{
	Ship ship;

	Waypoint waypoint;

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
			MoveWaypointNorth(waypoint, stoi(instructions[i].substr(1)));
			break;
		case 'S':
			MoveWaypointSouth(waypoint, stoi(instructions[i].substr(1)));
			break;
		case 'E':
			MoveWaypointEast(waypoint, stoi(instructions[i].substr(1)));
			break;
		case 'W':
			MoveWaypointWest(waypoint, stoi(instructions[i].substr(1)));
			break;
		case 'L':
			TurnWaypointLeft(waypoint, stoi(instructions[i].substr(1)));
			break;
		case 'R':
			TurnWaypointRight(waypoint, stoi(instructions[i].substr(1)));
			break;
		case 'F':
			MoveTowardsWaypoint(waypoint, ship, stoi(instructions[i].substr(1)));
			break;
		default:
			break;
		}
	}

	std::cout << "Current Position: x " << ship.x << ", y " << ship.y << std::endl;
	std::cout << "The ship's Manhattan distance: " << abs(ship.x) + abs(ship.y) << std::endl;
}

void Part2::MoveWaypointNorth(Waypoint& w, int n)
{
	w.y += n;
}

void Part2::MoveWaypointSouth(Waypoint& w, int n)
{
	w.y -= n;
}

void Part2::MoveWaypointEast(Waypoint& w, int n)
{
	w.x += n;
}

void Part2::MoveWaypointWest(Waypoint& w, int n)
{
	w.x -= n;
}

void Part2::TurnWaypointLeft(Waypoint& w, int n)
{
	int newx, newy;
	switch (n)
	{
	case 90:
		newx = w.y * -1;
		newy = w.x;
		w.x = newx;
		w.y = newy;
		return;
	case 180:
		w.x *= -1;
		w.y *= -1;
		return;
	case 270:
		newx = w.y;
		newy = w.x * -1;
		w.x = newx;
		w.y = newy;
		return;
	default:
		break;
	}
}

void Part2::TurnWaypointRight(Waypoint& w, int n)
{
	int newx, newy;
	switch (n)
	{
	case 90:
		newx = w.y;
		newy = w.x * -1;
		w.x = newx;
		w.y = newy;
		return;
	case 180:
		w.x *= -1;
		w.y *= -1;
		return;
	case 270:
		newx = w.y * -1;
		newy = w.x;
		w.x = newx;
		w.y = newy;
		return;
	default:
		break;
	}
}

void Part2::MoveTowardsWaypoint(Waypoint& w, Ship& s, int n)
{
	s.x += (w.x * n);
	s.y += (w.y * n);
}
