#ifndef RESEARCHDEV_H
#define RESEARCHDEV_H

#include "Employee.h"

class ResearchDev : public Employee {
    private:
        std::string position;
        std::string finished_research;
        std::string current_research;
        std::string expertise;

    public:
        //Initialisation
        ResearchDev();
        ResearchDev(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, 
        std::string position, std::string finished_research, std::string current_research, std::string expertise);

        //Getters
        std::string get_position();
        std::string get_finished();
        std::string get_research();
        std::string get_expertise();

        //Setters
        void set_position(std::string position);
        void set_finished(std::string finished_research);
        void set_research(std::string current_research);
        void set_expertise(std::string expertise);

};

#endif //RESEARCHDEV_H