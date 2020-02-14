#pragma once
#include <string>
#include "Point.h"

struct Tetra
{
	Point norms[4] = {};
	double references[4] = {};
	Point refPoints[2] = {};
	bool valid = false;
	Tetra() {};
	Tetra(Point p1, Point p2, Point p3, Point p4);
	bool contains(Point p);
};

class TetraPacker
{
private:
	int edgeOrder[6] = { 1, 3, 2, 6, 4, 5 };
	Tetra tetras[6] = {};
public:
	TetraPacker(Point edges[]);
	bool contains(Point);
};
