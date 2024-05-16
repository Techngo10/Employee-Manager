#ifndef MARKETING_H
#define MARKETING_H

#include "Employee.h"
#include <iostream>
#include <string.h>
using namespace std;

class Marketing : public Employee {
    private:
        string position;
        float success_rate;

    public:
        Marketing();
        Marketing(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string new_position, float success);

        string get_position();
        void set_position(string new_position);

        float get_success_rate();
        void set_success_rate(float success);

};

#endif //MARKETING_H
