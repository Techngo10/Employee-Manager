#include "Design.h"
#include "Employee.h"

#include <iostream>
#include <string.h>
using namespace std;

Design::Design() : Employee(), position("none"), design_finished(""), design_current("none") {}
Design::Design(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string position, string design_finished, string design_current) 
: Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position(position), design_finished(design_finished), design_current(design_current) {}

string Design::get_position(){return position;};
void Design::set_position(string position){this->position = position;};

string Design::get_finished(){return design_finished;};
void Design::set_finished(string design_finished){this->design_finished = design_finished;};
string Design::get_design_current(){return design_current;};
void Design::set_design_current(string design_current){this->design_current = design_current;};