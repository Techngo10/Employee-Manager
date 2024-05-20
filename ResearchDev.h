#ifndef RESEARCHDEV_H
#define RESEARCHDEV_H

#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

class ResearchDev : public Employee {
    private:
        string position;
        string finished_research;
        string current_research;
        string expertise;

    public:
        ResearchDev();
        ResearchDev(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, 
        string new_position, string finished, string current, string expert);

        string get_position();
        void set_position(string new_position);

        string get_finished();
        void set_finished(string finished);

        string get_research();
        void set_research(string current);

        string get_expertise();
        void set_expertise(string expert);

};

#endif