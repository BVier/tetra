// tetra.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TetraPacker.h"
#include "Point.h"

int main()
{
    std::cout << "Hello World!\n";
	Point c1 = Point(0, 0, 0);
	Point c2 = Point(1, 0, 0);
	Point c3 = Point(0, 1, 0);
	Point c4 = Point(1, 1, 0);
	Point c5 = Point(0, 0, 1);
	Point c6 = Point(1, 0, 1);
	Point c7 = Point(0, 1, 1);
	Point c8 = Point(1, 1, 1);
	Point edges[] = { c1,c2,c3,c4,c5,c6,c7,c8 };

	TetraPacker tetra = TetraPacker(edges);

	Point test = Point(0.5, 0.5, 0.5);
	std::cout << "contains " << test.strRepresentation << ": ";
	std::cout << tetra.contains(test) << "\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
