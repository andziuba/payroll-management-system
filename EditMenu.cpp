#include "EditMenu.h"

EditMenu::EditMenu(EmployeeManager& emp_manager)
    : employee_manager(emp_manager) {}

int EditMenu::DisplayMenu() {
  int edit_menu_choice;

  cout << "Modify employee record" << endl;
  cout << "Please select which infomation do you want to change by entering "
          "the corresponding number:"
       << endl;
  cout << "1 - first name" << endl;
  cout << "2 - last name" << endl;
  cout << "3 - address" << endl;
  cout << "4 - phone number" << endl;
  cout << "5 - designation" << endl;
  cout << "6 - grade" << endl;
  cout << endl << "7 - return to main menu" << endl;

  cout << endl << "Enter your choice: ";
  cin >> edit_menu_choice;

  return edit_menu_choice;
}

void EditMenu::ProcessChoice(int edit_menu_choice) {
  string new_code, new_first_name, new_last_name, new_address, new_phone_number,
      new_designation, new_grade;

  // Get the validators
  const NonEmptyValidator& non_empty = employee_manager.getNonEmptyValidator();
  const NumericValidator& numeric = employee_manager.getNumericValidator();
  const AllowedValuesValidator& allowed_designations =
      employee_manager.getAllowedDesignationsValidator();
  const AllowedValuesValidator& allowed_grades =
      employee_manager.getAllowedGradesValidator();

  // Get the code of the employee to modify and check if it exists
  cout << "Choose which employee you want to modify by entering their code\n\n";
  string entered_code = employee_manager.AskForCode();
  ClearScreen();

  if (entered_code == "-1") {
    cout << "Employee with entered code doesn't exists" << endl;
    this_thread::sleep_for(chrono::seconds(1));
    return;
  }

  Employee employee_to_modify =
      employee_manager.GetEmployeeByCode(entered_code);

  // Clear input buffer
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  switch (edit_menu_choice) {
    case 1:
      new_first_name =
          employee_manager.GetValidInput("\nEnter new First Name: ", non_empty);
      employee_to_modify.SetFirstName(new_first_name);
      break;
    case 2:
      new_last_name =
          employee_manager.GetValidInput("\nEnter new Last Name: ", non_empty);
      employee_to_modify.SetFirstName(new_last_name);
      break;
    case 3:
      new_address =
          employee_manager.GetValidInput("\nEnter new Address: ", non_empty);
      employee_to_modify.SetAddress(new_address);
      break;
    case 4:
      new_phone_number =
          employee_manager.GetValidInput("\nEnter new Phone Number: ", numeric);
      employee_to_modify.SetPhoneNumber(new_phone_number);
      break;
    case 5:
      new_designation = employee_manager.GetValidInput(
          "\nEnter new Designation: ", allowed_designations);
      employee_to_modify.SetDesignation(new_designation);
      break;
    case 6:
      new_grade =
          employee_manager.GetValidInput("\nEnter new Grade: ", allowed_grades);
      employee_to_modify.SetGrade(new_grade);
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
  }

  employee_manager.ModifyEmployeeInSystem(employee_to_modify);
  ClearScreen();
  cout << "Modified!" << endl;
  this_thread::sleep_for(chrono::seconds(1));
}
