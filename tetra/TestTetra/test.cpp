#include "pch.h"

Point c1 = Point(0, 0, 0);
Point c2 = Point(1, 0, 0);
Point c3 = Point(0, 1, 0);
Point c4 = Point(1, 1, 0);
Point c5 = Point(0, 0, 1);
Point c6 = Point(1, 0, 1);
Point c7 = Point(0, 1, 1);
Point c8 = Point(1, 1, 1);
Point edges[] = { c1,c2,c3,c4,c5,c6,c7,c8 };

TEST(TestDefaultTetraPacker, ShouldAcceptPointInTheMiddle) {
    TetraPacker domain = TetraPacker(edges);
    Point test = Point(0.5, 0.5, 0.5);
    EXPECT_EQ(test.strRepresentation, "(0.500000, 0.500000, 0.500000)");
    //EXPECT_TRUE(domain.contains(test));
}