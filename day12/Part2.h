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
	// Ship Commands
	static void MoveShipNorth(Ship& s, int n);
	static void MoveShipSouth(Ship& s, int n);
	static void MoveShipEast(Ship& s, int n);
	static void MoveShipWest(Ship& s, int n);
	static void TurnShipLeft(Ship& s, int n);
	static void TurnShipRight(Ship& s, int n);
	static void MoveShipForward(Ship& s, int n);

	//Waypoint Commands
	static void MoveWaypointNorth(Waypoint& w, int n);
	static void MoveWaypointSouth(Waypoint& w, int n);
	static void MoveWaypointEast(Waypoint& w, int n);
	static void MoveWaypointWest(Waypoint& w, int n);
	static void TurnWaypointLeft(Waypoint& w, int n);
	static void TurnWaypointRight(Waypoint& w, int n);
	static void MoveTowardsWaypoint(Waypoint& w, Ship& s, int n);
};
