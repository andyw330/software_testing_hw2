#include "commission.h"
#include "gtest/gtest.h"

// Tests commission().

/* === Specification-based Testing === */

// Standard
TEST(CommissionTest, StdBoundary) {
  EXPECT_DOUBLE_EQ(10, commission(1, 1, 1));
  EXPECT_DOUBLE_EQ(12.5, commission(1, 1, 2));
  EXPECT_DOUBLE_EQ(13, commission(1, 2, 1));
  EXPECT_DOUBLE_EQ(14.5, commission(2, 1, 1));
  EXPECT_DOUBLE_EQ(50, commission(5, 5, 5));
  EXPECT_DOUBLE_EQ(97.5, commission(10, 10, 9));
  EXPECT_DOUBLE_EQ(97, commission(10, 9, 10));
  EXPECT_DOUBLE_EQ(95.5, commission(9, 10, 10));
  EXPECT_DOUBLE_EQ(100, commission(10, 10, 10));
  EXPECT_DOUBLE_EQ(103.75, commission(10, 10, 11));
  EXPECT_DOUBLE_EQ(104.5, commission(10, 11, 10));
  EXPECT_DOUBLE_EQ(106.75, commission(11, 10, 10));
  EXPECT_DOUBLE_EQ(160, commission(14, 14, 14));
  EXPECT_DOUBLE_EQ(216.25, commission(18, 18, 17));
  EXPECT_DOUBLE_EQ(215.5, commission(18, 17, 18));
  EXPECT_DOUBLE_EQ(213.25, commission(17, 18, 18));
  EXPECT_DOUBLE_EQ(220, commission(18, 18, 18));
  EXPECT_DOUBLE_EQ(225, commission(18, 18, 19));
  EXPECT_DOUBLE_EQ(226, commission(18, 19, 18));
  EXPECT_DOUBLE_EQ(229, commission(19, 18, 18));
  EXPECT_DOUBLE_EQ(820, commission(48, 48, 48));
  EXPECT_DOUBLE_EQ(1415, commission(70, 80, 89));
  EXPECT_DOUBLE_EQ(1414, commission(70, 79, 90));
  EXPECT_DOUBLE_EQ(1411, commission(69, 80, 90));
  EXPECT_DOUBLE_EQ(1420, commission(70, 80, 90));
}
// Special Value (Sales Boundary)
TEST(CommissionTest, SpecialBoundary) {
  EXPECT_DOUBLE_EQ(100.75, commission(10, 11, 9)); // sales = 1005
  EXPECT_DOUBLE_EQ(219.25, commission(18, 17, 19)); // sales = 1795
  EXPECT_DOUBLE_EQ(221, commission(18, 19, 17)); // sales = 1805
}

