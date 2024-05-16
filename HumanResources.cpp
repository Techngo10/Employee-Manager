#include "HumanResources.h"
#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

//Setting up all variables and making HR and employee which is a person
HumanResources::HumanResources()
    : Employee(), position("none"), no_trained(0), no_hired(0), no_fired(0), no_retired(0) {}
HumanResources::HumanResources(float salary_hourly, float hours_weekly, 
    string date_joined, int age, int phone, string name, string address, string position) 
    : Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), 
      position(position), no_trained(0), no_hired(0), no_fired(0), no_retired(0) {} 


// getters, setters and adders
std::string HumanResources::get_position() {return position;};
void HumanResources::set_position(std::string new_position) {position = new_position;};

int HumanResources::get_trained() {return no_trained;};
void HumanResources::add_trained(int trained) {no_trained += trained;};

int HumanResources::get_hired() {return no_hired;};
void HumanResources::add_hired(int hired) {no_hired += hired;};

int HumanResources::get_fired() {return no_fired;};
void HumanResources::add_fired(int fired) {no_fired += fired;};

int HumanResources::get_retired() {return no_retired;};
void HumanResources::add_retired(int retired) {no_retired += retired;};