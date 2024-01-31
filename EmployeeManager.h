#pragma once
#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#include "Employee.h"
#include "InputValidator.h"
#include "display.h"
using namespace std;

class EmployeeManager {
  vector<Employee> employees;

  // Initialize validators
  NonEmptyValidator non_empty_validator;

  NumericValidator numeric_validator;

  vector<string> allowed_designations = {"manager", "engineer", "trainee"};
  AllowedValuesValidator allowed_designations_validator =
      AllowedValuesValidator(allowed_designations);

  vector<string> allowed_grades = {"A", "B", "C", "D", "E"};
  AllowedValuesValidator allowed_grades_validator =
      AllowedValuesValidator(allowed_grades);

  unordered_map<string, double> base_salaries = {
      {"manager", 10000}, {"engineer", 5000}, {"trainee", 3000}};
  unordered_map<string, double> grade_bonuses = {
      {"A", 0.2}, {"B", 0.15}, {"C", 0.1}, {"D", 0.05}, {"E", 0.0}};
  double net_salary_ratio = 0.8;

  void PrintEmployee(Employee current_employee);

 public:
  EmployeeManager();

  string AskForCode();

  Employee GetEmployeeByCode(string code);

  bool CheckIfCodeExists(string code);

  string GetValidInput(const string& prompt, const InputValidator& validator);

  void AddNewEmployee();

  void DeleteEmployee();

  void PrintEmployeeSalarySlip();

  void DisplayEmployeeRecord();

  void DisplayAllEmployees();

  void ModifyEmployeeInSystem(Employee modified_employee);

  // Getters for validators
  const NonEmptyValidator& getNonEmptyValidator() const {
    return non_empty_validator;
  }

  const NumericValidator& getNumericValidator() const {
    return numeric_validator;
  }

  const AllowedValuesValidator& getAllowedDesignationsValidator() const {
    return allowed_designations_validator;
  }

  const AllowedValuesValidator& getAllowedGradesValidator() const {
    return allowed_grades_validator;
  }
};
