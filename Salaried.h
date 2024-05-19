#ifndef SALARIED_H
#define SALARIED_H

#include "Salary.h"
#include <string>

class Salaried : public Salary {
private:
    std::string employeeName;
    float annualSalary;

public:
    // Constructors
    Salaried(const std::string& name, float salary);
    Salaried();  // Default constructor

    // Override the pure virtual function
    float calculateSalary() const override;

    // Additional member functions
    std::string getEmployeeName() const;
    float getAnnualSalary() const;
};

#endif // SALARIED_H
