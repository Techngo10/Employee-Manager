#include "EmployeeManager.h"
 

#include <iostream>
#include <string>
using namespace std;

EmployeeManager::EmployeeManager();

void EmployeeManager::displayMenu() const {
    cout << "Welcome to the Employee Management System!" << endl;
    cout << "Type 'help' to see available commands." << endl;
};

void EmployeeManager::displayHelp() const {
     // Display available commands
    cout << "Available commands:" << endl;
    cout << "  - add: Add a new employee" << endl;
    cout << "  - remove: Remove an employee" << endl;
    cout << "  - list: List all employees" << endl;
    cout << "  - salary <employee_id>: Check salary of an employee" << endl;
    cout << "  - quit: Exit the program" << endl;

};


void EmployeeManager::loadFromFile(const string& filename);
void EmployeeManager::saveToFile(const string& filename) const;