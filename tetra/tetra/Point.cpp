#include "Point.h"
#include <math.h>


Point subtract(Point p1, Point p2) {
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	double z = p1.z - p2.z;
	return Point(x, y, z);
}

Point add(Point p1, Point p2) {
	double x = p1.x + p2.x;
	double y = p1.y + p2.y;
	double z = p1.z + p2.z;
	return Point(x, y, z);
}

Point computeNorm(Point p1, Point p2, Point p3) {
	Point v1 = subtract(p2, p1);
	Point v2 = subtract(p1, p3);
	Point c = cross(v2, v1);
	double euclideanDist = euclid(c);
	c.x /= euclideanDist;
	c.y /= euclideanDist;
	c.z /= euclideanDist;
	return c;
}
Point cross(Point v1, Point v2) {
	double x = v1.y * v2.z - v1.z * v2.y;
	double y = v1.z * v2.x - v1.x * v2.z;
	double z = v1.x * v2.y - v1.y * v2.x;
	return Point(x, y, z);
}

double dot(Point p1, Point p2)
{
	return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

double euclid(Point p)
{
	return sqrt(pow(p.x, 2) + pow(p.y, 2) + pow(p.z, 2));
}

std::string Point::toString() {
	return "(" + std::to_string(this->x) + ", "
		+ std::to_string(this->y) + ", "
		+ std::to_string(this->z) + ")";
}
