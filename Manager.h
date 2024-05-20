#ifndef MANAGER_H
#define MANAGER_H 

#include "Employee.h"

class Manager : public Employee {
    private:
        std::string password; 
        std::string position;

    public:
        //Initialisation
        Manager();
        Manager(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address,
            std::string password, std::string position);

        //Getters
        std::string get_password();
        std::string get_position();

        //Setters 
        void set_password(std::string password);
        void set_position(std::string position);
};

#endif
