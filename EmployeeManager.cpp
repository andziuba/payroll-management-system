#include "EmployeeManager.h"

EmployeeManager::EmployeeManager() {}

// Ask for employee's code and check if it exists
string EmployeeManager::AskForCode() {
  string entered_code;

  cout << "Enter employee's code: " << endl;
  cin >> entered_code;

  for (auto& current_employee : employees) {
    if (current_employee.GetCode() == entered_code) {
      return entered_code;
    }
  }

  return "-1";
}

bool EmployeeManager::CheckIfCodeExists(string code) {
  for (auto& current_employee : employees) {
    if (current_employee.GetCode() == code) {
      return true;
    }
  }
  return false;
}

Employee EmployeeManager::GetEmployeeByCode(string code) {
  for (auto& current_employee : employees) {
    if (current_employee.GetCode() == code) {
      return current_employee;
    }
  }

  return Employee("", "", "", "", "", Date(0, 0, 0), "", "");
}

string EmployeeManager::GetValidInput(const string& prompt,
                                      const InputValidator& validator) {
  string input;

  do {
    cout << prompt;
    getline(cin, input);

    // Use the validator to check the input
    if (validator.IsValid(input)) {
      break;
    } else {
      cout << "Invalid input." << endl;
    }
  } while (true);

  return input;
}

void EmployeeManager::PrintEmployee(Employee current_employee) {
  cout << "Code: " << current_employee.GetCode() << endl;
  cout << "First Name: " << current_employee.GetFirstName() << endl;
  cout << "Last Name: " << current_employee.GetLastName() << endl;
  cout << "Address: " << current_employee.GetAddress() << endl;
  cout << "Phone Number: " << current_employee.GetPhoneNumber() << endl;
  cout << "Joining Date: " << current_employee.GetJoiningDate() << endl;
  cout << "Designation: " << current_employee.GetDesignation() << endl;
  cout << "Grade: " << current_employee.GetGrade() << endl;
  cout << endl;
}

void EmployeeManager::AddNewEmployee() {
  // Clear initial input buffer
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // Enter code until it's unique
  string code;
  code = GetValidInput("\nEnter Employee Code: ", non_empty_validator);
  while (CheckIfCodeExists(code)) {
    cout << "This code is assigned to a different employee." << endl;
    code = GetValidInput(
        "\nEnter Employee Code (code must be unique and can't be modified): ",
        non_empty_validator);
  }

  // Enter other employee details and validate them
  string first_name =
      GetValidInput("\nEnter First Name: ", non_empty_validator);

  string last_name = GetValidInput("\nEnter Last Name: ", non_empty_validator);

  string address = GetValidInput("\nEnter Address: ", non_empty_validator);

  string phone_number =
      GetValidInput("\nEnter Phone Number: ", numeric_validator);

  Date joining_date(0, 0, 0);
  cin >> joining_date;

  string designation =
      GetValidInput("\nEnter Designation (manager, engineer, trainee): ",
                    allowed_designations_validator);
  string grade = GetValidInput("\nEnter Grade (A, B, C, D, E): ",
                               allowed_grades_validator);

  Employee newEmployee(code, first_name, last_name, address, phone_number,
                       joining_date, designation, grade);
  employees.push_back(newEmployee);

  ClearScreen();
  cout << "Added!" << endl;
  this_thread::sleep_for(chrono::seconds(1));
  ClearScreen();
};

void EmployeeManager::DeleteEmployee() {
  string entered_code = AskForCode();

  ClearScreen();
  if (entered_code == "-1") {
    cout << "Employee with entered code doesn't exists" << endl;
  } else {
    employees.erase(std::remove_if(employees.begin(), employees.end(),
                                   [&](Employee& employee) {
                                     return employee.GetCode() == entered_code;
                                   }),
                    employees.end());

    cout << "Deleted!" << endl;
  }

  this_thread::sleep_for(chrono::seconds(1));
  ClearScreen();
};

void EmployeeManager::PrintEmployeeSalarySlip() {
  string entered_code = AskForCode();
  ClearScreen();

  if (entered_code == "-1") {
    cout << "Employee with entered code doesn't exists" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    return;
  }

  Employee selected_employee = GetEmployeeByCode(entered_code);

  // Get employee's info needed to calculate salary
  double base_salary = base_salaries[selected_employee.GetDesignation()];
  double grade_bonus = grade_bonuses[selected_employee.GetGrade()];

  // Calculate salaries
  double basic_salary =
      selected_employee.CalculateBasicSalary(base_salary, grade_bonus);
  double net_salary =
      selected_employee.CalculateNetSalary(basic_salary, net_salary_ratio);

  // Print salary slip
  cout << "Employee Salary Slip" << endl;
  cout << "Code: " << selected_employee.GetCode() << endl;
  cout << "Name: " << selected_employee.GetFirstName() << " "
       << selected_employee.GetLastName() << endl;
  cout << "Designation: " << selected_employee.GetDesignation() << endl;
  cout << "Grade bonus: " << grade_bonus * 100 << "%" << endl;
  cout << "Basic Salary: " << basic_salary << endl;
  cout << "Net Salary: " << net_salary << endl;

  ReturnToMainMenu();
};

void EmployeeManager::DisplayEmployeeRecord() {
  string entered_code = AskForCode();

  ClearScreen();
  if (entered_code == "-1") {
    cout << "Employee with entered code doesn't exists" << endl;
  } else {
    Employee selected_employee = GetEmployeeByCode(entered_code);
    cout << "Employee Record" << endl;
    PrintEmployee(selected_employee);
  }

  ReturnToMainMenu();
};

void EmployeeManager::DisplayAllEmployees() {
  if (employees.empty()) {
    cout << "No employees to display." << endl;
  }

  for (auto& current_employee : employees) {
    PrintEmployee(current_employee);
  }

  ReturnToMainMenu();
};

void EmployeeManager::ModifyEmployeeInSystem(Employee modified_employee) {
  for (auto& current_employee : employees) {
    if (current_employee.GetCode() == modified_employee.GetCode()) {
      current_employee = modified_employee;
      break;
    }
  }
};
