#include "display.h"

void ClearScreen() { system("cls"); }

void ReturnToMainMenu() {
  cout << endl << "Press Enter to return to the Main Menu ";

  cin.ignore();  // Ignore the previous newline character
  cin.get();     // Wait for the user to press Enter
}
