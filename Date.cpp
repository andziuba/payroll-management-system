#include "Date.h"

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

bool Date::IsLeapYear(int year) {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool Date::IsValidDate(int day, int month, int year) {
  if (year < 0 || month < 1 || month > 12 || day < 1) {
    return false;
  }

  int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  // Adjust February days for leap years
  if (month == 2 && Date::IsLeapYear(year)) {
    days_in_month[2] = 29;
  }

  return day <= days_in_month[month];
}

istream& operator>>(istream& input, Date& date) {
  string input_line;

  do {
    cout << endl << "Enter Joining Date (format: day/month/year): ";

    getline(input, input_line);

    // Create a stringstream from the input line
    stringstream ss(input_line);

    // Check if date was entered in the correct format
    if (ss >> date.day && ss.get() == '/' && ss >> date.month &&
        ss.get() == '/' && ss >> date.year && ss.eof()) {
      // Validate the date
      if (Date::IsValidDate(date.day, date.month, date.year)) {
        break;
      }
    }

    cout << "Invalid date" << endl;
  } while (true);

  return input;
}

ostream& operator<<(ostream& output, const Date& date) {
  output << date.day << "/" << date.month << "/" << date.year;
  return output;
}
