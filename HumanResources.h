#ifndef HUMANRESOURCES_H
#define HUMANRESOURCES_H

#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

class HumanResources: public Employee {
    private:
        std::string position;
        int no_trained;
        int no_hired;
        int no_fired;
        int no_retired;

    public:
        HumanResources();
        HumanResources(string position, int ID, float salary_hourly, float hours_weekly, 
            string date_joined, int age, int phone, string name, string address);

        std::string get_position();
        void set_position(std::string new_position);

        int get_trained();
        void add_trained(int trained);

        int get_hired();
        void add_hired(int hired);

        int get_fired();
        void add_fired(int fired);

        int get_retired();
        void add_retired(int retired);

};

#endif