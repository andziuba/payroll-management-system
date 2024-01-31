#pragma once
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

class Date {
  int day;
  int month;
  int year;

  static bool IsLeapYear(int year);
  static bool IsValidDate(int day, int month, int year);

 public:
  Date(int day, int month, int year);
  friend istream& operator>>(istream& input, Date& date);
  friend ostream& operator<<(ostream& output, const Date& date);
};
