#ifndef MARKETING_H
#define MARKETING_H

#include "Employee.h"

class Marketing : public Employee {
    private:
        std::string position;
        float success_rate;

    public:
        //Initialisation
        Marketing();
        Marketing(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, std::string position, float success_rate);

        //Getters
        std::string get_position();
        float get_success_rate();

        //Setters
        void set_position(std::string position);
        void set_success_rate(float success_rate);
};

#endif //MARKETING_H
