#include "HumanResources.h"

//Initalisation
HumanResources::HumanResources()
    : Employee(), position("none"), no_trained(0), no_hired(0), no_fired(0), no_retired(0) {}
HumanResources::HumanResources(float salary_hourly, float hours_weekly, 
    std::string date_joined, int age, int phone, std::string name, std::string address, std::string position) 
    : Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), 
      position(position), no_trained(0), no_hired(0), no_fired(0), no_retired(0) {} 


//Getters
std::string HumanResources::get_position() {return position;};
int HumanResources::get_trained() {return no_trained;};
int HumanResources::get_hired() {return no_hired;};
int HumanResources::get_fired() {return no_fired;};
int HumanResources::get_retired() {return no_retired;};

//Setters
void HumanResources::set_position(std::string position) {this->position = position;};
void HumanResources::set_trained(int no_trained) {this->no_trained = no_trained;};
void HumanResources::set_hired(int no_hired) {this->no_hired = no_hired;};
void HumanResources::set_fired(int no_fired) {this->no_fired = no_fired;};
void HumanResources::set_retired(int no_retired) {this->no_retired = no_retired;};