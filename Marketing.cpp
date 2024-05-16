#include "Marketing.h"
#include <iostream>
#include <string.h>
using namespace std;

Marketing::Marketing() : position("none"), success_rate(0) {}
Marketing::Marketing(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string new_position, float success)    
: Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position("none"), success_rate(0) {}

string Marketing::get_position(){return position;};
void Marketing::set_position(string new_position){
    position = new_position;

};

float Marketing::get_success_rate(){return success_rate;};
void Marketing::set_success_rate(float success){
    success_rate = success;

};