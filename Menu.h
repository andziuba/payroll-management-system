#pragma once
#include <iostream>

class Menu {
 public:
  virtual int DisplayMenu() = 0;
  virtual void ProcessChoice(int choice) = 0;
};
