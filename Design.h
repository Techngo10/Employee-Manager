#ifndef DESIGN_H
#define DESIGN_H

#include "Employee.h"

class Design : public Employee {
    private:
        std::string position;
        std::string design_finished;
        std::string design_current;

    public:
        //Initialisation
        Design();
        Design(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, 
        std::string position, std::string design_finished, std::string design_current);

        //Getters
        std::string get_position();
        std::string get_finished();
        std::string get_design_current();

        //Setters
        void set_position(std::string position);
        void set_finished(std::string design_finished);
        void set_design_current(std::string design_current);
};

#endif