#ifndef SALARY_H
#define SALARY_H

#include <iostream>
#include <string.h>

class Salary {
    public:
        virtual ~Salary() = default;
        virtual float calculateSalary() const = 0;

};

#endif 