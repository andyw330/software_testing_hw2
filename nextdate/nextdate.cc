#include "nextdate.h"
#include <stdio.h>

char date[16];

// Returns next date;
const char* nextdate(int month, int day, int year) {
  int month_out_range = (month < 1 || month > 12);
  int day_out_range = (day < 1 || day > 31);
  int year_out_range = (year < 1812 || year > 2012);

  if (month_out_range && !day_out_range && !year_out_range)
    return "month not in range";
  else if (!month_out_range && day_out_range && !year_out_range)
    return "day not in range";
  else if (!month_out_range && !day_out_range && year_out_range)
    return "year not in range";
  else if (month_out_range && day_out_range && !year_out_range)
    return "month and day not in range";
  else if (month_out_range && !day_out_range && year_out_range)
    return "month and year not in range";
  else if (!month_out_range && day_out_range && year_out_range)
    return "day and year not in range";
  else if (month_out_range && day_out_range && year_out_range)
    return "month and day and year not in range";

  int tomorrowMonth = month;
  int tomorrowDay = day;
  int tomorrowYear = year;

  if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10) {
    if (day < 31)
      tomorrowDay = day + 1;
    else if (day == 31) {
      tomorrowDay = 1;
      tomorrowMonth = month + 1;
    } else
      return "Invalid input date";
  } else if (month == 4 || month == 6 || month == 9 || month == 11) {
    if (day < 30)
      tomorrowDay = day + 1;
    else if (day == 30) {
      tomorrowDay = 1;
      tomorrowMonth = month + 1;
    } else
      return "Invalid input date";
  } else if (month == 12) {
    if (day < 31)
      tomorrowDay = day + 1;
    else {
      tomorrowDay = 1;
      tomorrowMonth = 1;
      tomorrowYear = year + 1;
    }
  } else if (month == 2) {
    if (day < 28)
      tomorrowDay = day + 1;
    else if (day == 28) {
      if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // is leap year
        tomorrowDay = 29;
      else {
        tomorrowDay = 1;
        tomorrowMonth = 3;
      }
    } else if (day == 29) {
      if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) { // is leap year
        tomorrowDay = 1;
        tomorrowMonth = 3;
      } else
        return "Invalid input date";
    } else
      return "Invalid input date";
  }

  sprintf(date, "%d/%d/%d", tomorrowMonth, tomorrowDay, tomorrowYear);
  return date;
}
