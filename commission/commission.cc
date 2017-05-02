#include "commission.h"
#include <stdio.h>
#include <stdlib.h>

// Returns commission.
double commission(int locks, int stocks, int barrels) {
  if (locks == -1) {
    fprintf(stderr, "Program terminates");
    exit(0);
  }

  int locks_out_range = (locks < 1 || locks > 70);
  int stocks_out_range = (stocks < 1 || stocks > 80);
  int barrels_out_range = (barrels < 1 || barrels > 90);

  if (locks_out_range && !stocks_out_range && !barrels_out_range) {
    fprintf(stderr, "Value of locks not in the range");
    exit(1);
  } else if (!locks_out_range && stocks_out_range && !barrels_out_range) {
    fprintf(stderr, "Value of stocks not in the range");
    exit(1);
  } else if (!locks_out_range && !stocks_out_range && barrels_out_range) {
    fprintf(stderr, "Value of barrels not in the range");
    exit(1);
  } else if (locks_out_range && stocks_out_range && !barrels_out_range) {
    fprintf(stderr, "Value of locks and stocks not in the range");
    exit(1);
  } else if (locks_out_range && !stocks_out_range && barrels_out_range) {
    fprintf(stderr, "Value of locks and barrels not in the range");
    exit(1);
  } else if (!locks_out_range && stocks_out_range && barrels_out_range) {
    fprintf(stderr, "Value of stocks and barrels not in the range");
    exit(1);
  } else if (locks_out_range && stocks_out_range && barrels_out_range) {
    fprintf(stderr, "Value of locks and stocks and barrels not in the range");
    exit(1);
  }

  double sales = locks * 45.0 + stocks * 30.0 + barrels * 25.0;
  double commission;
  if (sales > 1800.0) {
    commission = 0.10 * 1000.0;
    commission = commission + 0.15 * 800.0;
    commission = commission + 0.2 * (sales - 1800.0);
  } else if (sales > 1000.0) {
    commission = 0.10 * 1000.0;
    commission = commission + 0.15 * (sales - 1000.0);
  } else
    commission = 0.10 * sales;

  return commission;
}
