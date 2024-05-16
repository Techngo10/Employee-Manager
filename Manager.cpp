#include "Manager.h"
#include <iostream>
#include <string.h>

Manager::Manager() : Employee(), password("none"), position("none") {};
Manager::Manager(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string pass, string pos)
    : Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), password(pass), position(pos) {}

string Manager::get_password(){return password;};
void Manager::set_password(string pass){password = pass;};

string Manager::get_position(){return position;};
void Manager::set_position(string pos){position = pos;};
