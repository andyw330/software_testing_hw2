#include "triangle.h"
#include "gtest/gtest.h"

// Tests triangle(). (upper bound 200)

// Boundary Value Testing
// Normal
TEST(TriangleTest, NormalBoundary) {
  EXPECT_STREQ("Isosceles", triangle(100, 100, 1));
  EXPECT_STREQ("Isosceles", triangle(100, 100, 2));
  EXPECT_STREQ("Equilateral", triangle(100, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(100, 100, 199));
  EXPECT_STREQ("NotATriangle", triangle(100, 100, 200));
  EXPECT_STREQ("Isosceles", triangle(100, 1, 100));
  EXPECT_STREQ("Isosceles", triangle(100, 2, 100));
  EXPECT_STREQ("Equilateral", triangle(100, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(100, 199, 100));
  EXPECT_STREQ("NotATriangle", triangle(100, 200, 100));
  EXPECT_STREQ("Isosceles", triangle(1, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(2, 100, 100));
  EXPECT_STREQ("Equilateral", triangle(100, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(199, 100, 100));
  EXPECT_STREQ("NotATriangle", triangle(200, 100, 100));
}
// Robust
TEST(TriangleTest, RobustBoundary) {
  EXPECT_STREQ("Value of c is not in the range of permitted values", triangle(100, 100, 0));
  EXPECT_STREQ("Isosceles", triangle(100, 100, 1));
  EXPECT_STREQ("Isosceles", triangle(100, 100, 2));
  EXPECT_STREQ("Equilateral", triangle(100, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(100, 100, 199));
  EXPECT_STREQ("NotATriangle", triangle(100, 100, 200));
  EXPECT_STREQ("Value of c is not in the range of permitted values", triangle(100, 100, 201));

  EXPECT_STREQ("Value of b is not in the range of permitted values", triangle(100, 0, 100));
  EXPECT_STREQ("Isosceles", triangle(100, 1, 100));
  EXPECT_STREQ("Isosceles", triangle(100, 2, 100));
  EXPECT_STREQ("Equilateral", triangle(100, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(100, 199, 100));
  EXPECT_STREQ("NotATriangle", triangle(100, 200, 100));
  EXPECT_STREQ("Value of b is not in the range of permitted values", triangle(100, 201, 100));

  EXPECT_STREQ("Value of a is not in the range of permitted values", triangle(0, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(1, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(2, 100, 100));
  EXPECT_STREQ("Equilateral", triangle(100, 100, 100));
  EXPECT_STREQ("Isosceles", triangle(199, 100, 100));
  EXPECT_STREQ("NotATriangle", triangle(200, 100, 100));
  EXPECT_STREQ("Value of a is not in the range of permitted values", triangle(201, 100, 100));
}

// Equivalence Class Testing
// Weak Normal (, Strong Normal)
TEST(TriangleTest, EquivalenceWN) {
  EXPECT_STREQ("Equilateral", triangle(5, 5, 5));
  EXPECT_STREQ("Isosceles", triangle(2, 2, 3));
  EXPECT_STREQ("Scalene", triangle(3, 4, 5));
  EXPECT_STREQ("NotATriangle", triangle(4, 1, 2));
}
// Weak Robust
TEST(TriangleTest, EquivalenceWR) {
  EXPECT_STREQ("Value of a is not in the range of permitted values", triangle(-1, 5, 5));
  EXPECT_STREQ("Value of b is not in the range of permitted values", triangle(5, -1, 5));
  EXPECT_STREQ("Value of c is not in the range of permitted values", triangle(5, 5, -1));
  EXPECT_STREQ("Value of a is not in the range of permitted values", triangle(201, 5, 5));
  EXPECT_STREQ("Value of b is not in the range of permitted values", triangle(5, 201, 5));
  EXPECT_STREQ("Value of c is not in the range of permitted values", triangle(5, 5, 201));
}
// Strong Robust
TEST(TriangleTest, EquivalenceSR) {
  EXPECT_STREQ("Value of a is not in the range of permitted values", triangle(-1, 5, 5));
  EXPECT_STREQ("Value of b is not in the range of permitted values", triangle(5, -1, 5));
  EXPECT_STREQ("Value of c is not in the range of permitted values", triangle(5, 5, -1));
  EXPECT_STREQ("Value of a,b is not in the range of permitted values", triangle(-1, -1, 5));
  EXPECT_STREQ("Value of a,c is not in the range of permitted values", triangle(-1, 5, -1));
  EXPECT_STREQ("Value of b,c is not in the range of permitted values", triangle(5, -1, -1));
  EXPECT_STREQ("Value of a,b,c is not in the range of permitted values", triangle(-1, -1, -1));
  EXPECT_STREQ("Value of a is not in the range of permitted values", triangle(205, 195, 195));
  EXPECT_STREQ("Value of b is not in the range of permitted values", triangle(195, 205, 195));
  EXPECT_STREQ("Value of c is not in the range of permitted values", triangle(195, 195, 205));
  EXPECT_STREQ("Value of a,b is not in the range of permitted values", triangle(205, 205, 195));
  EXPECT_STREQ("Value of a,c is not in the range of permitted values", triangle(205, 195, 205));
  EXPECT_STREQ("Value of b,c is not in the range of permitted values", triangle(195, 205, 205));
  EXPECT_STREQ("Value of a,b,c is not in the range of permitted values", triangle(205, 205, 205));
}

// Edge Testing
// Normal
TEST(TriangleTest, EdgeNormal) {
  EXPECT_STREQ("Equilateral", triangle(1, 1, 1));
  EXPECT_STREQ("Equilateral", triangle(200, 200, 200));
  EXPECT_STREQ("Isosceles", triangle(1, 2, 2));
  EXPECT_STREQ("Isosceles", triangle(200, 200, 199));
  EXPECT_STREQ("Scalene", triangle(2, 3, 4));
  EXPECT_STREQ("Scalene", triangle(200, 199, 198));
  EXPECT_STREQ("NotATriangle", triangle(1, 1, 2));
  EXPECT_STREQ("NotATriangle", triangle(200, 199, 1));
}
// Robust
TEST(TriangleTest, EdgeRobust) {
  EXPECT_STREQ("Value of a is not in the range of permitted values", triangle(-1, 1, 1));
  EXPECT_STREQ("Value of b is not in the range of permitted values", triangle(1, -1, 1));
  EXPECT_STREQ("Value of c is not in the range of permitted values", triangle(1, 1, -1));
  EXPECT_STREQ("Value of a,b is not in the range of permitted values", triangle(-1, -1, 1));
  EXPECT_STREQ("Value of a,c is not in the range of permitted values", triangle(-1, 1, -1));
  EXPECT_STREQ("Value of b,c is not in the range of permitted values", triangle(1, -1, -1));
  EXPECT_STREQ("Value of a,b,c is not in the range of permitted values", triangle(-1, -1, -1));
  EXPECT_STREQ("Value of a is not in the range of permitted values", triangle(201, 200, 200));
  EXPECT_STREQ("Value of b is not in the range of permitted values", triangle(200, 201, 200));
  EXPECT_STREQ("Value of c is not in the range of permitted values", triangle(200, 200, 201));
  EXPECT_STREQ("Value of a,b is not in the range of permitted values", triangle(201, 201, 200));
  EXPECT_STREQ("Value of a,c is not in the range of permitted values", triangle(201, 200, 201));
  EXPECT_STREQ("Value of b,c is not in the range of permitted values", triangle(200, 201, 201));
  EXPECT_STREQ("Value of a,b,c is not in the range of permitted values", triangle(201, 201, 201));
}

// Decision Table Testing
TEST(TriangleTest, DecisionTable) {
  EXPECT_STREQ("NotATriangle", triangle(4, 1, 2));
  EXPECT_STREQ("NotATriangle", triangle(1, 4, 2));
  EXPECT_STREQ("NotATriangle", triangle(1, 2, 4));
  EXPECT_STREQ("Equilateral", triangle(5, 5, 5));
  EXPECT_STREQ("Isosceles", triangle(2, 2, 3));
  EXPECT_STREQ("Isosceles", triangle(2, 3, 2));
  EXPECT_STREQ("Isosceles", triangle(3, 2, 2));
  EXPECT_STREQ("Scalene", triangle(3, 4, 5));
}
