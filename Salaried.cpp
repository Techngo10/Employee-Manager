#include "Salaried.h"

// Default constructor
Salaried::Salaried() : employeeName(""), annualSalary(0.00) {}

// Parameterized constructor
Salaried::Salaried(const std::string& name, float salary)
    : employeeName(name), annualSalary(salary) {}

// Implement the pure virtual function
float Salaried::calculateSalary() const {
    return annualSalary / 12; // Assuming monthly salary calculation
}

// Getter for employee name
std::string Salaried::getEmployeeName() const {
    return employeeName;
}

// Getter for annual salary
float Salaried::getAnnualSalary() const {
    return annualSalary;
}
