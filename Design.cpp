#include "Design.h"
#include "Employee.h"

#include <iostream>
#include <string.h>
using namespace std;

Design::Design() : Employee(), position("none"), amount_design_finished(0), design_current("none") {}
Design::Design(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string position, int amount_design_finished, int design_current) 
: Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position("none"), amount_design_finished(0), design_current("none") {}

string Design::get_position(){return position;};
void Design::set_position(string position){this->position = position;};

int Design::get_finished(){return amount_design_finished;};
void Design::add_finished(int amount_design_finished){this->amount_design_finished += amount_design_finished;};

string Design::get_design_current(){return design_current;};
void Design::set_design_current(string design_current){this->design_current = design_current;};