#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <vector>
#include "Employee.h"
#include "Manager.h"
#include "HumanResources.h"
#include "Location.h"
// Include other headers as needed

class EmployeeManager {
    private:

    public:
        EmployeeManager();
        ~EmployeeManager();

        void displayMenu() const;
        void displayHelp() const;
        void listings() const;
        void loadFromFile(const std::string& filename);
        void saveToFile(const std::string& filename) const;
};

#endif // EMPLOYEEMANAGER_H
