#include "nextdate.h"
#include "gtest/gtest.h"

// Tests nextdate().

// Boundary Value Testing
// Standard
TEST(NextdateTest, StdBoundary) {
  EXPECT_STREQ("6/16/1812", nextdate(6, 15, 1812));
  EXPECT_STREQ("6/16/1813", nextdate(6, 15, 1813));
  EXPECT_STREQ("6/16/1912", nextdate(6, 15, 1912));
  EXPECT_STREQ("6/16/2011", nextdate(6, 15, 2011));
  EXPECT_STREQ("6/16/2012", nextdate(6, 15, 2012));
  EXPECT_STREQ("6/2/1912", nextdate(6, 1, 1912));
  EXPECT_STREQ("6/3/1912", nextdate(6, 2, 1912));
  EXPECT_STREQ("7/1/1912", nextdate(6, 30, 1912));
  EXPECT_STREQ("Invalid input date", nextdate(6, 31, 1912));
  EXPECT_STREQ("1/16/1912", nextdate(1, 15, 1912));
  EXPECT_STREQ("2/16/1912", nextdate(2, 15, 1912));
  EXPECT_STREQ("11/16/1912", nextdate(11, 15, 1912));
  EXPECT_STREQ("12/16/1912", nextdate(12, 15, 1912));
}
// Worst-Case
TEST(NextdateTest, WorstCaseBoundary) {
  EXPECT_STREQ("1/2/1812", nextdate(1, 1, 1812));
  EXPECT_STREQ("1/2/1813", nextdate(1, 1, 1813));
  EXPECT_STREQ("1/2/1912", nextdate(1, 1, 1912));
  EXPECT_STREQ("1/2/2011", nextdate(1, 1, 2011));
  EXPECT_STREQ("1/2/2012", nextdate(1, 1, 2012));
  EXPECT_STREQ("1/3/1812", nextdate(1, 2, 1812));
  EXPECT_STREQ("1/3/1813", nextdate(1, 2, 1813));
  EXPECT_STREQ("1/3/1912", nextdate(1, 2, 1912));
  EXPECT_STREQ("1/3/2011", nextdate(1, 2, 2011));
  EXPECT_STREQ("1/3/2012", nextdate(1, 2, 2012));
  EXPECT_STREQ("1/16/1812", nextdate(1, 15, 1812));
  EXPECT_STREQ("1/16/1813", nextdate(1, 15, 1813));
  EXPECT_STREQ("1/16/1912", nextdate(1, 15, 1912));
  EXPECT_STREQ("1/16/2011", nextdate(1, 15, 2011));
  EXPECT_STREQ("1/16/2012", nextdate(1, 15, 2012));
  EXPECT_STREQ("1/31/1812", nextdate(1, 30, 1812));
  EXPECT_STREQ("1/31/1813", nextdate(1, 30, 1813));
  EXPECT_STREQ("1/31/1912", nextdate(1, 30, 1912));
  EXPECT_STREQ("1/31/2011", nextdate(1, 30, 2011));
  EXPECT_STREQ("1/31/2012", nextdate(1, 30, 2012));
  EXPECT_STREQ("2/1/1812", nextdate(1, 31, 1812));
  EXPECT_STREQ("2/1/1813", nextdate(1, 31, 1813));
  EXPECT_STREQ("2/1/1912", nextdate(1, 31, 1912));
  EXPECT_STREQ("2/1/2011", nextdate(1, 31, 2011));
  EXPECT_STREQ("2/1/2012", nextdate(1, 31, 2012));
  EXPECT_STREQ("2/2/1812", nextdate(2, 1, 1812));
  EXPECT_STREQ("2/2/1813", nextdate(2, 1, 1813));
  EXPECT_STREQ("2/2/1912", nextdate(2, 1, 1912));
  EXPECT_STREQ("2/2/2011", nextdate(2, 1, 2011));
  EXPECT_STREQ("2/2/2012", nextdate(2, 1, 2012));
  EXPECT_STREQ("2/3/1812", nextdate(2, 2, 1812));
  EXPECT_STREQ("2/3/1813", nextdate(2, 2, 1813));
  EXPECT_STREQ("2/3/1912", nextdate(2, 2, 1912));
  EXPECT_STREQ("2/3/2011", nextdate(2, 2, 2011));
  EXPECT_STREQ("2/3/2012", nextdate(2, 2, 2012));
  EXPECT_STREQ("2/16/1812", nextdate(2, 15, 1812));
  EXPECT_STREQ("2/16/1813", nextdate(2, 15, 1813));
  EXPECT_STREQ("2/16/1912", nextdate(2, 15, 1912));
  EXPECT_STREQ("2/16/2011", nextdate(2, 15, 2011));
  EXPECT_STREQ("2/16/2012", nextdate(2, 15, 2012));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 1812));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 1813));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 1912));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 2011));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 2012));
  EXPECT_STREQ("Invalid input date", nextdate(2, 31, 1812));
  EXPECT_STREQ("Invalid input date", nextdate(2, 31, 1813));
  EXPECT_STREQ("Invalid input date", nextdate(2, 31, 1912));
  EXPECT_STREQ("Invalid input date", nextdate(2, 31, 2011));
  EXPECT_STREQ("Invalid input date", nextdate(2, 31, 2012));
  EXPECT_STREQ("6/2/1812", nextdate(6, 1, 1812));
  EXPECT_STREQ("6/2/1813", nextdate(6, 1, 1813));
  EXPECT_STREQ("6/2/1912", nextdate(6, 1, 1912));
  EXPECT_STREQ("6/2/2011", nextdate(6, 1, 2011));
  EXPECT_STREQ("6/2/2012", nextdate(6, 1, 2012));
  EXPECT_STREQ("6/3/1812", nextdate(6, 2, 1812));
  EXPECT_STREQ("6/3/1813", nextdate(6, 2, 1813));
  EXPECT_STREQ("6/3/1912", nextdate(6, 2, 1912));
  EXPECT_STREQ("6/3/2011", nextdate(6, 2, 2011));
  EXPECT_STREQ("6/3/2012", nextdate(6, 2, 2012));
}