// Equivalence Class Testing
// L1= {locks: 1 ≤ locks ≤ 70}
// L2= {locks = –1} (occurs if locks = –1 is used to control input iteration)
// S1 = {stocks: 1 ≤ stocks ≤ 80}
// B1= {barrels: 1 ≤ barrels ≤ 90}
// Weak Robust
TEST(CommissionTest, EquivalenceWR) {
  EXPECT_DOUBLE_EQ(100, commission(10, 10, 10));
  EXPECT_EXIT(commission(-1, 40, 45), ::testing::ExitedWithCode(0), "Program terminates");
  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(71, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_EXIT(commission(35, 81, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_EXIT(commission(35, 40, -1), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_EXIT(commission(35, 40, 91), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
}
// Strong Robust
TEST(CommissionTest, EquivalenceSR) {
  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_EXIT(commission(35, 40, -2), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");
  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");
  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");
}

// Edge Testing
// Robust
TEST(CommissionTest, EdgeR) {
  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(-1, 40, 45), ::testing::ExitedWithCode(0), "Program terminates");
  EXPECT_EXIT(commission(0, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_DOUBLE_EQ(334, commission(1, 40, 45));
  EXPECT_DOUBLE_EQ(946, commission(69, 40, 45));
  EXPECT_DOUBLE_EQ(955, commission(70, 40, 45));
  EXPECT_EXIT(commission(71, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");

  EXPECT_EXIT(commission(35, 0, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_DOUBLE_EQ(406, commission(35, 1, 45));
  EXPECT_DOUBLE_EQ(412, commission(35, 2, 45));
  EXPECT_DOUBLE_EQ(874, commission(35, 79, 45));
  EXPECT_DOUBLE_EQ(880, commission(35, 80, 45));
  EXPECT_EXIT(commission(35, 81, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");

  EXPECT_EXIT(commission(35, 40, 0), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_DOUBLE_EQ(420, commission(35, 40, 1));
  EXPECT_DOUBLE_EQ(425, commission(35, 40, 2));
  EXPECT_DOUBLE_EQ(860, commission(35, 40, 89));
  EXPECT_DOUBLE_EQ(865, commission(35, 40, 90));
  EXPECT_EXIT(commission(35, 40, 91), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
}

// Decision Table Testing
// Generate same cases of Equivalence Class Testing
TEST(CommissionTest, DecisionTable) {
  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(-1, 40, 45), ::testing::ExitedWithCode(0), "Program terminates");
  EXPECT_EXIT(commission(0, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_DOUBLE_EQ(334, commission(1, 40, 45));
  EXPECT_DOUBLE_EQ(946, commission(69, 40, 45));
  EXPECT_DOUBLE_EQ(955, commission(70, 40, 45));
  EXPECT_EXIT(commission(71, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");

  EXPECT_EXIT(commission(35, 0, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_DOUBLE_EQ(406, commission(35, 1, 45));
  EXPECT_DOUBLE_EQ(412, commission(35, 2, 45));
  EXPECT_DOUBLE_EQ(874, commission(35, 79, 45));
  EXPECT_DOUBLE_EQ(880, commission(35, 80, 45));
  EXPECT_EXIT(commission(35, 81, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");

  EXPECT_EXIT(commission(35, 40, 0), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_DOUBLE_EQ(420, commission(35, 40, 1));
  EXPECT_DOUBLE_EQ(425, commission(35, 40, 2));
  EXPECT_DOUBLE_EQ(860, commission(35, 40, 89));
  EXPECT_DOUBLE_EQ(865, commission(35, 40, 90));
  EXPECT_EXIT(commission(35, 40, 91), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
}


/* === Code-based Testing - Path Testing === */

// C0: Statement coverage
TEST(CommissionTest, CodeCoverageC0) {
  EXPECT_EXIT(commission(-1, 40, 45), ::testing::ExitedWithCode(0), "Program terminates");
  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_EXIT(commission(35, 40, -2), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");
  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");
  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");
  EXPECT_DOUBLE_EQ(221, commission(18, 19, 17)); // sales = 1805
  EXPECT_DOUBLE_EQ(100.75, commission(10, 11, 9)); // sales = 1005
  EXPECT_DOUBLE_EQ(10, commission(1, 1, 1));
}

// C1: DD-path coverage
TEST(CommissionTest, CodeCoverageC1) {
  EXPECT_EXIT(commission(-1, 40, 45), ::testing::ExitedWithCode(0), "Program terminates");
  EXPECT_DOUBLE_EQ(10, commission(1, 1, 1));

  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");

  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_EXIT(commission(35, 40, -2), ::testing::ExitedWithCode(1), "Value of barrels not in the range");

  EXPECT_EXIT(commission(35, 40, -2), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");

  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");
  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");

  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");
  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");

  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");

  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");
  EXPECT_DOUBLE_EQ(221, commission(18, 19, 17));

  EXPECT_DOUBLE_EQ(221, commission(18, 19, 17)); // sales = 1805
  EXPECT_DOUBLE_EQ(100.75, commission(10, 11, 9)); // sales = 1005

  EXPECT_DOUBLE_EQ(100.75, commission(10, 11, 9)); // sales = 1005
  EXPECT_DOUBLE_EQ(10, commission(1, 1, 1));
}

// C2: DD-path coverage + Simple loop coverage
TEST(CommissionTest, CodeCoverageC2) {

  // no loop => same as C1

  EXPECT_EXIT(commission(-1, 40, 45), ::testing::ExitedWithCode(0), "Program terminates");
  EXPECT_DOUBLE_EQ(10, commission(1, 1, 1));

  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");

  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_EXIT(commission(35, 40, -2), ::testing::ExitedWithCode(1), "Value of barrels not in the range");

  EXPECT_EXIT(commission(35, 40, -2), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");

  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");
  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");

  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");
  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");

  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");

  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");
  EXPECT_DOUBLE_EQ(221, commission(18, 19, 17));

  EXPECT_DOUBLE_EQ(221, commission(18, 19, 17)); // sales = 1805
  EXPECT_DOUBLE_EQ(100.75, commission(10, 11, 9)); // sales = 1005

  EXPECT_DOUBLE_EQ(100.75, commission(10, 11, 9)); // sales = 1005
  EXPECT_DOUBLE_EQ(10, commission(1, 1, 1));

}

// MCDC: Modified condition/decision coverage
TEST(CommissionTest, CodeCoverageMCDC) {
  EXPECT_EXIT(commission(-1, 40, 45), ::testing::ExitedWithCode(0), "Program terminates");
  EXPECT_DOUBLE_EQ(334, commission(1, 40, 45));

  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_DOUBLE_EQ(334, commission(1, 40, 45));
  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");
  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");

  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");
  EXPECT_DOUBLE_EQ(406, commission(35, 1, 45));
  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");

  EXPECT_EXIT(commission(35, 40, -1), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");
  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");
  EXPECT_DOUBLE_EQ(420, commission(35, 40, 1));

  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");
  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");
  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");
  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");

  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");
  EXPECT_EXIT(commission(35, 40, -1), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");
  EXPECT_EXIT(commission(-2, 40, 45), ::testing::ExitedWithCode(1), "Value of locks not in the range");

  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");
  EXPECT_EXIT(commission(35, 40, -1), ::testing::ExitedWithCode(1), "Value of barrels not in the range");
  EXPECT_EXIT(commission(35, -1, 45), ::testing::ExitedWithCode(1), "Value of stocks not in the range");

  EXPECT_EXIT(commission(-2, -1, -1), ::testing::ExitedWithCode(1), "Value of locks and stocks and barrels not in the range");
  EXPECT_EXIT(commission(35, -1, -1), ::testing::ExitedWithCode(1), "Value of stocks and barrels not in the range");
  EXPECT_EXIT(commission(-2, 40, -1), ::testing::ExitedWithCode(1), "Value of locks and barrels not in the range");
  EXPECT_EXIT(commission(-2, -1, 45), ::testing::ExitedWithCode(1), "Value of locks and stocks not in the range");

  EXPECT_DOUBLE_EQ(224, commission(18, 17, 20)); // sales = 1820
  EXPECT_DOUBLE_EQ(216.25, commission(17, 17, 20)); // sales = 1775
  EXPECT_DOUBLE_EQ(218.5, commission(18, 16, 20)); // sales = 1790
  EXPECT_DOUBLE_EQ(219.25, commission(18, 17, 19)); // sales = 1795

  EXPECT_DOUBLE_EQ(100.75, commission(10, 11, 9)); // sales = 1005
  EXPECT_DOUBLE_EQ(96, commission(9, 11, 9)); // sales = 960
  EXPECT_DOUBLE_EQ(97.5, commission(10, 10, 9)); // sales = 975
  EXPECT_DOUBLE_EQ(98, commission(10, 11, 8)); // sales = 980

}