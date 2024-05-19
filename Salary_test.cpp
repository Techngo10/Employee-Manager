#include <iostream>
#include "Salaried.h"

int main() {
    Salaried salariedEmployee("John Doe", 60000.0f);

    std::cout << "Employee Name: " << salariedEmployee.getEmployeeName() << std::endl;
    std::cout << "Annual Salary: " << salariedEmployee.getAnnualSalary() << std::endl;
    std::cout << "Monthly Salary: " << salariedEmployee.calculateSalary() << std::endl;

    return 0;
}