// Equivalence Class Testing
// M1 = { month: month has 30 days }
// M2 = { month: month has 31 days }
// M3 = { month: month is February }
// D1 = { day: 1 ≤ day ≤ 28 }
// D2 = { day: day = 29 }
// D3 = { day: day = 30 }
// D4 = { day: day = 31 }
// Y1 = { year: year = 2000 }
// Y2 = { year: year is a leap year }
// Y3 = { year: year is a common year }
// Weak Normal
TEST(NextdateTest, EquivalenceWN) {
  EXPECT_STREQ("6/15/2000", nextdate(6, 14, 2000));
  EXPECT_STREQ("7/30/1996", nextdate(7, 29, 1996));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 2002));
  EXPECT_STREQ("Invalid input date", nextdate(6, 31, 2000));
}
// Strong Normal
TEST(NextdateTest, EquivalenceSN) {
  EXPECT_STREQ("6/15/2000", nextdate(6, 14, 2000));
  EXPECT_STREQ("6/15/1996", nextdate(6, 14, 1996));
  EXPECT_STREQ("6/15/2002", nextdate(6, 14, 2002));
  EXPECT_STREQ("6/30/2000", nextdate(6, 29, 2000));
  EXPECT_STREQ("6/30/1996", nextdate(6, 29, 1996));
  EXPECT_STREQ("6/30/2002", nextdate(6, 29, 2002));
  EXPECT_STREQ("7/1/2000", nextdate(6, 30, 2000));
  EXPECT_STREQ("7/1/1996", nextdate(6, 30, 1996));
  EXPECT_STREQ("7/1/2002", nextdate(6, 30, 2002));
  EXPECT_STREQ("Invalid input date", nextdate(6, 31, 2000));
  EXPECT_STREQ("Invalid input date", nextdate(6, 31, 1996));
  EXPECT_STREQ("Invalid input date", nextdate(6, 31, 2002));
  EXPECT_STREQ("7/15/2000", nextdate(7, 14, 2000));
  EXPECT_STREQ("7/15/1996", nextdate(7, 14, 1996));
  EXPECT_STREQ("7/15/2002", nextdate(7, 14, 2002));
  EXPECT_STREQ("7/30/2000", nextdate(7, 29, 2000));
  EXPECT_STREQ("7/30/1996", nextdate(7, 29, 1996));
  EXPECT_STREQ("7/30/2002", nextdate(7, 29, 2002));
  EXPECT_STREQ("7/31/2000", nextdate(7, 30, 2000));
  EXPECT_STREQ("7/31/1996", nextdate(7, 30, 1996));
  EXPECT_STREQ("7/31/2002", nextdate(7, 30, 2002));
  EXPECT_STREQ("8/1/2000", nextdate(7, 31, 2000));
  EXPECT_STREQ("8/1/1996", nextdate(7, 31, 1996));
  EXPECT_STREQ("8/1/2002", nextdate(7, 31, 2002));
  EXPECT_STREQ("2/15/2000", nextdate(2, 14, 2000));
  EXPECT_STREQ("2/15/1996", nextdate(2, 14, 1996));
  EXPECT_STREQ("2/15/2002", nextdate(2, 14, 2002));
  EXPECT_STREQ("3/1/2000", nextdate(2, 29, 2000));
  EXPECT_STREQ("3/1/1996", nextdate(2, 29, 1996));
  EXPECT_STREQ("Invalid input date", nextdate(2, 29, 2002));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 2000));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 1996));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 2002));
  EXPECT_STREQ("Invalid input date", nextdate(2, 31, 2000));
  EXPECT_STREQ("Invalid input date", nextdate(2, 31, 1996));
  EXPECT_STREQ("Invalid input date", nextdate(2, 31, 2002));
}
// Weak Robust
TEST(NextdateTest, EquivalenceWR) {
  EXPECT_STREQ("month not in range", nextdate(-1, 14, 1912));
  EXPECT_STREQ("month not in range", nextdate(-1, 14, 1996));
  EXPECT_STREQ("month not in range", nextdate(-1, 14, 2002));
  EXPECT_STREQ("month not in range", nextdate(-1, 29, 2000));
  EXPECT_STREQ("month not in range", nextdate(-1, 29, 1996));
  EXPECT_STREQ("month not in range", nextdate(-1, 29, 2002));
  EXPECT_STREQ("month not in range", nextdate(-1, 30, 2000));
  EXPECT_STREQ("month not in range", nextdate(-1, 30, 1996));
  EXPECT_STREQ("month not in range", nextdate(-1, 30, 2002));
  EXPECT_STREQ("month not in range", nextdate(-1, 31, 2000));
  EXPECT_STREQ("month not in range", nextdate(-1, 31, 1996));
  EXPECT_STREQ("month not in range", nextdate(-1, 31, 2002));
  EXPECT_STREQ("day not in range", nextdate(6, -1, 2000));
  EXPECT_STREQ("day not in range", nextdate(6, -1, 1996));
  EXPECT_STREQ("day not in range", nextdate(6, -1, 2002));
  EXPECT_STREQ("day not in range", nextdate(7, -1, 2000));
  EXPECT_STREQ("day not in range", nextdate(7, -1, 1996));
  EXPECT_STREQ("day not in range", nextdate(7, -1, 2002));
  EXPECT_STREQ("day not in range", nextdate(2, -1, 2000));
  EXPECT_STREQ("day not in range", nextdate(2, -1, 1996));
  EXPECT_STREQ("day not in range", nextdate(2, -1, 2002));
  EXPECT_STREQ("year not in range", nextdate(6, 14, 1811));
  EXPECT_STREQ("year not in range", nextdate(6, 29, 1811));
  EXPECT_STREQ("year not in range", nextdate(6, 30, 1811));
  EXPECT_STREQ("year not in range", nextdate(6, 31, 1811));
  EXPECT_STREQ("year not in range", nextdate(7, 14, 1811));
  EXPECT_STREQ("year not in range", nextdate(7, 29, 1811));
  EXPECT_STREQ("year not in range", nextdate(7, 30, 1811));
  EXPECT_STREQ("year not in range", nextdate(7, 31, 1811));
  EXPECT_STREQ("year not in range", nextdate(2, 14, 1811));
  EXPECT_STREQ("year not in range", nextdate(2, 29, 1811));
  EXPECT_STREQ("year not in range", nextdate(2, 30, 1811));
  EXPECT_STREQ("year not in range", nextdate(2, 31, 1811));
  EXPECT_STREQ("month not in range", nextdate(13, 14, 1912));
  EXPECT_STREQ("month not in range", nextdate(13, 14, 1996));
  EXPECT_STREQ("month not in range", nextdate(13, 14, 2002));
  EXPECT_STREQ("month not in range", nextdate(13, 29, 2000));
  EXPECT_STREQ("month not in range", nextdate(13, 29, 1996));
  EXPECT_STREQ("month not in range", nextdate(13, 29, 2002));
  EXPECT_STREQ("month not in range", nextdate(13, 30, 2000));
  EXPECT_STREQ("month not in range", nextdate(13, 30, 1996));
  EXPECT_STREQ("month not in range", nextdate(13, 30, 2002));
  EXPECT_STREQ("month not in range", nextdate(13, 31, 2000));
  EXPECT_STREQ("month not in range", nextdate(13, 31, 1996));
  EXPECT_STREQ("month not in range", nextdate(13, 31, 2002));
  EXPECT_STREQ("day not in range", nextdate(6, 32, 2000));
  EXPECT_STREQ("day not in range", nextdate(6, 32, 1996));
  EXPECT_STREQ("day not in range", nextdate(6, 32, 2002));
  EXPECT_STREQ("day not in range", nextdate(7, 32, 2000));
  EXPECT_STREQ("day not in range", nextdate(7, 32, 1996));
  EXPECT_STREQ("day not in range", nextdate(7, 32, 2002));
  EXPECT_STREQ("day not in range", nextdate(2, 32, 2000));
  EXPECT_STREQ("day not in range", nextdate(2, 32, 1996));
  EXPECT_STREQ("day not in range", nextdate(2, 32, 2002));
  EXPECT_STREQ("year not in range", nextdate(6, 14, 2013));
  EXPECT_STREQ("year not in range", nextdate(6, 29, 2013));
  EXPECT_STREQ("year not in range", nextdate(6, 30, 2013));
  EXPECT_STREQ("year not in range", nextdate(6, 31, 2013));
  EXPECT_STREQ("year not in range", nextdate(7, 14, 2013));
  EXPECT_STREQ("year not in range", nextdate(7, 29, 2013));
  EXPECT_STREQ("year not in range", nextdate(7, 30, 2013));
  EXPECT_STREQ("year not in range", nextdate(7, 31, 2013));
  EXPECT_STREQ("year not in range", nextdate(2, 14, 2013));
  EXPECT_STREQ("year not in range", nextdate(2, 29, 2013));
  EXPECT_STREQ("year not in range", nextdate(2, 30, 2013));
  EXPECT_STREQ("year not in range", nextdate(2, 31, 2013));
}
// Strong Robust
TEST(NextdateTest, EquivalenceSR) {
  EXPECT_STREQ("month and day not in range", nextdate(-1, -1, 1912));
  EXPECT_STREQ("month and day not in range", nextdate(-1, -1, 1996));
  EXPECT_STREQ("month and day not in range", nextdate(-1, -1, 2002));
  EXPECT_STREQ("day and year not in range", nextdate(6, -1, 1811));
  EXPECT_STREQ("day and year not in range", nextdate(7, -1, 1811));
  EXPECT_STREQ("day and year not in range", nextdate(2, -1, 1811));
  EXPECT_STREQ("month and year not in range", nextdate(-1, 14, 1811));
  EXPECT_STREQ("month and year not in range", nextdate(-1, 29, 1811));
  EXPECT_STREQ("month and year not in range", nextdate(-1, 30, 1811));
  EXPECT_STREQ("month and day and year not in range", nextdate(-1, -1, 1811));
  // ignore upper case for now
}

