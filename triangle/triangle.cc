#include "triangle.h"

// Returns triangle type. (upper bound 200)
const char* triangle(int a, int b, int c) {
  int a_out_range = (a < 1 || a > 200);
  int b_out_range = (b < 1 || b > 200);
  int c_out_range = (c < 1 || c > 200);

  if (a_out_range && !b_out_range && !c_out_range)
    return "Value of a is not in the range of permitted values";
  else if (!a_out_range && b_out_range && !c_out_range)
    return "Value of b is not in the range of permitted values";
  else if (!a_out_range && !b_out_range && c_out_range)
    return "Value of c is not in the range of permitted values";
  else if (a_out_range && b_out_range && !c_out_range)
    return "Value of a,b is not in the range of permitted values";
  else if (a_out_range && !b_out_range && c_out_range)
    return "Value of a,c is not in the range of permitted values";
  else if (!a_out_range && b_out_range && c_out_range)
    return "Value of b,c is not in the range of permitted values";
  else if (a_out_range && b_out_range && c_out_range)
    return "Value of a,b,c is not in the range of permitted values";

  if (a + b <= c || b + c <= a || c + a <= b) {
    return "NotATriangle";
  }

  if (a == b && b == c)
    return "Equilateral";
  else if (a != b && a != c && b != c)
    return "Scalene";
  else
    return "Isosceles";
}
