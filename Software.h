#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "Employee.h"

class Software: public Employee{
    private:
        std::string positions;
        std::string languages;
        std::string projects_finished;
        std::string projects_current;

    public:
        //Initialisation
        Software();
        Software(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, std::string position);

        //Getters
        std::string get_position();
        std::string get_languages();
        std::string get_projects_current();
        std::string get_finished();
     
        //Setters
        void set_position(std::string position);
        void set_language(std::string languages);
        void set_finished(std::string projects_finished);
        void set_projects_current(std::string projects_current);

};

#endif //SOFTWARE_H