// Edge Testing
// Normal
TEST(NextdateTest, EdgeN) {
  EXPECT_STREQ("1/15/1912", nextdate(1, 14, 1912));
  EXPECT_STREQ("2/15/1912", nextdate(2, 14, 1912));
  EXPECT_STREQ("11/15/1912", nextdate(11, 14, 1912));
  EXPECT_STREQ("12/15/1912", nextdate(12, 14, 1912));
  EXPECT_STREQ("6/2/1912", nextdate(6, 1, 1912));
  EXPECT_STREQ("6/3/1912", nextdate(6, 2, 1912));
  EXPECT_STREQ("6/30/1912", nextdate(6, 29, 1912));
  EXPECT_STREQ("7/1/1912", nextdate(6, 30, 1912));
  EXPECT_STREQ("6/15/1812", nextdate(6, 14, 1812));
  EXPECT_STREQ("6/15/1813", nextdate(6, 14, 1813));
  EXPECT_STREQ("6/15/2011", nextdate(6, 14, 2011));
  EXPECT_STREQ("6/15/2012", nextdate(6, 14, 2012));
}
// Robust
TEST(NextdateTest, EdgeR) {
  EXPECT_STREQ("month not in range", nextdate(0, 14, 1912));
  EXPECT_STREQ("1/15/1912", nextdate(1, 14, 1912));
  EXPECT_STREQ("2/15/1912", nextdate(2, 14, 1912));
  EXPECT_STREQ("11/15/1912", nextdate(11, 14, 1912));
  EXPECT_STREQ("12/15/1912", nextdate(12, 14, 1912));
  EXPECT_STREQ("month not in range", nextdate(13, 14, 1912));

  EXPECT_STREQ("day not in range", nextdate(6, 0, 1912));
  EXPECT_STREQ("6/2/1912", nextdate(6, 1, 1912));
  EXPECT_STREQ("6/3/1912", nextdate(6, 2, 1912));
  EXPECT_STREQ("6/30/1912", nextdate(6, 29, 1912));
  EXPECT_STREQ("7/1/1912", nextdate(6, 30, 1912));
  EXPECT_STREQ("Invalid input date", nextdate(6, 31, 1912));
  EXPECT_STREQ("day not in range", nextdate(6, 32, 1912));

  EXPECT_STREQ("year not in range", nextdate(6, 14, 1811));
  EXPECT_STREQ("6/15/1812", nextdate(6, 14, 1812));
  EXPECT_STREQ("6/15/1813", nextdate(6, 14, 1813));
  EXPECT_STREQ("6/15/2011", nextdate(6, 14, 2011));
  EXPECT_STREQ("6/15/2012", nextdate(6, 14, 2012));
  EXPECT_STREQ("year not in range", nextdate(6, 14, 2013));
}

// Decision Table Testing
TEST(NextdateTest, DecisionTable) {
  EXPECT_STREQ("4/16/2001", nextdate(4, 15, 2001));
  EXPECT_STREQ("5/1/2001", nextdate(4, 30, 2001));
  EXPECT_STREQ("Invalid input date", nextdate(4, 31, 2001));
  EXPECT_STREQ("1/16/2001", nextdate(1, 15, 2001));
  EXPECT_STREQ("2/1/2001", nextdate(1, 31, 2001));
  EXPECT_STREQ("12/16/2001", nextdate(12, 15, 2001));
  EXPECT_STREQ("1/1/2002", nextdate(12, 31, 2001));
  EXPECT_STREQ("2/16/2001", nextdate(2, 15, 2001));
  EXPECT_STREQ("2/29/2004", nextdate(2, 28, 2004));
  EXPECT_STREQ("3/1/2001", nextdate(2, 28, 2001));
  EXPECT_STREQ("3/1/2004", nextdate(2, 29, 2004));
  EXPECT_STREQ("Invalid input date", nextdate(2, 29, 2001));
  EXPECT_STREQ("Invalid input date", nextdate(2, 30, 2001));
}
