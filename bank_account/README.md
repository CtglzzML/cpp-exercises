BankAccount Console Application (C++)

This project is a simple console-based banking application implemented in C++.
It demonstrates fundamental object-oriented programming concepts and basic error handling techniques using exceptions.

Overview

The application allows the user to interact with a bank account through a text-based menu. Users can:

Display the current account balance

Deposit money

Withdraw money

Exit the program

All operations are validated to ensure safe and correct behaviour.
Invalid operations (such as depositing negative amounts or withdrawing more than the available balance) are handled using std::runtime_error exceptions.

Key Concepts Demonstrated

Class design and encapsulation

Private data members

Public member functions

Input validation

Exception handling (try, throw, catch)

Basic loop-driven menu structure

Separation of concerns inside a class
