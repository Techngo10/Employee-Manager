#include "Manufacturing.h"
#include "Employee.h"
#include <iostream>
#include <string.h>

Manufacturing::Manufacturing() : position("none"), certification("none"), cars_complete(0) {};
Manufacturing::Manufacturing(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string position, string certification, int cars_complete)
: Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position(position), certification(certification), cars_complete(cars_complete) {}

string Manufacturing::get_position(){return position;};
void Manufacturing::set_position(string position){this->position = position;};

string Manufacturing::get_certification(){return certification;};
void Manufacturing::add_certification(string certification){this->certification = certification;};

int Manufacturing::get_cars_complete(){return cars_complete;};
void Manufacturing::add_cars_complete(int cars_complete){this->cars_complete = cars_complete;};