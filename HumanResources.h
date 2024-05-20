#ifndef HUMANRESOURCES_H
#define HUMANRESOURCES_H

#include "Employee.h"

class HumanResources : public Employee {
    private:
        std::string position;
        int no_trained;
        int no_hired;
        int no_fired;
        int no_retired;

    public:
        //Initialisation
        HumanResources();
        HumanResources(float salary_hourly, float hours_weekly, 
            std::string date_joined, int age, int phone, std::string name, std::string address, std::string position);

        //Getters
        std::string get_position();
        int get_trained();
        int get_hired();
        int get_fired();
        int get_retired();

        //Setters
        void set_position(std::string position);
        void set_trained(int no_trained);
        void set_hired(int no_hired);
        void set_fired(int no_fired);
        void set_retired(int no_retired);
};

#endif