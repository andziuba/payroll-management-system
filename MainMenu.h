#pragma once
#include <iostream>

#include "EmployeeManager.h"
#include "Menu.h"

class MainMenu : public Menu {
  EmployeeManager& employee_manager;

 public:
  MainMenu(EmployeeManager& emp_manager);
  int DisplayMenu() override;
  void ProcessChoice(int main_menu_choice) override;
};
