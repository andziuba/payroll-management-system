#pragma once
#include <iostream>

#include "Date.h"
#include "Employee.h"
#include "EmployeeManager.h"
#include "InputValidator.h"
#include "Menu.h"
#include "display.h"

class EditMenu : public Menu {
  EmployeeManager& employee_manager;

 public:
  EditMenu(EmployeeManager& emp_manager);
  int DisplayMenu() override;
  void ProcessChoice(int edit_menu_choice) override;
};
