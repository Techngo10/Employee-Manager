#include "Sales.h"

//Initialisation
Sales::Sales() : position("none"), conversion_rate(0), cars_sold(0), revenue(0) {}
Sales::Sales(float salary_hourly, float hours_weekly, std::string date_joined, int age, int phone, std::string name, std::string address, std::string position, float conversion_rate, int cars_sold, float revenue)
: Employee(salary_hourly, hours_weekly, date_joined, age, phone, name, address), position(position), conversion_rate(conversion_rate), cars_sold(cars_sold), revenue(revenue) {}

//Getters
std::string Sales::get_position(){return position;};
float Sales::get_conversion_rate(){return conversion_rate;};
int Sales::get_cars_sold(){return cars_sold;};
float Sales::get_revenue(){return revenue;};

//Setters
void Sales::set_position(std::string position){this->position = position;};
void Sales::set_conversion_rate(float conversion_rate){this->conversion_rate = conversion_rate;};
void Sales::set_cars_sold(int cars_sold){this->cars_sold = cars_sold;};
void Sales::set_revenue(float revenue){this->revenue = revenue;};