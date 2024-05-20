#include "Design.h"
#include "Employee.h"

//Initialisation
Design::Design() : Employee(), position("none"), design_finished(""), design_current("none") {}
Design::Design(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, std::string position, std::string design_finished, std::string design_current) 
: Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position(position), design_finished(design_finished), design_current(design_current) {}

//Getters
std::string Design::get_position(){return position;};
std::string Design::get_finished(){return design_finished;};
std::string Design::get_design_current(){return design_current;};

//Setters
void Design::set_position(std::string position){this->position = position;};
void Design::set_finished(std::string design_finished){this->design_finished = design_finished;};
void Design::set_design_current(std::string design_current){this->design_current = design_current;};