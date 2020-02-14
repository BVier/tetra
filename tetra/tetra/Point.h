#pragma once
#include <string>

struct Point
{
	double x = 0;
	double y = 0;
	double z = 0;
	std::string strRepresentation="";
	Point() {};
	Point(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->strRepresentation = "(" + std::to_string(x) + ", "
			+ std::to_string(y) + ", "
			+ std::to_string(z) + ")";;
	}
	std::string toString();
};


Point subtract(Point p1, Point p2);
Point add(Point p1, Point p2);
Point computeNorm(Point p1, Point p2, Point p3);
Point cross(Point p1, Point p2);
double dot(Point p1, Point p2);
double euclid(Point p1);
