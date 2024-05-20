#include "Marketing.h"

//Initialisation
Marketing::Marketing() : position("none"), success_rate(0) {}
Marketing::Marketing(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, std::string position, float success_rate)    
: Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position(position), success_rate(success_rate) {}

//Getters
std::string Marketing::get_position(){return position;};
float Marketing::get_success_rate(){return success_rate;};

//Setters
void Marketing::set_position(std::string position) {this->position = position;};
void Marketing::set_success_rate(float success_rate) {this->success_rate = success_rate;};