#ifndef MANUFACTURING_H
#define MANUFACTURING_H

#include "Employee.h"

class Manufacturing : public Employee {
    private:
        std::string position;
        std::string certification;
        int cars_complete;

    public:
        //Initialisation
        Manufacturing();
        Manufacturing(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, std::string position, std::string certification, int cars_complete);

        //Getters
        std::string get_position();
        std::string get_certification();
        int get_cars_complete();

        //Setters
        void set_position(std::string position);
        void set_certification(std::string certification);
        void set_cars_complete(int cars_complete);
};

#endif