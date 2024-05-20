#include "Manager.h"

//Initialisation
Manager::Manager() : Employee(), password("none"), position("none") {};
Manager::Manager(float salary_hourly, float hours_weekly, string date_joined, int age, int phone, string name, string address, string password, string position)
    : Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), password(password), position(position) {}

//Getters
string Manager::get_password(){return password;};
string Manager::get_position(){return position;};

//Setters
void Manager::set_password(string password){this->password = password;};
void Manager::set_position(string position){this->position = position;};
