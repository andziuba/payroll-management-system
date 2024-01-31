#pragma once
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Base class for input validation
class InputValidator {
 public:
  // Pure virtual function implemented by derived classes
  virtual bool IsValid(const string& input) const = 0;

  // Virtual destructor for derived classes
  virtual ~InputValidator() {}
};

class NumericValidator : public InputValidator {
 public:
  bool IsValid(const string& input) const override;
};

class AllowedValuesValidator : public InputValidator {
 private:
  const vector<string>& allowed_values;

 public:
  AllowedValuesValidator(const vector<string>& allowed_values);
  bool IsValid(const string& input) const override;
};

class NonEmptyValidator : public InputValidator {
 public:
  bool IsValid(const string& input) const override;
};
