#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <iostream>
#include <string.h>

#include "Employee.h"
 

using namespace std;

class Software: public Employee{
    private:
        string Positions;
        string Languages;
        string projects_finished;
        string projects_current;

    public:
        Software();
        Software(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string position);
    
        string get_position();
        string get_languages();
        string get_projects_current();
        string get_finished();
     

        void set_position(string position);
        void set_language(string languages);
        void set_finished(string finished);
        void set_projects_current(string currentProjects);

};

#endif