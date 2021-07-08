#pragma once

enum Direction {
	North = 0, East = 90, South = 180, West = 270
};

typedef struct Ship {
	Direction facing = Direction::East;
	int x = 0;
	int y = 0;
};

typedef struct Waypoint {
	int x = 10;
	int y = 1;
};