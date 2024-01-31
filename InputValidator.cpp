#include "InputValidator.h"

bool NumericValidator::IsValid(const string& input) const {
  return input.find_first_not_of("0123456789") == string::npos;
}

// Constructor to initialize the allowed values
AllowedValuesValidator::AllowedValuesValidator(
    const vector<string>& allowed_values)
    : allowed_values(allowed_values) {}

bool AllowedValuesValidator::IsValid(const string& input) const {
  return find(allowed_values.begin(), allowed_values.end(), input) !=
         allowed_values.end();
}

bool NonEmptyValidator::IsValid(const string& input) const {
  return !input.empty() && input.find_first_not_of(' ') != string::npos;
}
