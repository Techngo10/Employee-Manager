#ifndef DESIGN_H
#define DESIGN_H

#include "Employee.h"
#include <iostream>
#include <string.h>
using namespace std;

class Design : public Employee {
    private:
        string position;
        string design_finished;
        string design_current;

    public:
        Design();
        Design(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, 
        string position, string design_finished, string design_current);

        string get_position();
        void set_position(string position);

        string get_finished();
        void set_finished(string design_finished);

        string get_design_current();
        void set_design_current(string design_current);

};

#endif