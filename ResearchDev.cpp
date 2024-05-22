#include "ResearchDev.h"

//Initialisation
ResearchDev::ResearchDev() : position("none"), finished_research("none"), current_research("none"), expertise("none") {}
ResearchDev::ResearchDev(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, 
    std::string position, std::string finished_research, std::string current_research, std::string expertise)
    : Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position(position), finished_research(finished_research), 
    current_research(current_research), expertise(expertise) {}

//Getters
std::string ResearchDev::get_position(){return position;};
std::string ResearchDev::get_finished(){return finished_research;};
std::string ResearchDev::get_research(){return current_research;};
std::string ResearchDev::get_expertise(){return expertise;};

//Setters
void ResearchDev::set_position(std::string position){this->position = position;};
void ResearchDev::set_finished(std::string finished_research){this->finished_research = finished_research;};
void ResearchDev::set_research(std::string current_research){this->current_research = current_research;};
void ResearchDev::set_expertise(std::string expertise){this->expertise = expertise;};