# Payroll-Management-System using C++

The project has multiple classes and sub-classes with some features within them. Basic operations users can perform via this program project which has such functions: adding new employee record, modifying employee record and deleting record, displaying one or all employee’s record. Besides these, payroll management also allows users to print the salary slip for a particular employee.

## Project Operations:
### Addition of New Employee:
The information handled in this feature are employee code number, name, address, phone number, joining date (day, month and year), designation and grade.
### Modify Employee Record:
This System in C++ asks for employee code from the user for this function to work. Modifications that can be made are joining date (day, month and year), name, address, phone number, designation and grade. Employee’s grades are categorized as A, B, C, D and E.
### Delete Employee Record:
Deletion is done of an employee record from Payroll Management System by entering the employee code.
### Print Employee Salary Slip:
This feature too asks for the employee code; the employee code has been used to unlock or perform operations in many features of this Payroll Management System project in C++. The slip enlists basic information about employee, grade bonus, nasic salary and net salary.
### Display Employee Record:
Providing the employee code number, users can access all the provided information related to a particular employee via this function. The employee record information displayed are the ones provided while adding a new employee record.
### Display List of Employees:
This feature displays the record of all added employees.

## OOP Priniples:
### Ensapsulation
Encapsulation involves the use of access modifiers within classes to control the visibility of their members.
Example: In the `Employee` class, access modifiers are added to regulate the accessibility of various properties and methods. Additionally, the class makes use of getters and setters to encapsulate the internal state, allowing controlled access to class properties.
### Abstraction
Abstraction is achieved through the use of classes, allowing the hiding of implementation details while exposing only essential features.
Example: The `Date` class abstracts away the implementation of date manipulation. Users interact with a simplified interface, shielding them from the complexities of the underlying implementation.
### Inheritance
Inheritance is employed to establish a relationship between classes, enabling the creation of specialized versions based on a common base class.
Example: `MainMenu` and `EditMenu` classes inherit from the abstract base class `Menu`. Inheritance is used to create a specialized version of the base `Menu` class, allowing the derived classes to provide their own implementations of the abstract methods `DisplayMenu` and `ProcessChoice`.
### Polymorphism
Polymorphism allows objects of different types to be treated as objects of a common base type. It enables the use of a single interface to represent and work with various derived types.
Example: The base class `InputValidator` declares a common interface through the pure virtual function `IsValid`. Derived classes `NumericValidator`, `AllowedValuesValidator` and `NonEmptyValidator` implement this function according to their specific validation criteria.
