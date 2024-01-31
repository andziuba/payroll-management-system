#include "MainMenu.h"

MainMenu::MainMenu(EmployeeManager& emp_manager)
    : employee_manager(emp_manager) {}

int MainMenu::DisplayMenu() {
  int main_menu_choice;

  cout << "Payroll Management System" << endl;
  cout << "Please select an action by entering the corresponding number:"
       << endl;
  cout << "1 - Add a new employee" << endl;
  cout << "2 - Modify employee record" << endl;
  cout << "3 - Delete employee record" << endl;
  cout << "4 - Print employee salary slip" << endl;
  cout << "5 - Dispaly employee record" << endl;
  cout << "6 - Display list of employees" << endl;
  cout << "7 - Exit" << endl;

  cout << endl << "Enter your choice: ";
  cin >> main_menu_choice;

  return main_menu_choice;
}

void MainMenu::ProcessChoice(int main_menu_choice) {
  switch (main_menu_choice) {
    case 1:
      employee_manager.AddNewEmployee();
      break;
    case 3:
      employee_manager.DeleteEmployee();
      break;
    case 4:
      employee_manager.PrintEmployeeSalarySlip();
      break;
    case 5:
      employee_manager.DisplayEmployeeRecord();
      break;
    case 6:
      employee_manager.DisplayAllEmployees();
      break;
  }
}
