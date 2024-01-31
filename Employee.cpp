#include "Employee.h"

Employee::Employee(string code, string first_name, string last_name,
                   string address, string phone_number,
                   const Date& joining_date, string designation, string grade)
    : code(code),
      first_name(first_name),
      last_name(last_name),
      address(address),
      phone_number(phone_number),
      designation(designation),
      grade(grade),
      joining_date(joining_date) {}

// Setters

void Employee::SetCode(string code) { this->code = code; }

void Employee::SetFirstName(string first_name) {
  this->first_name = first_name;
}

void Employee::SetLastName(string last_name) { this->last_name = last_name; }

void Employee::SetAddress(string address) { this->address = address; }

void Employee::SetPhoneNumber(string phone_number) {
  this->phone_number = phone_number;
}

void Employee::SetJoiningDate(const Date& joining_date) {
  this->joining_date = joining_date;
}

void Employee::SetDesignation(string designation) {
  this->designation = designation;
}

void Employee::SetGrade(string grade) { this->grade = grade; }

// Getters

string Employee::GetCode() { return code; }

string Employee::GetFirstName() { return first_name; }

string Employee::GetLastName() { return last_name; }

string Employee::GetAddress() { return address; }

string Employee::GetPhoneNumber() { return phone_number; }

Date Employee::GetJoiningDate() { return joining_date; }

string Employee::GetDesignation() { return designation; }

string Employee::GetGrade() { return grade; }

// Calculate salary

double Employee::CalculateBasicSalary(double base_salary, double grade_bonus) {
  return base_salary + (base_salary * grade_bonus);
}

double Employee::CalculateNetSalary(double basic_salary,
                                    double net_salary_ratio) {
  return basic_salary * net_salary_ratio;
}
