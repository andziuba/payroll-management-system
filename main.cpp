#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <string>
#include <thread>
#include <vector>

#include "EditMenu.h"
#include "MainMenu.h"
#include "display.h"
using namespace std;

void StartProgram(MainMenu& main_menu, EditMenu& edit_menu) {
  int allowed_choices_main[] = {1, 2, 3, 4, 5, 6, 7};
  int allowed_choices_edit[] = {1, 2, 3, 4, 5, 6, 7};
  int main_menu_choice = 0;
  int edit_menu_choice = 0;

  while (true) {
    main_menu_choice = main_menu.DisplayMenu();

    // Check if main menu choice is allowed
    if (find(begin(allowed_choices_main), end(allowed_choices_main),
             main_menu_choice) != end(allowed_choices_main)) {
      ClearScreen();

      // Close the program
      if (main_menu_choice == 7) {
        break;

        // Display edit menu
      } else if (main_menu_choice == 2) {
        while (true) {
          edit_menu_choice = edit_menu.DisplayMenu();

          // Check if edit menu choice is allowed
          if (find(begin(allowed_choices_edit), end(allowed_choices_edit),
                   edit_menu_choice) != end(allowed_choices_edit)) {
            ClearScreen();

            // Close the edit menu
            if (edit_menu_choice == 7) {
              ClearScreen();
              break;
            }

            // Process edit menu choices
            else {
              edit_menu.ProcessChoice(edit_menu_choice);
              ClearScreen();
            }

          } else {
            cout << "Invalid choice. Please try again." << endl;
            this_thread::sleep_for(chrono::seconds(1));
            ClearScreen();
          }
        }

        // Process other main menu choices
      } else {
        main_menu.ProcessChoice(main_menu_choice);
        ClearScreen();
      }

    } else {
      cout << "Invalid choice. Please try again." << endl;
      this_thread::sleep_for(chrono::seconds(1));
      ClearScreen();
    }
  }
}

int main() {
  // Create instances of classes
  EmployeeManager employee_manager;
  MainMenu main_menu(employee_manager);
  EditMenu edit_menu(employee_manager);

  ClearScreen();
  StartProgram(main_menu, edit_menu);

  return 0;
}
