#pragma once
#include <iostream>
#include <string>

#include "Date.h"
using namespace std;

class Employee {
  string code;
  string first_name;
  string last_name;
  string address;
  string phone_number;
  Date joining_date;
  string designation;
  string grade;

 public:
  Employee(string code, string first_name, string last_name, string address,
           string phone_number, const Date& joining_date, string designation,
           string grade);

  void SetCode(string code);
  void SetFirstName(string first_name);
  void SetLastName(string last_name);
  void SetAddress(string address);
  void SetPhoneNumber(string phone_number);
  void SetJoiningDate(const Date& joining_date);
  void SetDesignation(string designation);
  void SetGrade(string grade);

  string GetCode();
  string GetFirstName();
  string GetLastName();
  string GetAddress();
  string GetPhoneNumber();
  Date GetJoiningDate();
  string GetDesignation();
  string GetGrade();

  double CalculateBasicSalary(double base_salary, double grade_bonus);
  double CalculateNetSalary(double basic_salary, double net_salary_ratio);
};
