#pragma once
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Shared.h"

class Part2
{
public:
	static void Solution(std::string f);

private:
	static void MoveWaypointNorth(Waypoint& w, int n);
	static void MoveWaypointSouth(Waypoint& w, int n);
	static void MoveWaypointEast(Waypoint& w, int n);
	static void MoveWaypointWest(Waypoint& w, int n);
	static void TurnWaypointLeft(Waypoint& w, int n);
	static void TurnWaypointRight(Waypoint& w, int n);
	static void MoveTowardsWaypoint(Waypoint& w, Ship& s, int n);
};
